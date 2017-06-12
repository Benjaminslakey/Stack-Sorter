/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 03:07:28 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 07:58:47 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pswap_ra(t_push_swap *obj, int print)
{
	if ((obj->a_stack)->size >= 2)
		rotate_op(obj->a_stack);
	if (print)
		ft_putstr("ra\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void		pswap_rb(t_push_swap *obj, int print)
{
	if ((obj->b_stack)->size >= 2)
		rotate_op(obj->b_stack);
	if (print)
		ft_putstr("rb\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void		pswap_rr(t_push_swap *obj, int print)
{
	if ((obj->a_stack)->size >= 2 || (obj->b_stack)->size >= 2)
	{
		if ((obj->a_stack)->size >= 2)
			rotate_op(obj->a_stack);
		if ((obj->b_stack)->size >= 2)
			rotate_op(obj->b_stack);
	}
	if (print)
		ft_putstr("rr\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void		pswap_rra(t_push_swap *obj, int print)
{
	if ((obj->a_stack)->size >= 2)
		reverse_rotate_op(obj->a_stack);
	if (print)
		ft_putstr("rra\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void		pswap_rrb(t_push_swap *obj, int print)
{
	if ((obj->b_stack)->size >= 2)
		reverse_rotate_op(obj->b_stack);
	if (print)
		ft_putstr("rrb\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}
