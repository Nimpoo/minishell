/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:43:55 by tle               #+#    #+#             */
/*   Updated: 2022/11/25 00:32:25 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

typedef struct s_getstr
{
	char	*line;
	int		size;
}		t_getstr;

int	ft_quote(char *character, int value)
{
	*character = -1;
	return (value);
}

void	ft_new_token(t_token **token, char *content)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	new->content = ft_strdup(content);
	new->next = NULL;
	printf("\e[34;1m[DEBUG]\e[0m: \e[1;32m[lexer]: New token: \"%s\"\e[0m\n", content);
	ft_lstadd_back(token, new);
}

t_getstr	ft_getstr(char **l, int i)
{
	t_getstr	a;
	int			s_q;
	int			d_q;

	s_q = FALSE;
	d_q = FALSE;
	a.size = -1;
	while ((*l)[++a.size + i] && (s_q || d_q || !ft_isspace((*l)[a.size + i])))
	{
		if ((*l)[a.size + i] == '\'' && !s_q && !d_q)
			s_q = TRUE;
		else if ((*l)[a.size + i] == '\'' && s_q && !d_q)
			s_q = FALSE;
		else if ((*l)[a.size + i] == '\"' && !d_q && !s_q)
			d_q = TRUE;
		else if ((*l)[a.size + i] == '\"' && d_q && !s_q)
			d_q = FALSE;
		else if ((*l)[a.size + i] == '$' && !s_q)
			(*l) = ft_strdup_and_free(ft_variable(l, a.size + i));
	}
	if (s_q || d_q)
		g_minishell.exitcode = 258;
	a.line = ft_calloc(a.size + 1, sizeof(char));
	ft_strlcpy(a.line, *l + i, a.size);
	return (a);
}

t_token	*ft_generate_token(char **line, int i)
{
	t_token		*token;
	t_getstr	getstr;

	token = NULL;
	if ((*line) && (*line)[i])
	{
		i += ft_skip_space((*line), i);
		if ((*line)[i])
		{
			getstr = ft_getstr(line, i);
			ft_new_token(&token, getstr.line);
			free(getstr.line);
			token->next = ft_generate_token(line, i + getstr.size);
		}
	}
	return (token);
}

t_token	*ft_lexer(char **line)
{
	t_token	*token;
	int		i;

	token = NULL;
	if ((*line) && (*line)[0])
	{
		ft_addhistory(*line);
		i = ft_skip_space((*line), 0);
		if ((*line)[i])
		{
			printf("\e[34;1m[DEBUG]\e[0m: line\t  -> \"%s\"\n", (*line));
			token = ft_generate_token(line, i);
		}
	}
	if (g_minishell.exitcode == 258)
	{
		ft_printf(2, "\e[31;1m[minishell]: Error syntax\n\e[0m");
		ft_lstclear(token);
		return (NULL);
	}
	return (token);
}
