#include <stdio.h>
#include <unistd.h>
#include <string.h>

// #include "libasm.h"

// extern int ft_strcmp(const char *s1, const char *s2);

extern ssize_t ft_write(int fd, const void *buf, size_t count);

int main () {
	char src[] = "Salut ca vA", dst[] = "Salut ca va";

	printf("[%ld]<-\n", ft_write(1, src, strlen(src)));
	return (0);
}