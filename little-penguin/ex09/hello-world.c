// SPDX-License-Identifier: GPL-2.0
#include <linux/seq_file.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/mount.h>
#include <linux/proc_fs.h>
#include <linux/namei.h>
#include <linux/slab.h>
#include <linux/pid_namespace.h>
#include <linux/mnt_namespace.h>
#include <uapi/linux/mount.h>
#include <linux/nsproxy.h>
#include <linux/module.h>
#include "/usr/src/linux-next/fs/mount.h"
#include <linux/rbtree.h>

#define PROC_NAME "mymounts"

static void show_mount(struct seq_file *m, struct mount *mnt)
{
	struct path path;
	char *buf;
	char *path_str;

	path.mnt = &mnt->mnt;
	path.dentry = mnt->mnt.mnt_root;

	buf = kmalloc(GFP_KERNEL, PAGE_SIZE);
	if (!buf)
		return;

	path_str = d_path(&path, buf, PAGE_SIZE);
	if (!strcmp(mnt->mnt_devname, "/dev/root")) {
		kfree(buf);
		return;
	}
	seq_printf(m, "%s %s\n", mnt->mnt_devname, path_str);
	kfree(buf);
}

static void traverse_mnt_tree(struct seq_file *m, struct rb_root *node)
{
	struct rb_node *temp;
	struct mount *mnt;

	for (temp = rb_first(node); temp; temp = rb_next(temp)) {
		mnt = rb_entry(temp, struct mount, mnt_node);
		show_mount(m, mnt);
	}
}

static int mymounts_show(struct seq_file *m, void *v)
{
	struct mnt_namespace *ns = current->nsproxy->mnt_ns;

	if (!ns)
		return -EFAULT;
	traverse_mnt_tree(m, &ns->mounts);

	return 0;
}

static int mymounts_open(struct inode *inode, struct file *file)
{
	return single_open(file, mymounts_show, NULL);
}

static const struct proc_ops proc_file_fops = {
	.proc_open = mymounts_open,
	.proc_read = seq_read,
	.proc_lseek = seq_lseek,
	.proc_release = single_release,
};

static int __init mymounts_init(void)
{
	proc_create(PROC_NAME, 0, NULL, &proc_file_fops);
	pr_info("/proc/%s created\n", PROC_NAME);
	return 0;
}

static void __exit mymounts_exit(void)
{
	remove_proc_entry(PROC_NAME, NULL);
	pr_info("/proc/%s removed\n", PROC_NAME);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Valmpani");
MODULE_DESCRIPTION("A module to list mount points");
MODULE_VERSION("0.1");

module_init(mymounts_init);
module_exit(mymounts_exit);
