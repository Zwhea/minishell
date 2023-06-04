/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:25:03 by twang             #+#    #+#             */
/*   Updated: 2023/05/29 17:55:31 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*---- includes --------------------------------------------------------------*/

# include "structures.h"

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*---- Builtins --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- env_utils -------------------------------------------------------------*/
/*---- env_utils.c ----*/
bool			has_a_key_from_env(char *line, char **env);
void			replace_content_in_env(char *line, char **env);
t_return_status	add_str_to_env(char *line, char ***env_pt);
bool			is_a_key_from_env(char *key, char **env);
t_return_status	del_str_from_env(char *line, char ***env_pt);

/*---- get_in_env.c ----*/
char			*get_line_from_key(char *key, char **env);
char			**get_line_addr_from_key(char *key, char **env);
char			*get_env_content_from_key(char *key, char **env);
bool			key_is_not_alnum(char *line);

/*---- ordering_env_export.c ----*/
char			*get_first_line_in_env(char **env);
char			*get_next_line_in_env(char *last, char **env);

/*---- utils -------------------------------------------------------------*/
/*---- export_get_ft_to_do.c ----*/
void			get_rid_of_plus(char *line);
t_export_ft		get_ft_to_do(char *line, char **env);
t_return_status	concat_content_to_line_in_env(char *line, char ***env_pt);
t_return_status	do_nothing_t_export_ft(char *line, char ***env_pt);
t_return_status	not_in_context_error(char *line, char ***env_pt);

/*---- cd.c ----*/
t_return_status	cd_builtin(char **av, char ***env_pt);

/*---- echo.c ----*/
t_return_status	echo_builtin(char **av, char ***env_pt);

/*---- env.c ----*/
t_return_status	env_builtin(char **av, char ***env_pt);

/*---- exit.c ----*/
t_return_status	exit_builtin(char **av, char ***env_pt);

/*---- exit_the_programme.c ----*/
t_return_status	exit_the_program(t_data *data, char ***env_pt, t_cmd cmd);

/*---- export.c ----*/
t_return_status	export_builtin(char **args, char ***env_pt);
t_return_status	replace_content_in_env_pt(char *line, char ***env_pt);

/*---- pwd.c ----*/
t_return_status	pwd_builtin(char **args, char ***env_pt);

/*---- unset.c ----*/
t_return_status	unset_builtin(char **args, char ***env_pt);

/*----------------------------------------------------------------------------*/
/*---- Execution_settings ----------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- expands ---------------------------------------------------------------*/
/*---- cut_line_utils.c ----*/
void			increment_count_and_reset_pin(size_t *count_pt, char **line_pt);

/*---- cut_line.c ----*/
t_return_status	cut_line_on(char *line, char ***res_pt);

/*---- expands_utils.c ----*/
bool			is_eq_to(char obj, void *to_compare);
bool			isnotalnum(char obj, void *to_ignore);
bool			is_from_base(char obj, void *base);
t_return_status	check_allocations(char **line_arr, size_t arr_len);

/*---- expands.c ----*/
t_return_status	performe_expand_on_line(char **line_pt, char **env);
t_return_status	join_token_lst_on(t_cmd *cmd, t_string_token **arg, char **env);
char			**join_token_lst(t_string_token **arg, char **env);

/*---- join_expands.c ----*/
t_return_status	join_arr_on(char **str_arr, char **line_pt, char **env);
void			cpy_next_char(unsigned int index, char *str);

/*---- replace_dollar_str_by_env_value.c ----*/
t_return_status	replace_dollar_str_by_env_value(char **pin_pt, char **env);

/*---- replace_dquotes_str_by_env_value.c ----*/
t_return_status	replace_dquotes_str_by_env_value(char **line_pt, char **env);

/*---- subshell --------------------------------------------------------------*/
/*---- subshell_preparation.c ----*/
char			**subshell_preparation(t_string_token **start);

/*---- switchmans ------------------------------------------------------------*/
/*---- switchman_once.c ----*/
t_return_status	switchman_once(t_data *data, char ***env_pt);
void			ft_free_all_str_lst(t_data *data, int index);

/*---- switchman_utils.c ----*/
size_t			go_to_next_(t_emt token, t_string_token *tmp, \
								t_string_token **str_tok);
void			go_to_next_logical_door(t_string_token *src, \
								t_string_token **dst);
int				get_next_index(int last, t_string_token **instructions_arr);

/*---- switchman.c ----*/
t_return_status	switchman(t_data *data, \
					t_string_token *token_lst, char ***env_pt);

/*---- wildcards -------------------------------------------------------------*/
/*---- files_wildcards.c ----*/
t_return_status	wildcard_files(t_data *data, char **file, int block_id);

/*---- utils.c ----*/
t_return_status	check_line(char *line);
void			replace_wild_card(char *line);

/*---- wildcards_utils.c ----*/
int				get_alloc_size(char *line);
t_return_status	find_matching_files(char *line, char *name);
t_return_status	fill_dst_arr(char *line, char **arr_to_fill);

/*---- wildcards.c ----*/
t_return_status	expand_wildcards(char ***original_pt);

/*---- env_init.c ----*/
t_return_status	env_init_on(char ***env_pt);

/*----------------------------------------------------------------------------*/
/*---- Execve ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- childs.c ----*/
t_return_status	childs_execve(t_data *data, char ***env);

/*---- exec_articultaion_utils.c ----*/
bool			check_cmd(t_cmd *cmd);
void			init_data(t_data *data);

/*---- exec_articultaion.c ----*/
t_return_status	execution(t_data *data, t_string_token *lst_of_tok, \
									char ***env_pt);

/*---- executions.c ----*/
void			subshell_then_exit(t_cmd command, char ***env);
void			builtin_then_exit(t_cmd command, char ***env);
void			execve_then_exit(t_cmd command, char ***env);
t_return_status	builtin_switch(t_cmd command, char **av, char ***env_pt);

/*---- fds_manage.c ----*/
t_return_status	duplicate_fds(t_cmd block, t_data *data, char ***env_pt);
t_return_status	heredoc_child_management(t_cmd *cmd, t_data *data, \
										char **env_pt);

/*---- pipes_manage.c ----*/
t_return_status	do_the_pipe(t_cmd *cmd_block, int nb_of_pipe, int block_id);
void			manage_the_pipe(t_data *data, int block_id);

/*---- utils.c ----*/
t_return_status	is_executable(char *command);
void			close_this(int fd);
char			*add_path_cmd(t_cmd *cmd, char **env);
void			free_all_others(t_cmd *cmds, int block_id, int nb_of_pipes);

/*----------------------------------------------------------------------------*/
/*---- Lexing ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- 1_preservation --------------------------------------------------------*/
/*---- double_quoting.c ----*/
t_return_status	dquoting_process(t_token *last_token, \
									t_token *token, t_token **end_of_quot_pt);
/*---- preserv.c ----*/
t_return_status	preserve_token_lst(t_token *token);

/*---- simple_quoting.c ----*/
t_return_status	squoting_process(t_token *last_token, \
	t_token *token, t_token **end_of_quot_pt);

/*---- 2_metachar_managing ---------------------------------------------------*/

/*---- split_toklst_on_meta.c ----*/
t_token			*split_toklst_on_meta(t_token *tok);
t_token			*regroup_meta(t_token *tok);
char			*get_prompt(char *str, int flag);

/*---- lexing_token_utils ----------------------------------------------------*/
/*---- tokens_lst_utils_2.c ----*/
void			del_token(t_token *token);
int				len_to_next_type(t_token *pin);

/*---- tokens_lst_utils.c ----*/
t_token			*token_constructor(t_emt emt, char msg);
void			token_lst_clear(t_token *trash);

/*---- lexing_articulation.c ----*/
t_return_status	get_lexed_str_token_lst_from_line(char *line, \
		t_string_token **str_tok_pt, char **env);
t_string_token	*parsing_constructor(char *str, char **env);

/*----------------------------------------------------------------------------*/
/*---- Main ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- prompt ----------------------------------------------------------------*/
/*---- prompt.c ----*/
t_return_status	get_prompt_on(char **prompt_pt, char **env);

/*---- prompt_utils.c ----*/
void			copy_all_box(char *box, char *pwd, size_t box_width);
t_return_status	clean_the_prompt(char *line, char **env);

/*---- utils -----------------------------------------------------------------*/
/*---- display.c ----*/
t_return_status	welcome_to_minihell(char ***env_pt);

/*---- return_to_root.c ====*/
void			return_to_root(char *line, char **env);

/*---- utils.c ----*/
t_return_status	reset_term_settings(t_data *data);
t_return_status	init_main(t_data *data, t_string_token **str_token_pt, \
				char **av, char ***env_pt);
void			loop_init(t_data *data, char **line_pt, char **env);
t_return_status	set_data_instruction_arr(t_data *data, \
									t_string_token *str_tok_lst);
int				go_fuck_yourself_malloc(t_string_token *token_lst, char **env);
t_return_status	check_arguments(char **av);

/*----------------------------------------------------------------------------*/
/*---- Parsing ---------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- cmds_managements ------------------------------------------------------*/

/*---- path_utils.c ----*/
char			**get_paths(char **env);

/*---- strings_manage.c ----*/
void			strings_management(t_data *data, \
								t_string_token *lst_of_tok, char **env);

/*---- strings_utils.c ----*/
t_builtin		is_builtin(char *string);
t_return_status	builtin_switch(t_cmd command, char **av, char ***env_pt);
t_return_status	builtin_switch_free(t_cmd command, char **av, char ***env_pt);
bool			is_path(char *line);

/*---- files_managements -----------------------------------------------------*/

/*---- files_prepare.c ----*/
void			check_opened_infiles(t_data *data, int block_id);
void			check_opened_outfiles(t_data *data, int block_id);
bool			file_is_empty(char *file);
t_return_status	redirection_syntax_error(char *str);
bool			redir_failed(t_cmd *cmd);

/*---- heredoc_prepare.c ----*/
t_return_status	check_closing_par(t_string_token *string_token_lst);
void			get_heredoc_setup(t_data *data);
t_return_status	set_up_get_here_doc(t_string_token *token, char **limiter, \
										bool *do_expand, int *fd_hd);
void			keep_going(int *i, t_string_token **temp, t_data *data);
void			trim_limiter(char *s);

/*---- set_files.c ----*/
t_return_status	files_management(t_data *data, t_string_token *lst_of_tok, \
									char **env);
t_return_status	set_infile(t_data *data, char **file, int block_id, \
									char **env);
t_return_status	set_heredoc(t_data *data, char **hr_data, int block_id, \
									char **env);								
t_return_status	set_outfile(t_data *data, char **file, int block_id, \
									char **env);
t_return_status	set_appends(t_data *data, char **file, int block_id, \
										char **env);		

/*---- set_heredoc.c ----*/
t_return_status	heredoc_management(t_data *data, \
								t_string_token *string_token_lst, char **env);
t_return_status	read_fd_in_str(int fd, char **dst);

/*---- utils.c ----*/
void			false_space_to_space(char *str);
void			manage_ambiguous(t_cmd *cmd, char *file);
t_return_status	expand_hd(char **here_doc, char **env);
bool			read_hd_ep(char *line, int nb_of_line, char *limiter);
bool			redir_failed(t_cmd *cmd);

/*---- utils -----------------------------------------------------------------*/
/*---- clean_utils.c ----*/
void			clean_files_token(t_string_token *lst_of_tok);
void			clean_token(t_string_token *lst_of_tok);
t_return_status	fork_heredoc_error_process(int *fd_hd, char *limiter);

/*----------------------------------------------------------------------------*/
/*---- Signals ---------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- signals_utils.c ----*/
char			*update_prompt(char *prompt);
char			*get_color(void);

/*---- signals.c ----*/
void			init_signals(t_data *data);
void			handle_signal_heredoc(int signal);
void			handle_signal_child(int signo);
void			handle_signal_parent(int signo);

/*----------------------------------------------------------------------------*/
/*---- Syntax ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*---- check_par_err.c ----*/
void			check_par_err(t_string_token *str_tok_lst);

/*---- check_unic_syntax.c ----*/
void			update_tokens(t_string_token *str_tok_lst);
bool			update_to_filename(t_string_token **tmp);
bool			update_to_hr_data(t_string_token **tmp);
bool			dn_ut(t_string_token **tmp);

/*---- syntax_is_valid.c ----*/
t_return_status	syntax_is_valid(t_string_token *lst_to_check);
bool			is_a_meta(t_emt token);
bool			is_a_redir(t_emt token);

/*----------------------------------------------------------------------------*/
/*---- Token_list_utils ------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*---- str_token_debug.c ----*/
void			display_str_token(t_string_token *tok);
void			display_t_emt_string(t_string_token *token);
void			display_str_token_till(t_string_token *tok);
void			display_str_par(t_string_token *tok);

/*---- str_token_utils.c ----*/
int				next_control_operator_is_a_pipe(t_string_token *tok);
char			*format_string_token(t_string_token *token);

/*---- t_string_token_utils.c ----*/
void			cpy_token_lst_to_str(t_token *tok, char *str);
t_return_status	string_token_new_on(void *content, t_emt emt, \
									t_string_token **str_token_pt);
t_return_status	str_arr_to_str_token_lst(char **split, \
									t_string_token **str_token_pt);
/*---- t_string_token_cleans.c ----*/
void			string_token_destructor(t_string_token *trash);
void			del_next_string_token(t_string_token *tok);
void			del_space_token(t_string_token *tok);
void			del_empty_tokens(t_string_token *token_lst);
void			free_all_str(t_data *data);

/*---- t_string_token_create.c ----*/
t_string_token	*string_token_creator(void);
t_return_status	string_token_creator_on(t_string_token **tok_pt);

/*---- token_lst_constructor.c ----*/
t_token			*token_lst_constructor(char *str);

/*---- token_to_str_token.c ----*/
t_string_token	*token_lst_to_str_token(t_token *tok);

#endif