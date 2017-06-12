/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 03:08:38 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 07:59:03 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pswap_rrr(t_push_swap *obj, int print)
{
	if ((obj->a_stack)->size >= 2 || (obj->b_stack)->size >= 2)
	{
		if ((obj->a_stack)->size >= 2)
			reverse_rotate_op(obj->a_stack);
		if ((obj->b_stack)->size >= 2)
			reverse_rotate_op(obj->b_stack);
	}
	if (print)
		ft_putstr("rrr\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}
