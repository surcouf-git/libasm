#include <stdio.h>
#include "struct.h"
#include <stdlib.h>

void print_line() {
	for (int i = 0; i < 50; i++) {
		printf("-");
	}
	printf("\n");
}

void free_all(t_list *ptr) {
	t_list *actual = NULL;
	while (ptr) {
		actual = ptr->next;
		free(ptr);
		ptr = actual;
	}
}

void print_list(t_list *head) {
	t_list *ptr = head;
	int i = 0;

	printf("printing list: \n");
	while (ptr) {
		if (ptr->data)
			printf("Node [%d] - value [%d] - addr -> [%p] - next addr-> [%p]\n", i++, *(int *)ptr->data, ptr, ptr->next);
		else
			printf("Node [%d] - value [%p] - addr -> [%p] - next addr-> [%p]\n", i++, ptr->data, ptr, ptr->next);
		ptr = ptr->next;
	}
}

void list_size_call(void) {
	t_list tab[29] = {};
	t_list alone = {};
	t_list *head = &alone, *ptr = head;

	printf("testing ft_list_size_bonus: \n");
	printf("list with null head: [%d]\n", ft_list_size(NULL));
	printf("list with only one node: [%d]\n", ft_list_size(head));

	for (int i = 0; i < 29; i++) {
		ptr->next =	&tab[i];
		ptr = ptr->next;
	}
	int size = ft_list_size(head);
	printf("list with multiple nodes: [%d]\n\n", ft_list_size(head));
	print_line();
}

void list_push_front_call(void) {
	t_list *ptr = NULL;
	t_list **null_head = NULL;
	static int data = 63254;
	static int first_node = 1654;

	ft_list_push_front(null_head, NULL);
	printf("pushing on a null head after: ptr addr = [%p]\n", null_head);

	printf("\npushing one node to the list -> before: ptr addr = [%p] address inside = [%p]\n", &ptr, ptr);
	ft_list_push_front(&ptr, &first_node);
	printf("pushing one node to the list -> after: ptr addr = [%p] address inside = [%p]\n", &ptr, ptr);

	printf("\npushing 20 nodes in the list: \n");
	for (int i = 0; i < 20; i++) {
		if (i < 10)
			ft_list_push_front(&ptr, NULL);
		else
			ft_list_push_front(&ptr, &data);

	}
	print_list(ptr);
	free_all(ptr);
	printf("\n");
}

int main() {
	list_size_call();
	list_push_front_call();
}