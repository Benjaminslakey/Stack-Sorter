/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 03:42:51 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 03:27:31 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void				push_all(t_push_swap *obj, const char stack, int print)
{
	if (stack == 'a')
	{
		while ((obj->b_stack)->size)
			pswap_pa(obj, print);
	}
	else if (stack == 'b')
	{
		while ((obj->a_stack)->size)
			pswap_pb(obj, print);
	}
}

void				rotate_stacks(int d, int m, t_push_swap *obj, int print)
{
	int			i;

	i = -1;
	while (++i < m)
	{
		if (d)
			pswap_rr(obj, print);
		else
			pswap_rrr(obj, print);
	}
}

void				rotate_stack(int s, int d, int m, t_push_swap *obj)
{
	int			i;

	i = -1;
	while (++i < m)
	{
		if (s == 1)
		{
			if (d)
				pswap_ra(obj, obj->print);
			else
				pswap_rra(obj, obj->print);
		}
		else
		{
			if (d)
				pswap_rb(obj, obj->print);
			else
				pswap_rrb(obj, obj->print);
		}
	}
}

int					find_min(t_pstack_head *head)
{
	int			i;
	int			index;
	int			min;
	t_pstack	*curr;

	index = 1;
	i = 0;
	if (head->first != NULL)
		curr = head->first;
	else
		return (0);
	min = curr->elem;
	while (++i <= head->size && curr != NULL)
	{
		if (curr->elem < min)
		{
			min = curr->elem;
			index = i;
		}
		curr = curr->next;
	}
	return (index);
}

int					find_max(t_pstack_head *head)
{
	int			i;
	int			j;
	int			max;
	t_pstack	*curr;

	i = 0;
	j = 1;
	if (head->first != NULL)
		curr = head->first;
	else
		return (0);
	max = curr->elem;
	while (++i <= head->size && curr != NULL)
	{
		if (curr->elem > max)
		{
			max = curr->elem;
			j = i;
		}
		curr = curr->next;
	}
	return (j);
}
