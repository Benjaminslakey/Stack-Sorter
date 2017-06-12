/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:39 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 03:21:13 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void				push_op(t_pstack_head *head1, t_pstack_head *head2)
{
	t_pstack		*temp;

	if (head1 && head2)
	{
		temp = pop_pstack(head1);
		push_pstack(head2, temp);
	}
}

void				swap_op(t_pstack_head *head)
{
	t_pstack		*elem1;
	t_pstack		*elem2;

	elem1 = NULL;
	elem2 = NULL;
	if (head->size > 1)
	{
		elem1 = pop_pstack(head);
		elem2 = pop_pstack(head);
		push_pstack(head, elem1);
		push_pstack(head, elem2);
	}
}

void				rotate_op(t_pstack_head *head)
{
	t_pstack		*temp;
	t_pstack		*first;

	if (head->size > 1)
	{
		first = head->first;
		head->first = first->next;
		first->next = NULL;
		temp = head->first;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = first;
	}
}

void				reverse_rotate_op(t_pstack_head *head)
{
	t_pstack		*last;
	t_pstack		*second_last;

	if (head->size == 2)
	{
		last = head->first;
		head->first = last->next;
		last->next = NULL;
		(head->first)->next = last;
	}
	else if (head->size > 2)
	{
		second_last = head->first;
		last = head->first;
		while (last->next != NULL)
		{
			second_last = second_last->next;
			last = second_last->next;
		}
		last->next = head->first;
		head->first = last;
		second_last->next = NULL;
	}
}
