/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:07:42 by twang             #+#    #+#             */
/*   Updated: 2023/05/29 16:27:00 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "enums.h"

/*---- typedef structures ----------------------------------------------------*/

typedef struct s_token			t_token;
typedef struct s_block			t_block;
typedef struct s_string_token	t_string_token;
typedef struct s_data			t_data;
typedef struct s_cmd			t_cmd;

/*---- typedef function pointers ---------------------------------------------*/

typedef t_return_status			(*t_preserv_act)(t_token *a, t_token *b, \
																t_token **c);
typedef t_return_status			(*t_export_ft)(char *arg, char ***env_pt);
typedef t_return_status			(*t_files_manage_ft)(t_data *data, \
										char **line, int i, char **env);
typedef t_return_status			(*t_builtin_ft)(char **av, char ***env_pt);
typedef bool					(*t_increment_ft)(char line_pt, void *arg);
typedef bool					(*t_act_update)(t_string_token ** token);

/*---- structures ------------------------------------------------------------*/

struct	s_token
{
	t_emt			token;
	char			sign_char;
	void			*content;
	t_esec			esec;
	struct s_token	*next;
	struct s_token	*next_word;
};

struct	s_block
{
	int		value;
	t_e_op	e_op;
	t_block	*right;
	t_block	*left;
};

struct s_string_token
{
	t_emt				token;
	char				*content;
	char				**str_arr;
	t_string_token		*next;
};

struct s_data
{
	t_cmd			*cmds_block;
	t_string_token	**instructions_arr;
	struct termios	term;
	int				index;
	char			*prompt;
	int				fd[2];
	int				nb_of_pipe;
};

struct s_cmd
{
	t_builtin	id_command;
	char		**commands;
	char		*heredoc_data;
	bool		is_ambiguous;
	bool		is_heredoc;
	int			infile;
	int			outfile;
	int			fd_hd[2];
	pid_t		process_id;
};

#endif