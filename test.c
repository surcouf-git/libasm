#include <stdio.h>
#include <unistd.h>
#include <string.h>

// #include "libasm.h"

// extern int ft_strcmp(const char *s1, const char *s2);

extern ssize_t ft_read(int fd, void *buf, size_t count);

// char *strdup(const char *s1)

// extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main () {
	char src[] = "Salut ca vA", dst[] = "Salut ca va";
	char buf[1000];

	printf("[%ld]<-\n", ft_read(0, buf, 999));
	return (0);
}