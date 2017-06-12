/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:39 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 07:37:22 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <limits.h>
#include <stdio.h>

int					check_args(char **args)
{
	int				i;
	int				num;
	int				wspc;

	i = -1;
	wspc = 0;
	while (args[0][++i])
	{
		if (num && wspc && ANUM(args[0][i]))
			return (1);
		else if (ANUM(args[0][i]))
			num = 1;
		else if (WHT(args[0][i]) && num)
			wspc = 1;
	}
	return (0);
}

int					err_checks(char **args, int argc)
{
	int			i;
	int			j;

	i = -1;
	if (!ft_strcmp(args[0], "-v") || !ft_strcmp(args[0], "-c"))
		i++;
	if (argc > 1 && (!ft_strcmp(args[1], "-v") || !ft_strcmp(args[1], "-c")))
		i++;
	while (++i < argc)
	{
		ERR_GUARD((i <= 2) && check_args(&(args[i])), 0);
		ERR_GUARD((ft_strlen(args[i]) > 10 && (ft_atoi(args[i]) > INT_MAX ||
					ft_atoi(args[i]) < INT_MIN)), 1);
		ERR_GUARD((!ft_str_isnum(args[i]) && !ft_atoi(args[i])), 2);
		j = i;
		while (++j < argc && args[j])
			ERR_GUARD((ft_atoi(args[i]) == ft_atoi(args[j])), 3);
	}
	return (0);
}

int					set_options(int argc, char **args, t_push_swap *obj)
{
	if (args[0][0] == '-')
	{
		if (argc >= 3)
		{
			if (!ft_strcmp(args[0], "-v") || !ft_strcmp(args[1], "-v"))
				obj->set_debug = 1;
			if (!ft_strcmp(args[0], "-c") || !ft_strcmp(args[1], "-c"))
				obj->set_color = 1;
		}
		else
		{
			if (!ft_strcmp(args[0], "-v"))
				obj->set_debug = 1;
			if (!ft_strcmp(args[0], "-c"))
				obj->set_color = 1;
		}
	}
	if (obj->set_color || obj->set_debug)
		return ((obj->set_color && obj->set_debug) ? 2 : 1);
	return (0);
}

t_push_swap			*init_sorter(void)
{
	t_push_swap		*obj;

	obj = (t_push_swap*)malloc(sizeof(t_push_swap));
	obj->checker = 0;
	obj->set_debug = 0;
	obj->set_color = 0;
	obj->print = 0;
	obj->table_size = 0;
	obj->operations = 0;
	obj->numbers = NULL;
	obj->a_stack = NULL;
	obj->b_stack = NULL;
	return (obj);
}

int					init_table(int var, char **args, t_push_swap *obj)
{
	int				i;
	int				err;
	int				opt;
	char			**nums;

	err = 0;
	i = -1;
	nums = NULL;
	opt = 0;
	if (var)
	{
		nums = ft_strsplit(args[0], ' ');
		while (nums[++i])
			;
		err = print_error(err_checks(nums, i));
		if (!(obj->set_debug) && !(obj->set_color))
			opt = set_options(i, nums, obj);
		obj->table_size = i - opt;
		i = -1;
	}
	obj->numbers = (int*)malloc(sizeof(int) * obj->table_size);
	while (++i < obj->table_size)
		(obj->numbers)[i] = ft_atoi((var) ? nums[i + opt] : args[i]);
	free(nums);
	return (err);
}
