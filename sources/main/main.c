/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:14:50 by twang             #+#    #+#             */
/*   Updated: 2023/05/30 16:02:46 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*---- global definition -----------------------------------------------------*/

int	g_ret_val;

/*----------------------------------------------------------------------------*/

int	main(int ac, char **av, char **env)
{
	char			*line;
	t_data			data;
	t_string_token	*str_tok_lst;

	(void)ac;
	if (init_main(&data, &str_tok_lst, av, &env) != SUCCESS)
		return (1);
	while (MINI_SHELL_MUST_GO_ON)
	{
		loop_init(&data, &line, env);
		if (get_lexed_str_token_lst_from_line(line, &str_tok_lst, env) \
			!= SUCCESS)
			continue ;
		if (set_data_instruction_arr(&data, str_tok_lst))
			return (go_fuck_yourself_malloc(str_tok_lst, env));
		if (heredoc_management(&data, str_tok_lst, env) != SUCCESS
			&& reset_term_settings(&data) == SUCCESS)
		{
			free(data.instructions_arr);
			string_token_destructor(str_tok_lst);
			continue ;
		}
		reset_term_settings(&data);
		switchman(&data, str_tok_lst, &env);
	}
}
