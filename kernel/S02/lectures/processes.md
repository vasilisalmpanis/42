# Processes

A process is an operating system abstraction that groups together multiple resources:

* An address space
* One or more threads
* Opened files
* Sockets
* Semaphores
* Shared memory regions
* Timers
* Signal handlers
* Many other resources and status information

In linux all this information is stored in task_struct.

Every driver can access the current task_struct by using the macro ***current***.

The first task that starts when the kernel boots is called **init_task** and it is a static  
variable creates in `init/init_task.c`

quiz:
```gdb
# find first the struct
# and save fd_array in a variable
# you can also save the maxfds in a variable.
while ($i<32)
 >if ($fd_array[$i] != 0)
  >p $fd_array[$i].f_path->dentry->d_name
  >end
 >set $i = $i + 1
 >end
```

### Clone


both fork and pthread_create use clone underneath. The folling flags can be passed.
* **CLONE_FILES** - shares the file descriptor table with the parent
* **CLONE_VM** - shares the address space with the parent
* **CLONE_FS** - shares the filesystem information (root directory, current directory) with the parent
* **CLONE_NEWNS** - does not share the mount namespace with the parent
* **CLONE_NEWIPC** - does not share the IPC namespace (System V IPC objects, POSIX message queues) with the parent
* **CLONE_NEWNET** - does not share the networking namespaces (network interfaces, routing table) with the parent

The flags can be combined by bitwise **OR**:

    CLONE_NEWNET | CLONE_FILES

#### Namespaces

the allow the segregation of different parts of the kernel.  
examples are docker containers. The processes inside cannot see the ones outside  
To achieve this partitioning, the struct nsproxy structure is used to group types of resources  
that we want to partition. It currently supports IPC, networking, cgroup, mount, networking, PID, time namespaces

[struct nsproxy](https://elixir.bootlin.com/linux/v6.15.2/source/include/linux/nsproxy.h#L32)

nsproxy is a member of task struct and holds pointers to all namespaces.
the same instance is shared by multiple tasks and is duplicated upon unsharing.

## QUIZ:
- What is the size of struct thread_info?
- Which of the following are potential valid sizes for struct thread_info: 4095, 4096, 4097?

    answer the size is 4096.

# Kthreads

sometimes drivers need to run in process context. This is why we have kthreads. they don't access userspace and they
don't access files.
