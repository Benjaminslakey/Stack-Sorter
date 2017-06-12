/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 05:46:52 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 05:51:48 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

int					already_sorted(int *arr, int size)
{
	int				i;
	int				prev;

	i = -1;
	prev = arr[0];
	ERR_GUARD((arr == NULL || size == 0 || size == 1), 1);
	while (++i < size)
	{
		if (prev > arr[i])
			return (0);
		prev = arr[i];
	}
	return (1);
}

static void			clean_prog_memory(t_push_swap **obj)
{
	if ((*obj)->a_stack != NULL)
		clean_stack(&((*obj)->a_stack));
	if ((*obj)->b_stack != NULL)
		clean_stack(&((*obj)->b_stack));
	free((*obj)->numbers);
	free(*obj);
	*obj = NULL;
}

void				determine_sort(t_push_swap *obj)
{
	int				selection;
	int				bubble;
	int				insertion;

	if (obj->table_size <= 3)
	{
		sort_trips(obj, 1);
		return ;
	}
	if (obj->table_size < 30)
		bubble = pswap_bubble_sort(obj, 0);
	else
		bubble = INT_MAX;
	insertion = pswap_insertion_sort(obj, 0);
	selection = pswap_selection_sort(obj, 0);
	obj->print = 1;
	if (selection <= bubble && selection <= insertion)
		pswap_selection_sort(obj, 1);
	else if (insertion <= bubble && insertion <= selection)
		pswap_insertion_sort(obj, 1);
	else if (bubble <= selection && bubble <= insertion)
		pswap_bubble_sort(obj, 1);
}

int					main(int argc, char **argv)
{
	int				options;
	int				var;
	char			**first_num;
	t_push_swap		*sorter;

	options = 0;
	first_num = argv;
	if (argc < 2)
	{
		ft_putstr("Error\nNo values given\n");
		return (0);
	}
	ERR_GUARD((print_error(err_checks(++first_num, argc - 1))), -1);
	sorter = init_sorter();
	options = set_options(argc, first_num, sorter);
	sorter->table_size = argc - options - 1;
	var = check_args(first_num + options);
	if (init_table(var, first_num + options, sorter) == 0 &&
			!already_sorted(sorter->numbers, sorter->table_size))
		determine_sort(sorter);
	clean_prog_memory(&sorter);
	return (0);
}
