/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:39 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 07:58:06 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void			pswap_sa(t_push_swap *obj, int print)
{
	if ((obj->a_stack)->size >= 2)
		swap_op(obj->a_stack);
	if (print)
		ft_putstr("sa\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void			pswap_sb(t_push_swap *obj, int print)
{
	if ((obj->b_stack)->size >= 2)
		swap_op(obj->b_stack);
	if (print)
		ft_putstr("sb\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void			pswap_ss(t_push_swap *obj, int print)
{
	if ((obj->a_stack)->size >= 2 || (obj->b_stack)->size >= 2)
	{
		if ((obj->a_stack)->size >= 2)
			swap_op(obj->a_stack);
		if ((obj->b_stack)->size >= 2)
			swap_op(obj->b_stack);
	}
	if (print)
		ft_putstr("ss\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void			pswap_pa(t_push_swap *obj, int print)
{
	if ((obj->b_stack)-> size >= 1)
		push_op(obj->b_stack, obj->a_stack);
	if (print)
		ft_putstr("pa\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}

void			pswap_pb(t_push_swap *obj, int print)
{
	if ((obj->a_stack)-> size >= 1)
		push_op(obj->a_stack, obj->b_stack);
	if (print)
		ft_putstr("pb\n");
	if (obj->set_debug && print)
		print_stacks(obj);
	(obj->operations)++;
}
