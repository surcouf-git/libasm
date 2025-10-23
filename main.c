#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *s);

char *ft_strcpy(char *restrict dst, const char *restrict src);

extern int ft_strcmp(const char *s1, const char *s2);

extern ssize_t ft_read(int fd, void *buf, size_t count);

// extern char *ft_strdup(const char *s1);

// extern ssize_t ft_write(int fd, const void *buf, size_t count);

void print_line() {
	for (int i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}

void	read_call(void) {
	char buf[1024] = {};

	print_line();

	printf("testing read with invalid fd:\n\n");
	errno = 0;
	int rd = read(-1, buf, 1023);
	printf("read: %d (errno = %d)\n", rd, errno);
	errno = 0;
	int ft_rd = ft_read(-1, buf, 1023);
	printf("ft_read: %d (errno = %d)\n\n-----\n\n", ft_rd, errno);

	errno = 0;
	int file_fd = open("./read_file.txt", O_RDONLY);
	if (file_fd > 0) {
		printf("testing read with valid fd:\n\n");
		int rd = read(file_fd, buf, 1023);
		printf("read: %d (errno = %d) content -> [%s]\n", rd, errno, buf);
		errno = 0;
		lseek(file_fd, 0, SEEK_SET);
		memset(buf, 0, 1024);
		int ft_rd = ft_read(file_fd, buf, 1023);
		printf("ft_read: %d (errno = %d) content -> [%s]\n", ft_rd, errno, buf);
		close(file_fd);
	} else
		printf ("Cannot exec test 2 -> open file for read (%s)", strerror(errno));

	printf("\n\n-----\n\ntesting read with stdin:\n\n");
	errno = 0;
	memset(buf, 0, 1024);
	printf("->");
	fflush(stdout);
	rd = read(0, buf, 1023);
	printf("\nread: %d (errno = %d) content -> [%s]\n", rd, errno, buf);
	errno = 0;
	printf("->");
	fflush(stdout);
	memset(buf, 0, 1024);
	ft_rd = ft_read(0, buf, 1023);
	printf("\nft_read: %d (errno = %d) content -> [%s]\n", ft_rd, errno, buf);
	printf("\n\n");
}

void	strlen_call(void) {
	char *nul_buf = NULL;
	char empty_buf[10] = {};
	char buf[10] = "hello !]\n";
	
	// printf("testing strlen with null buf (should segfault):\n\n");
	
	// errno = 0;
	// int rlen = strlen(nul_buf);
	// printf("\nstrlen: %d (errno = %d) content -> [%s]\n", rlen, errno, nul_buf);    // all this should segfault
	// errno = 0;
	// int ft_rlen = ft_strlen(nul_buf);
	// printf("\nft_strlen: %d (errno = %d) content -> [%s]\n", ft_rlen, errno, nul_buf);
	// printf("\n\n-----\n\n");
	
	printf("testing strlen whith empty buffer\n\n");
	errno = 0;
	int rlen = strlen(empty_buf);
	printf("\nstrlen: %d (errno = %d) content -> [%s]\n", rlen, errno, empty_buf);
	errno = 0;
	int ft_rlen = ft_strlen(empty_buf);
	printf("\nft_strlen: %d (errno = %d) content -> [%s]\n", ft_rlen, errno, empty_buf);
	
	printf("\n\n-----\n\n");
	printf("testing strlen whith normal buffer buffer\n\n");
	errno = 0;
	rlen = strlen(buf);
	printf("\nstrlen: %d (errno = %d) content -> [%s\n", rlen, errno, buf);
	errno = 0;
	ft_rlen = ft_strlen(buf);
	printf("\nft_strlen: %d (errno = %d) content -> [%s\n", ft_rlen, errno, buf);
	print_line();
}

void strcpy_call(void) {
	char *nul_buf = NULL, *ptr = NULL;
	char empty_buf[1024] = {};
	char buf[10] = "hello !]\n";
	

	printf("testing strcpy with null buf as both params:\n\n");

	ptr = strcpy(nul_buf, nul_buf);
	printf("strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr);
	ptr = NULL;
	ptr = ft_strcpy(nul_buf, nul_buf);
	printf("ft_strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr);

	printf("\n\n-----\n\n");

	// printf("testing strcpy with null buf as first param:\n\n");
	// ptr = strcpy(nul_buf, empty_buf);
	// printf("strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr); // should segfault
	// ptr = NULL;
	// ptr = ft_strcpy(nul_buf, empty_buf);
	// printf("ft_strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr);

	printf("testing strcpy with null buf as second param:\n\n");
	memset(empty_buf, 0, 1024);
	ptr = strcpy(empty_buf, nul_buf);
	printf("strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr);  // should segfault ?????????
	ptr = NULL;
	memset(empty_buf, 0, 1024);
	ptr = ft_strcpy(empty_buf, nul_buf);
	printf("ft_strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr);

	printf("testing strcpy with normal params:\n\n");
	memset(empty_buf, 0, 1024);
	ptr = strcpy(empty_buf, buf);
	printf("strcpy: ptr = [%p] | content = [%s\n", ptr, ptr);
	ptr = NULL;
	memset(empty_buf, 0, 1024);
	ptr = ft_strcpy(empty_buf, buf);
	printf("ft_strcpy: ptr = [%p] | content = [%s\n", ptr, ptr);

	print_line();
}

void strcmp_call(void) {
	char *nul_buf = NULL;
	char empty_buf[10] = {};
	char buf1[20] = "hello";
	char buf2[20] = "hello";
	char buf3[20] = "world";
	int rcmp = 0;
	int ft_rcmp = 0;

	print_line();

	printf("testing strcmp with null buf as both params:\n\n");
	rcmp = strcmp(nul_buf, nul_buf);
	printf("strcmp: %d\n", rcmp);
	ft_rcmp = ft_strcmp(nul_buf, nul_buf);
	printf("ft_strcmp: %d\n", ft_rcmp);

	printf("\n\n-----\n\n");

	// printf("testing strcmp with null buf as first param:\n\n");
	// rcmp = strcmp(nul_buf, buf1); // should segfault
	// printf("strcmp: %d\n", rcmp);
	// ft_rcmp = ft_strcmp(nul_buf, buf1);
	// printf("ft_strcmp: %d\n", ft_rcmp);

	// printf("\n\n-----\n\n");

	printf("testing strcmp with null buf as second param:\n\n");
	// rcmp = strcmp(buf1, nul_buf); // should segfault
	// printf("strcmp: %d\n", rcmp);
	ft_rcmp = ft_strcmp(buf1, nul_buf);
	printf("ft_strcmp: %d\n", ft_rcmp);

	printf("testing strcmp with empty strings:\n\n");
	errno = 0;
	rcmp = strcmp(empty_buf, empty_buf);
	printf("strcmp: %d (errno = %d)\n", rcmp, errno);
	errno = 0;
	ft_rcmp = ft_strcmp(empty_buf, empty_buf);
	printf("ft_strcmp: %d (errno = %d)\n", ft_rcmp, errno);

	printf("\n\n-----\n\n");

	printf("testing strcmp with equal strings:\n\n");
	errno = 0;
	rcmp = strcmp(buf1, buf2);
	printf("strcmp: %d (errno = %d)\n", rcmp, errno);
	errno = 0;
	ft_rcmp = ft_strcmp(buf1, buf2);
	printf("ft_strcmp: %d (errno = %d)\n", ft_rcmp, errno);

	printf("\n\n-----\n\n");

	printf("testing strcmp with different strings:\n\n");
	errno = 0;
	rcmp = strcmp(buf1, buf3);
	printf("strcmp: %d (errno = %d)\n", rcmp, errno);
	errno = 0;
	ft_rcmp = ft_strcmp(buf1, buf3);
	printf("ft_strcmp: %d (errno = %d)\n", ft_rcmp, errno);

	print_line();
}

int main () {
	// char src[] = "Salut ca vA", dst[] = "Salut ca va";

	strlen_call();
	strcpy_call();
	strcmp_call();
	read_call();
	return (0);
}