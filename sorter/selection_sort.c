/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 00:32:00 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 03:10:23 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void				push_max(int max, int mid, t_push_swap *obj, int print)
{
	int				i;
	t_pstack		*temp;

	i = 0;
	temp = (obj->b_stack)->first;
	if (max > mid)
	{
		while (++i <= (obj->b_stack)->size - max + 1)
			pswap_rrb(obj, print);
	}
	else if (max <= mid)
	{
		while (++i < max)
			pswap_rb(obj, print);
	}
	pswap_pa(obj, print);
}

int					pswap_selection_sort(t_push_swap *obj, int print)
{
	int				midpoint;
	int				max_index;

	reset_stacks(obj);
	push_all(obj, 'b', print);
	while (!check_sort(obj) && (obj->b_stack)->size > 0)
	{
		midpoint = ((obj->b_stack)->size) / 2;
		max_index = find_max(obj->b_stack);
		push_max(max_index, midpoint, obj, print);
	}
	return (obj->operations);
}
