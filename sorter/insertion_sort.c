/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:59:39 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/16 05:41:38 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

/*
** find insertion point returns differing values depending on the stack it is
** looking through. Stack B is used as the temporary stack and A is the stack
** to sorted into. When the char 'b' is given for which, the function will
** return the index of the stack oect holding num. When given 'a'  the function
** searches through stack A until it has check all elements or found the proper
** place for the number inside the sorted stack
*/

int					find_insertion_point(t_push_swap *o, int num, int m,
		const char which)
{
	int				i;
	t_pstack_head	*stack;
	t_pstack		*curr;

	i = -1;
	stack = (which == 'a') ? o->a_stack : o->b_stack;
	ERR_GUARD((m == 0), 1);
	curr = peek_pstack_index(m, stack);
	if (which == 'a')
	{
		if (stack->size == 0)
			return (1);
		while (++i <= stack->size)
		{
			ERR_GUARD((num < curr->elem), ((m + i <= stack->size) ?
						m + i : (m + i) - stack->size));
			curr = (curr->next == NULL) ? stack->first : curr->next;
		}
		return ((m + i > stack->size) ? m + i - stack->size - 1 : m + i + 1);
	}
	while (++i < stack->size && curr->elem != num)
		curr = curr->next;
	return (i + 1);
}

/*
** The index array holds the index A in i[0] B in i[1]
** in the distance arrays for a stack and b stack the 0 index holds the
** distance downwards until rotated to the top and the 1 index holds the
** distance upwards. B index is the place that the num to insert currently sits
** in stack B, A index is the place for the number to be inserted.
** The ops array hold the number of operations to insert a given element IF:
** ops[0]: both stacks are rotated down simultaneously for the smaller amount
** in the down direction before rotating the larger section into position
** ops[1]: both stacks are rotated up simultaneously for the smaller amount in
** the up direction before rotating the larger section into position.
** !! ops[0] & ops[1] effectively cut out the operations required to rotate the
** smaller stack by including its rotation in the larger stacks by using ops
** RR or RRR!!
** ops[3]: both stacks are rotated in the direction of their shortest path but
** not at the same time
*/

int					calculate_operations(int to_insert, int **operations,
		int **table, t_push_swap *o)
{
	int				a[2];
	int				b[2];
	int				i[2];
	int				ops[3];

	i[1] = find_insertion_point(o, to_insert, 1, 'b');
	i[0] = find_insertion_point(o, to_insert, find_min(o->a_stack), 'a');
	a[1] = (i[0] > 0) ? i[0] - 1 : 0;
	a[0] = (i[0] <= (o->a_stack)->size) ? (o->a_stack)->size - i[0] + 1 : 1;
	b[1] = (i[1] > 0) ? i[1] - 1 : 0;
	b[0] = (o->b_stack)->size - i[1] + 1;
	ops[0] = (a[0] > b[0]) ? a[0] : b[0];
	ops[1] = (a[1] > b[1]) ? a[1] : b[1];
	ops[2] = ((a[0] < a[1]) ? a[0] : a[1]) + ((b[0] < b[1]) ? b[0] : b[1]);
	copy_int_array(&(table[0]), i, 2);
	copy_int_array(&(table[1]), a, 2);
	copy_int_array(&(table[2]), b, 2);
	copy_int_array(operations, ops, 3);
	if (ops[0] < ops[1] && ops[0] < ops[2])
		return (ops[0]);
	else if (ops[1] < ops[0] && ops[1] < ops[2])
		return (ops[1]);
	return (ops[2]);
}

/*
** the integer table, table, is used to hold data about each stack which was
** created inside of the calculate operations function. Inside the 2d array:
** table[0]: holds the two indicides, representing the position to be inserted
** into stack a, and the current position in stack b
** table[1] & table[2] hold information about the index of insertion with
** relation to the top of the stack, more specifically, how many moves in
** the up or down directions it take to correctly position the stack for
** insertion. with the first index being the moves downward and the next
** being the moves upward.
*/

void				best_insert(int **ops, int **t, t_push_swap *o)
{
	int				moves;
	int				least;
	int				*operations;
	int				**table;
	t_pstack		*curr;

	curr = (o->b_stack)->first;
	MEM_GUARD_VR((table = new_int_table(3, 2)));
	MEM_GUARD_VR((operations = (int*)malloc(sizeof(int) * 3)));
	least = calculate_operations(curr->elem, &operations, table, o);
	while (curr != NULL)
	{
		moves = calculate_operations(curr->elem, &operations, table, o);
		if (moves <= least)
		{
			copy_int_array(t, table[0], 2);
			copy_int_array(&(t[1]), table[1], 2);
			copy_int_array(&(t[2]), table[2], 2);
			copy_int_array(ops, operations, 3);
			least = moves;
		}
		curr = curr->next;
	}
	delete_int_table(3, &table);
	free(operations);
}

void				adjust_stacks(t_push_swap *o, int p)
{
	int				d;
	int				**t;
	int				*ops;

	MEM_GUARD_VR((t = new_int_table(3, 2)));
	MEM_GUARD_VR((ops = (int*)malloc(sizeof(int) * 3)));
	best_insert(&ops, t, o);
	if (ops[0] < ops[2] || ops[1] < ops[2])
	{
		d = (ops[0] < ops[1]) ? 0 : 1;
		rotate_stacks(d, (t[1][d] < t[2][d]) ? t[1][d] : t[2][d], o, p);
		rotate_stack((t[1][d] > t[2][d]) ? 1 : 2, d,
		(t[1][d] > t[2][d]) ? t[1][d] - t[2][d] : t[2][d] - t[1][d], o);
	}
	else
	{
		rotate_stack(1, (t[1][0] < t[1][1]) ? 0 : 1,
		(t[1][0] < t[1][1]) ? t[1][0] : t[1][1], o);
		rotate_stack(2, (t[2][0] < t[2][1]) ? 0 : 1,
		(t[2][0] < t[2][1]) ? t[2][0] : t[2][1], o);
	}
	delete_int_table(3, &t);
	free(ops);
}

int					pswap_insertion_sort(t_push_swap *o, int p)
{
	int				i;
	int				dir;
	int				m;

	i = 0;
	reset_stacks(o);
	while ((o->a_stack)->size > 2)
		pswap_pb(o, p);
	while ((o->b_stack)->size > 0)
	{
		adjust_stacks(o, p);
		pswap_pa(o, p);
	}
	dir = (find_min(o->a_stack) > (o->a_stack)->size / 2) ? 0 : 1;
	m = find_min(o->a_stack);
	rotate_stack(1, dir, (dir) ? m - 1 : (o->a_stack)->size - m + 1, o);
	return (o->operations);
}
