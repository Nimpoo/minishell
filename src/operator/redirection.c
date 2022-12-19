/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:48:56 by Keyblade          #+#    #+#             */
/*   Updated: 2022/12/19 13:04:52 by mayoub           ###   ########.fr       */
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
				if (t->content[i + 1])
					(ft_insert_token(t, ft_lstnew(t->content + i)),
						ft_replace_seg(t, "",
							(int []){i, ft_strlen(t->content) - i, 0}));
			}
		}
		ft_parse_redirecion(t->next, FALSE, FALSE, -1);
	}
}

// t_token	*ft_expend_token_list(t_token *t); <- ca va avec l'expend tu peux supp les 3 lignes c'etait juste pour test

void	*ft_init_redirection(t_input *s, t_token *t)
{
	if (t)
	{
		if (t->content[0] == '>' || t->content[0] == '<')
		{
			if (!t->next)
				return (ft_error_redirection_nl());
			else if (t->next->content[0] == '>' || t->next->content[0] == '<')
				return (ft_error_redirection(t->next->content[0]));
			// if (ft_strcmp(t->content, "<<"))
			// 	ft_expend_token_list(t->next);  <- possible d'expend ici mais ca entraine des erreurs, il faut trouve le moyen d'expend QUE le prochain et non pas tout le reste
			if (t->content[0] == '>')
				ft_open_file(s, t);
			else if (t->content[0] == '<')
			{
				if (ft_init_redirection_utils(s, t) == 0)
					return (NULL);
			}
			else
				return (ft_init_redirection(s, t->next));
			ft_init_redirection(s, t->next->next);
		}
		ft_init_redirection(s, t->next);
	}
	return (NULL);
}

void	ft_pipe_redirection(t_input *s)
{
	int	pipe_fd[2];

	if (s->next)
	{
		pipe(pipe_fd);
		if (s->out == STDOUT)
			s->out = pipe_fd[IN];
		else
			close(pipe_fd[IN]);
		if (s->next->in == STDIN)
			s->next->in = pipe_fd[OUT];
		else
			close(pipe_fd[OUT]);
	}
}

t_token	*ft_clear_tokens(t_token *t)
{
	t_token	*tmp;

	if (t && g_minishell.input)
	{
		if (t->content[0] == '<' || t->content[0] == '>')
		{
			tmp = t->next->next;
			t->next->next = NULL;
			ft_lstclear(t);
			t = ft_clear_tokens(tmp);
		}
		else
			t->next = ft_clear_tokens(t->next);
	}
	return (t);
}

void	ft_redirection(t_input *s)
{
	if (s)
	{
		ft_parse_redirecion(s->token, FALSE, FALSE, -1);
		ft_init_redirection(s, s->token);
		s->token = ft_clear_tokens(s->token);
		ft_pipe_redirection(s);
		if (s->in < 0 || s->out < 0)
			return ((void) ft_error_fd());
		printf("\e[1;34m[DEBUG]\e[0m: \e[1;36m[redirection]: in = '%d', out = '%d'\e[0m\n", s->in, s->out);
		ft_redirection(s->next);
	}
}
