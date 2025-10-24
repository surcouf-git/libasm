#include <stdio.h>
#include "struct.h"

void print_list(t_list *head) {
	t_list *ptr = head;
	int i = 0;

	while (ptr) {
		printf("Node [%d] - value [%s] - addr-> [%p]\n", i, (char *)ptr->data, ptr);
		ptr = ptr->next;
	}
}

int main() {
	t_list alone;
	t_list tab[30] = {};
	
	t_list *head = &alone, *ptr = head;

	for (int i = 0; i < 30; i++) {
		ptr->next =	&tab[i];
		ptr = ptr->next;
	}
	ptr->next = NULL;

	printf("SIZE:%d\n", ft_list_size(head));

	t_list *nptr = NULL, *nnptr = nptr;
	ft_list_push_front(&nptr, NULL);
	print_list(nnptr);
}