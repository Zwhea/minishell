/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_the_programme.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:46:35 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/05/27 14:46:37 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- prototypes ------------------------------------------------------------*/

static t_return_status	check_exit_args_unic(char **av, \
							char ***env_pt, t_data *data);
static void				cleaning_process_exit(t_data *data, \
							char **env, char **av);

/*----------------------------------------------------------------------------*/

t_return_status	exit_the_program(t_data *data, char ***env_pt, t_cmd cmd)
{
	char	**av;

	av = cmd.commands;
	ft_dprintf(2, RED"exit\n"END);
	if (av[1])
	{
		check_exit_args_unic(av, env_pt, data);
		return (FAILURE);
	}
	cleaning_process_exit(data, *env_pt, av);
	exit(g_ret_val);
	return (SUCCESS);
}

static t_return_status	check_exit_args_unic(char **av, \
							char ***env_pt, t_data *data)
{
	int	nb;

	if (ft_atoi_on(av[1], &nb) == FAILURE
		|| ft_isnbr(av[1]) == false)
	{
		ft_dprintf(2, \
		RED"minishell: exit: %s: numeric argument required\n"END, av[1]);
		cleaning_process_exit(data, *env_pt, av);
		exit(2);
	}
	if (ft_str_array_len(av) > 2)
	{
		ft_dprintf(2, RED"minishell: exit: too many arguments\n"END);
		g_ret_val = 1;
		ft_free_split(av);
		return (FAILURE);
	}
	g_ret_val = ft_atoi(av[1]);
	cleaning_process_exit(data, *env_pt, av);
	exit(g_ret_val);
	return (SUCCESS);
}

static void	cleaning_process_exit(t_data *data, char **env, char **av)
{
	free(data->instructions_arr);
	free(data->prompt);
	free(data->cmds_block);
	ft_free_split(env);
	ft_free_split(av);
}
