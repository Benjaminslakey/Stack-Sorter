/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:48:06 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/17 07:57:32 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>

typedef struct			s_pstack_head
{
	int					size;
	struct s_pstack		*first;
}						t_pstack_head;

typedef struct			s_pstack
{
	int					elem;
	struct s_pstack		*next;
}						t_pstack;

typedef struct			s_push_swap
{
	int					checker;
	int					set_debug;
	int					set_color;
	int					print;
	int					*numbers;
	int					table_size;
	int					operations;
	t_pstack_head		*a_stack;
	t_pstack_head		*b_stack;
}						t_push_swap;
/*
** stack functions
*/
t_pstack_head			*init_pstack(int *int_tab, int size);
t_pstack				*create_pstack_node(int elem);
void					reset_stacks(t_push_swap *obj);
void					push_pstack(t_pstack_head *head, t_pstack *elem);
t_pstack				*pop_pstack(t_pstack_head *head);
t_pstack				*peek_pstack_index(int index, t_pstack_head *head);
/*
**instruction set functions
*/
void					push_op(t_pstack_head *head1, t_pstack_head *head2);
void					swap_op(t_pstack_head *head);
void					rotate_op(t_pstack_head *head);
void					reverse_rotate_op(t_pstack_head *head);

void					pswap_sa(t_push_swap *obj, int print);
void					pswap_sb(t_push_swap *obj, int print);
void					pswap_ss(t_push_swap *obj, int print);
void					pswap_pa(t_push_swap *obj, int print);
void					pswap_pb(t_push_swap *obj, int print);
void					pswap_ra(t_push_swap *obj, int print);
void					pswap_rb(t_push_swap *obj, int print);
void					pswap_rr(t_push_swap *obj, int print);
void					pswap_rra(t_push_swap *obj, int print);
void					pswap_rrb(t_push_swap *obj, int print);
void					pswap_rrr(t_push_swap *obj, int print);

/*
** sorting function helpers
*/
int						check_sort(t_push_swap *obj);
int						find_max(t_pstack_head *head);
int						find_min(t_pstack_head *head);
void					push_all(t_push_swap *obj, const char stack, int p);
void					rotate_stacks(int d, int m, t_push_swap *obj, int p);
void					rotate_stack(int s, int d, int m, t_push_swap *o);

/*
**sorting functions
*/
int						pswap_bubble_sort(t_push_swap *obj, int print);
int						pswap_selection_sort(t_push_swap *obj, int print);
int						pswap_insertion_sort(t_push_swap *obj, int print);
void					sort_trips(t_push_swap *obj, int print);

/*
** input & output functions
*/
void					set_debug();
void					set_color();
int						init_table(int var, char **args, t_push_swap *obj);
void					print_stacks(t_push_swap *obj);
int						print_error(int err);

/*
** program setup and cleanup
*/
t_push_swap				*init_sorter(void);
int						err_checks(char **args, int arg_count);
int						check_args(char **args);
int						set_options(int argc, char **args, t_push_swap *obj);
void					clean_stack(t_pstack_head **stack);

#endif
