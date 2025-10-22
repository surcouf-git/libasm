#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// #include "libasm.h"

// extern int ft_strcmp(const char *s1, const char *s2);

extern ssize_t ft_read(int fd, void *buf, size_t count);

// extern char *ft_strdup(const char *s1);

// extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main () {
	// char src[] = "Salut ca vA", dst[] = "Salut ca va";
	char buf[1000];
	// char *ptr = ft_strdup(src);

	// printf("[%s]<-\n", ptr);
	// return (0);
	errno = 0;
	int result = ft_read(-1, buf, 999);
	printf("%d | %d\n", result, errno);
	return (0);
}