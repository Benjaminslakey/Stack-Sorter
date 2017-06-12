/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:40:54 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 03:25:47 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_pstack			*create_pstack_node(int elem)
{
	t_pstack		*node;

	MEM_GUARD((node = (t_pstack*)malloc(sizeof(t_pstack))));
	node->elem = elem;
	node->next = NULL;
	return (node);
}

t_pstack_head		*init_pstack(int *int_tab, int size)
{
	int				i;
	t_pstack_head	*head;
	t_pstack		*temp;
	t_pstack		*prev;

	i = -1;
	MEM_GUARD((head = (t_pstack_head*)malloc(sizeof(t_pstack_head))));
	head->first = NULL;
	head->size = size;
	ERR_GUARD((size == 0 || int_tab == NULL), head);
	while (++i < size)
	{
		temp = create_pstack_node(int_tab[i]);
		if (i == 0)
			head->first = temp;
		else
			prev->next = temp;
		prev = temp;
		temp = temp->next;
	}
	return (head);
}

void				clean_stack(t_pstack_head **stack)
{
	t_pstack_head	*head;
	t_pstack		*next;
	t_pstack		*temp;

	head = *stack;
	temp = (*stack)->first;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	free(head);
	*stack = NULL;
}

void				reset_stacks(t_push_swap *obj)
{
	if (obj->a_stack != NULL)
		clean_stack(&(obj->a_stack));
	if (obj->b_stack != NULL)
		clean_stack(&(obj->b_stack));
	obj->a_stack = init_pstack(obj->numbers, obj->table_size);
	obj->b_stack = init_pstack(NULL, 0);
	obj->operations = 0;
}
