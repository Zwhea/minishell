# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wangthea <wangthea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 14:25:51 by twang             #+#    #+#              #
#    Updated: 2023/05/22 17:12:48 by bpoumeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =																	\
			sources/builtins/env_utils/env_utils.c							\
			sources/builtins/env_utils/get_in_env.c							\
			sources/builtins/env_utils/ordering_env_export.c				\
			sources/builtins/utils/export_get_ft_to_do.c					\
			sources/builtins/cd.c											\
			sources/builtins/echo.c											\
			sources/builtins/env.c											\
			sources/builtins/exit.c											\
			sources/builtins/exit_the_programme.c							\
			sources/builtins/export.c										\
			sources/builtins/pwd.c											\
			sources/builtins/unset.c										\
			sources/execution_settings/expands/cut_line_utils.c				\
			sources/execution_settings/expands/cut_line.c					\
			sources/execution_settings/expands/expands_utils.c				\
			sources/execution_settings/expands/expands.c					\
			sources/execution_settings/expands/join_expands.c				\
			sources/execution_settings/expands/replace_dollar_str_by_env_value.c\
			sources/execution_settings/expands/replace_dquotes_str_by_env_value.c\
			sources/execution_settings/subshell/subshell_preparation.c		\
			sources/execution_settings/switchmans/switchman_once.c			\
			sources/execution_settings/switchmans/switchman_utils.c			\
			sources/execution_settings/switchmans/switchman.c				\
			sources/execution_settings/wildcards/files_wildcards.c			\
			sources/execution_settings/wildcards/wildcards_utils.c			\
			sources/execution_settings/wildcards/utils.c					\
			sources/execution_settings/wildcards/wildcards.c				\
			sources/execution_settings/env_init.c							\
			sources/execve/childs.c											\
			sources/execve/exec_articulation_utils.c						\
			sources/execve/exec_articulation.c								\
			sources/execve/executions.c										\
			sources/execve/fds_manage.c										\
			sources/execve/pipes_manage.c									\
			sources/execve/utils.c											\
			sources/lexing/1_preservation/double_quoting.c					\
			sources/lexing/1_preservation/preserv.c							\
			sources/lexing/1_preservation/simple_quoting.c					\
			sources/lexing/2_metachar_managing/split_toklst_on_meta.c		\
			sources/lexing/lexing_token_utils/simple_tokens_utils.c			\
			sources/lexing/lexing_token_utils/token_lst_utils_2.c			\
			sources/lexing/lexing_token_utils/token_lst_utils.c				\
			sources/lexing/lexing_articulation.c							\
			sources/main/prompt/prompt_utils.c								\
			sources/main/prompt/prompt.c									\
			sources/main/utils/check_arguments.c							\
			sources/main/utils/display.c									\
			sources/main/utils/return_to_root.c								\
			sources/main/utils/utils.c										\
			sources/main/main.c												\
			sources/parsing/cmds_management/path_utils.c					\
			sources/parsing/cmds_management/strings_manage.c				\
			sources/parsing/cmds_management/strings_utils.c					\
			sources/parsing/files_management/files_prepare.c				\
			sources/parsing/files_management/heredoc_prepare.c				\
			sources/parsing/files_management/set_files.c					\
			sources/parsing/files_management/set_heredoc.c					\
			sources/parsing/files_management/utils.c						\
			sources/parsing/utils/clean_utils.c								\
			sources/signals/signals_utils.c									\
			sources/signals/signals.c										\
			sources/syntax/check_par_err.c									\
			sources/syntax/check_unic_syntax.c								\
			sources/token_list_utils/str_token_utils.c						\
			sources/token_list_utils/t_string_token_utils.c					\
			sources/token_list_utils/t_string_token_cleans.c				\
			sources/token_list_utils/t_string_token_create.c				\
			sources/token_list_utils/t_string_token_utils.c					\
			sources/token_list_utils/token_lst_constructor.c				\
			sources/token_list_utils/token_to_str_token.c					\
			
