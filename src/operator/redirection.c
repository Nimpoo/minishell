/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:56 by Keyblade          #+#    #+#             */
/*   Updated: 2022/12/06 16:28:13 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_parse_redirecion(t_token *t, int s_q, int d_q, int j)
{
	int	i;

	if (t)
	{
		while (t->content[++j])
		{
			if (t->content[j] == '\'' && !d_q)
				s_q = 1 - s_q;
			else if (t->content[j] == '\"' && !s_q)
				d_q = 1 - d_q;
			if (!d_q && !s_q && (t->content[j] == '>' || t->content[j] == '<'))
			{
				i = 1;
				if (j)
					i = j;
				if (!j && t->content[j + 1] == t->content[j])
					i++;
				if (t->content[j + 1])
					(ft_insert_token(t, ft_lstnew(t->content + i)),
						ft_replace_seg(t, "",
							(int []){i, ft_strlen(t->content) - i, 0}));
			}
		}
		ft_parse_redirecion(t->next, FALSE, FALSE, -1);
	}
}

// 0644

void	ft_init_redirection(t_input *s, t_token *t)
{
	if (t)
	{
		if (!ft_strcmp(t->content, ">"))
		{
			printf("mode: outfile\n");
		}
		else if (!ft_strcmp(t->content, ">>"))
		{
			printf("mode: outfile append\n");
		}
		else if (!ft_strcmp(t->content, "<"))
		{
			printf("mode: infile\n");
		}
		else if (!ft_strcmp(t->content, "<<"))
		{
			printf("mode: heredoc\n");
		}
		if (t->next)
		{
			if (!ft_is_a_valid_filename(t->next->content))
				printf("error\n");
			else
				printf("file: '%s'\n", t->next->content);
		}
		ft_init_redirection(s, t->next);
	}
}

void	ft_pipe_redirection(t_input *s)
{
	int	pipe_fd[2];

	if (s->next)
	{
		pipe(pipe_fd);
		s->out = pipe_fd[1];
		s->next->in = pipe_fd[0];
	}
}

void	ft_redirection(t_input *s)
{
	if (s)
	{
		ft_parse_redirecion(s->token, FALSE, FALSE, -1);
		ft_init_redirection(s, s->token);
		ft_pipe_redirection(s);
		printf("\e[1;34m[DEBUG]\e[0m: \e[1;36m[redirection]: in = '%d', out = '%d'\e[0m\n", s->in, s->out);
		ft_redirection(s->next);
	}
}
