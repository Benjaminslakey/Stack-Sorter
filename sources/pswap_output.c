/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 01:31:51 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 08:13:09 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int					check_sort(t_push_swap *obj)
{
	int				num;
	t_pstack		*curr;

	num = 0;
	curr = (obj->a_stack)->first;
	if ((obj->b_stack)->first == NULL && (obj->b_stack)->size == 0)
	{
		if ((obj->a_stack)->first)
			num = ((obj->a_stack)->first)->elem;
		else
			return (0);
		while (curr)
		{
			ERR_GUARD((curr->elem < num), 0);
			num = curr->elem;
			curr = curr->next;
		}
	}
	else
		return (0);
	return (1);
}

int					print_error(int err)
{
	if (err)
	{
		ft_putstr_fd("Error\n", 2);
		if (err == 1)
			ft_putstr("Invalid Value...\nData too large for type: integer\n");
		else if (err == 2)
			ft_putstr("Invalid formatting...\nNon numeric input\n");
		else if (err == 3)
			ft_putstr("Duplicate Values\n");
		else if (err == 4)
			ft_putstr("Invalid instruction\n");
		else if (err == 5)
			ft_putstr("No values given\n");
		return (1);
	}
	return (0);
}

void				print_stacks(t_push_swap *obj)
{
	t_pstack		*curr_a;
	t_pstack		*curr_b;

	curr_a = (obj->a_stack)->first;
	curr_b = (obj->b_stack)->first;
	ERR_GUARD_VR((obj->set_debug == 0));
	if (obj->set_color)
		(!check_sort(obj)) ? ft_putstr("\x1b[31m") : ft_putstr("\x1b[32m");
	ft_putstr("Stack A\t\t\t\tStack B\n");
	ft_putstr("------------------------------------------\n");
	while (curr_a || curr_b)
	{
		if (curr_a)
			ft_putnbr(curr_a->elem);
		ft_putstr("\t\t\t\t");
		if (curr_b)
			ft_putnbr(curr_b->elem);
		ft_putstr("\n");
		if (curr_a != NULL)
			curr_a = curr_a->next;
		if (curr_b != NULL)
			curr_b = curr_b->next;
	}
	(obj->set_color) ? ft_putendl("\x1b[0m") : ft_putstr("\n");
}
