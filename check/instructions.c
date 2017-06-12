/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 20:57:55 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 08:08:43 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"
#include <stdio.h>

int					check_instruction(char *instruction)
{
	if (!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "sb")
			|| !ft_strcmp(instruction, "ss") || !ft_strcmp(instruction, "pa")
			|| !ft_strcmp(instruction, "pb") || !ft_strcmp(instruction, "ra")
			|| !ft_strcmp(instruction, "rb") || !ft_strcmp(instruction, "rr")
			|| !ft_strcmp(instruction, "rra") || !ft_strcmp(instruction, "rrb")
			|| !ft_strcmp(instruction, "rrr"))
		return (1);
	print_error(4);
	return (0);
}

void				execute_instructions(char *instruction, t_push_swap *obj)
{
	int				print;

	print = 0;
	if (!ft_strcmp(instruction, "sa"))
		pswap_sa(obj, print);
	else if (!ft_strcmp(instruction, "sb"))
		pswap_sb(obj, print);
	else if (!ft_strcmp(instruction, "ss"))
		pswap_ss(obj, print);
	else if (!ft_strcmp(instruction, "pa"))
		pswap_pa(obj, print);
	else if (!ft_strcmp(instruction, "pb"))
		pswap_pb(obj, print);
	else if (!ft_strcmp(instruction, "ra"))
		pswap_ra(obj, print);
	else if (!ft_strcmp(instruction, "rb"))
		pswap_rb(obj, print);
	else if (!ft_strcmp(instruction, "rr"))
		pswap_rr(obj, print);
	else if (!ft_strcmp(instruction, "rra"))
		pswap_rra(obj, print);
	else if (!ft_strcmp(instruction, "rrb"))
		pswap_rrb(obj, print);
	else if (!ft_strcmp(instruction, "rrr"))
		pswap_rrr(obj, print);
}

int					validate_sort(t_push_swap *obj)
{
	char			*instruction;

	instruction = NULL;
	while (get_next_line(0, &instruction) > 0)
	{
		if (check_instruction(instruction))
		{
			execute_instructions(instruction, obj);
			print_stacks(obj);
		}
		else
			break ;
	}
	if (!check_sort(obj))
	{
		ft_putstr("KO\n");
		return (0);
	}
	else
	{
		ft_putstr("OK\n");
		return (1);
	}
}
