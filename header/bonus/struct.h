#pragma once

typedef struct s_list
{
	void *data;
	struct s_list *next;
} t_list;

int ft_list_size(t_list *begin_list);

void ft_list_push_front(t_list **begin_list, void *data);