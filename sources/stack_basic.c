/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:39 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 03:30:41 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void				push_pstack(t_pstack_head *head, t_pstack *elem)
{
	t_pstack		*temp;

	if (head->size > 0 && elem)
	{
		temp = head->first;
		head->first = elem;
		elem->next = temp;
		(head->size)++;
	}
	else if (head->size == 0 && elem)
	{
		head->first = elem;
		(head->size)++;
	}
}

t_pstack			*pop_pstack(t_pstack_head *head)
{
	t_pstack		*temp;

	temp = NULL;
	MEM_GUARD(head);
	temp = head->first;
	head->first = (temp != NULL && temp->next != NULL) ? temp->next : NULL;
	if (temp)
		temp->next = NULL;
	(head->size)--;
	return (temp);
}

t_pstack			*peek_pstack_index(int index, t_pstack_head *head)
{
	int				i;
	t_pstack		*temp;

	i = 0;
	MEM_GUARD(head);
	MEM_GUARD((temp = head->first));
	if (index == 1)
		return (head->first);
	while (++i < index)
		temp = temp->next;
	return (temp);
}
