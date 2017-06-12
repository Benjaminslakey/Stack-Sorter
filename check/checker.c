/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:39 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 05:46:30 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/checker.h"

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

int					main(int argc, char **argv)
{
	int				var;
	int				options;
	char			**first_num;
	t_push_swap		*obj;

	options = 0;
	first_num = argv;
	ERR_GUARD((argc < 2), -1);
	ERR_GUARD((print_error(err_checks(++first_num, argc - 1))), -1);
	obj = init_sorter();
	obj->checker = 1;
	options = set_options(argc, first_num, obj);
	obj->table_size = argc - options - 1;
	var = check_args(first_num + options);
	if (init_table(var, first_num + options, obj) == 0
			&& obj->table_size > 0)
	{
		reset_stacks(obj);
		validate_sort(obj);
	}
	else if (obj->table_size == 0 && (obj->set_debug || obj->set_color))
		print_error(5);
	clean_prog_memory(&obj);
	return (0);
}
