/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:47:27 by twang             #+#    #+#             */
/*   Updated: 2023/05/17 10:50:40 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

/*---- typedef enums ---------------------------------------------------------*/

typedef enum e_builtin			t_builtin;
typedef enum e_secured			t_esec;
typedef enum e_token_minishell	t_emt;
typedef enum e_enum_op			t_e_op;
typedef enum e_par_stat			t_pr_stat;

/*---- enums -----------------------------------------------------------------*/

enum	e_token_minishell
{
	START = 0,
	PIPE = 1,
	AMPERSAND = 2,
	CHEVRON_IN = 3,
	CHEVRON_OT = 4,
	OR = 5,
	AND = 6,
	HERE_DOC = 7,
	APPENDS = 8,
	O_PRTSS = 9,
	C_PRTSS = 10,
	SEMICOLON = 11,
	E_SPACE = 12,
	TABULATION = 13,
	LETTER = 14,
	EOL = 15,
	STRING = 16,
	DOLLAR = 17,
	FILE_NAME = 18,
	HR_DATA = 19,
	SYN_ERR = 20,
	NONE = 21
};

enum e_builtin
{
	CMD,
	ENV,
	ECHO_,
	EXPORT,
	PWD,
	EXIT,
	UNSET,
	CD,
	EMPTY,
	SUBSHELL
};

enum e_secured
{
	SECURED,
	UNSECURED
};

enum e_enum_op
{
	AND_OP = 1,
	OR_OP = 2,
	UNRESOLVED = 3,
	RESOLVED = 4
};

enum e_par_stat
{
	NO_PAR,
	IN_PAR,
	OT_PAR
};

#endif