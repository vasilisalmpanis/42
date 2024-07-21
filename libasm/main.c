#include "ft_libasm.h"

int main(void)
{
//	char *buff = malloc(100);
//	char *buff2 = malloc(100);
//	char *str = "";
//	if (!buff) {
//		printf("error\n");
//		return 1;
//	}
//	bzero(buff, 99);
//	bzero(buff2, 99);
//	buff = strcpy(buff, str);
//	buff2 = strcpy(buff2, str);
//	printf("1 original: %s\n", buff);
//	printf("2 mine    : %s\n", buff2);
//	
//	/* TESTS FOR STRCMP */
//	char *cmp = "123";
//	int test1 = ft_strcmp(cmp, "124");
//	int test2 = strcmp(cmp, "124");
//	printf("original: %d, ft_strcmp: %d \n", test2, test1);
//
//	/* TEST FOR WRITE */
//	int error = ft_write(-1, buff2, 5);
//	perror(buff2);
//	printf("error %s\n", buff2);
//
//	char *new_buff = NULL;
//	new_buff = ft_strdup("Hello world");
//	if (new_buff)
//		printf("%s\n", new_buff);
//	else
//		printf("error allocating\n");
	int a = ft_strlen(NULL);
	printf("%d\n", a);
	a = ft_atoi_base("1", "1");
	printf("%d\n", a);
}
