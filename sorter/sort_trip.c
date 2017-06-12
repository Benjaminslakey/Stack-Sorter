/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_trips.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 05:46:41 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/16 06:50:52 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				sort_trips(t_push_swap *obj, int print)
{
	int				max;

	max = 0;
	reset_stacks(obj);
	if (obj->table_size == 2)
		pswap_sa(obj, print);
	else if (obj->table_size == 3)
	{
		max = find_max(obj->a_stack);
		if (max == 1)
			pswap_ra(obj, print);
		else if (max == 2)
			pswap_rra(obj, print);
		if (((obj->a_stack)->first)->elem >
				(((obj->a_stack)->first)->next)->elem)
			pswap_sa(obj, print);
	}
}
