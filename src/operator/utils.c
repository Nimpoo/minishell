/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:37:50 by Tropico 🦜        #+#    #+#             */
/*   Updated: 2022/12/20 08:25:28 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_close_all(t_input *s)
{
	if (s)
	{
		if (s->in != STDIN)
			close(s->in);
		if (s->out != STDOUT)
			close(s->out);
		ft_close_all(s->next);
	}
}

void	ft_wait_all(t_input *s)
{
	char	*a;
	int		i;

	if (s && s->token)
	{
		a = s->token->content;
		(wait(&i), ft_wait_all(s->next));
		if (ft_strcmp(a, "cd"))
			g_minishell.exitcode = i / 256;
	}
}

void	ft_open_file(t_input *s, t_token *t)
{
	if (s->out != STDOUT)
		close(s->out);
	if (t->content[1] == '>')
		s->out = open(t->next->content,
				O_CREAT | O_WRONLY | O_APPEND, 0600);
	else
		s->out = open(t->next->content,
				O_CREAT | O_WRONLY | O_TRUNC, 0600);
}

int	ft_init_redirection_utils(t_input *s, t_token *t)
{
	if (s->in != STDIN)
		close(s->in);
	if (t->content[1] == '<')
		s->in = ft_heredoc(t->next->content);
	else
	{
		if (!access(t->next->content, 0400))
			s->in = open(t->next->content, 0400);
		else
		{
			error_not_a_directory("minishell", s->token->next->content, 3);
			(ft_clear(g_minishell.input), g_minishell.input = NULL);
			return (0);
		}
	}
	return (1);
}
