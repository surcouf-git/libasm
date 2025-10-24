#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "libasm.h"

void print_line() {
	for (int i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}

void	read_call(void) {
	char buf[1024] = {};

	printf("testing read with invalid fd:\n\n");
	errno = 0;
	int rd = read(-1, buf, 1023);
	printf("read: %d (errno = %d)\n", rd, errno);
	errno = 0;
	int ft_rd = ft_read(-1, buf, 1023);
	printf("ft_read: %d (errno = %d)\n\n-----\n\n", ft_rd, errno);

	errno = 0;
	int file_fd = open("./files/read_file.txt", O_RDONLY);
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

	print_line();
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

	// printf("testing strcpy with null buf as second param:\n\n");
	// memset(empty_buf, 0, 1024);
	// ptr = strcpy(empty_buf, nul_buf);
	// printf("strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr);
	// ptr = NULL;
	// memset(empty_buf, 0, 1024);
	// ptr = ft_strcpy(empty_buf, nul_buf);
	// printf("ft_strcpy: ptr = [%p] | content = [%s]\n", ptr, ptr);

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

	// printf("testing strcmp with null buf as second param:\n\n");
	// rcmp = strcmp(buf1, nul_buf); // should segfault
	// printf("strcmp: %d\n", rcmp);
	// ft_rcmp = ft_strcmp(buf1, nul_buf);
	// printf("ft_strcmp: %d\n", ft_rcmp);

	printf("testing strcmp with empty strings:\n\n");
	rcmp = strcmp(empty_buf, empty_buf);
	printf("strcmp: %d\n", rcmp);
	ft_rcmp = ft_strcmp(empty_buf, empty_buf);
	printf("ft_strcmp: %d\n", ft_rcmp);
	printf("\n\n-----\n\n");

	printf("testing strcmp with equal strings:\n\n");
	rcmp = strcmp(buf1, buf2);
	printf("strcmp: %d\n", rcmp);
	ft_rcmp = ft_strcmp(buf1, buf2);
	printf("ft_strcmp: %d\n", ft_rcmp);
	printf("\n\n-----\n\n");

	printf("testing strcmp with different strings:\n\n");
	rcmp = strcmp(buf1, buf3);
	printf("strcmp: %d\n", rcmp);
	ft_rcmp = ft_strcmp(buf1, buf3);
	printf("ft_strcmp: %d\n", ft_rcmp);

	print_line();
}

void	write_call(void) {
	char buf[1024] = "Hello from write test\n";
	int wr, ft_wr;

	printf("testing write with invalid fd:\n\n");
	errno = 0;
	wr = write(-1, buf, strlen(buf));
	printf("write: %d (errno = %d)\n", wr, errno);
	errno = 0;
	ft_wr = ft_write(-1, buf, strlen(buf));
	printf("ft_write: %d (errno = %d)\n\n-----\n\n", ft_wr, errno);

	printf("testing write with valid fd (stdout):\n\n");
	errno = 0;
	wr = write(1, buf, strlen(buf));
	printf("write: %d (errno = %d)\n", wr, errno);
	errno = 0;
	ft_wr = ft_write(1, buf, strlen(buf));
	printf("ft_write: %d (errno = %d)\n\n-----\n\n", ft_wr, errno);

	printf("testing write with file:\n\n");
	errno = 0;
	int file_fd = open("./files/write_file.txt", O_WRONLY);
	if (file_fd > 0) {
		wr = write(file_fd, buf, strlen(buf));
		printf("write: %d (errno = %d)\n", wr, errno);
		errno = 0;
		ft_wr = ft_write(file_fd, buf, strlen(buf));
		printf("ft_write: %d (errno = %d)\n", ft_wr, errno);
		close(file_fd);
	} else
		printf("Cannot exec test 3 -> open file for write (%s)\n", strerror(errno));

	printf("\n\n-----\n\ntesting write with zero-length:\n\n");
	errno = 0;
	wr = write(1, "", 0);
	printf("write: %d (errno = %d)\n", wr, errno);
	errno = 0;
	ft_wr = ft_write(1, "", 0);
	printf("ft_write: %d (errno = %d)\n", ft_wr, errno);
	printf("\n\n");

	print_line();
}

void	strdup_call(void) {
	char *s = "Hello from strdup test";
	char *dup;
	char *ft_dup;

	printf("testing strdup with valid string:\n\n");
	errno = 0;
	dup = strdup(s);
	printf("strdup: [%s] (errno = %d)\n", dup, errno);
	free(dup);
	errno = 0;
	ft_dup = ft_strdup(s);
	printf("ft_strdup: [%s] (errno = %d)\n\n-----\n\n", ft_dup, errno);
	free(ft_dup);

	printf("testing strdup with empty string:\n\n");
	errno = 0;
	ft_dup = ft_strdup("");
	printf("ft_strdup: [%s] (errno = %d)\n\n-----\n\n", ft_dup, errno);
	free(ft_dup);
	errno = 0;
	dup = strdup("");
	printf("strdup: [%s] (errno = %d)\n", dup, errno);
	free(dup);

	// printf("testing strdup with NULL pointer (should segfault):\n\n");
	// errno = 0;
	// dup = NULL;
	// dup = strdup(dup);
	// printf("strdup: %p (errno = %d)\n\n", dup, errno); //should segfault
	// errno = 0;
	// ft_dup = NULL;
	// ft_dup = ft_strdup(ft_dup);
	// printf("ft_strdup: %p (errno = %d)\n\n", ft_dup, errno);
	// free(ft_dup);
}

int main () {
	strlen_call();
	strcpy_call();
	strcmp_call();
	write_call();
	read_call();
	strdup_call();
	return (0);
}