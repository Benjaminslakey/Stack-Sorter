/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 05:31:51 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 03:24:14 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../includes/push_swap.h"

int					validate_sort(t_push_swap *obj);
int					check_instruction(char *instruction);
void				execute_instructions(char *instruction, t_push_swap *obj);

#endif
