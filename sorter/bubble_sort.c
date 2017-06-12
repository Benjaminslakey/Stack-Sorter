/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 09:35:35 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/04 17:05:04 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

static void			bubble_swap(t_push_swap *obj, int ind_i, int print)
{
	int			i;

	i = -1;
	while (++i < ind_i)
		pswap_pb(obj, print);
	pswap_sa(obj, print);
	while ((obj->b_stack)->size)
		pswap_pa(obj, print);
}

int					pswap_bubble_sort(t_push_swap *obj, int print)
{
	int					i;
	int					count;
	int					temp;
	t_pstack			*temp_i;
	t_pstack			*temp_j;

	count = -1;
	reset_stacks(obj);
	while (++count < (obj->table_size))
	{
		i = -1;
		while (++i < (obj->table_size) - 1)
		{
			temp = -1;
			temp_i = (obj->a_stack)->first;
			while (++temp < i)
				temp_i = temp_i->next;
			temp_j = temp_i->next;
			if (temp_i->elem > temp_j->elem)
				bubble_swap(obj, i, print);
			temp_j = temp_j->next;
			temp_i = temp_i->next;
		}
	}
	return (obj->operations);
}
