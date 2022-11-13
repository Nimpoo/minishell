/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:04:03 by noalexan          #+#    #+#             */
/*   Updated: 2022/11/13 19:50:33 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envv)
{
	t_env	*env;

	((void) argc, (void) argv, (void) envv);
	env = ft_create_env(envv);
	ft_minishell(ft_makeprompt(PROMPT, env), env);
	system("leaks minishell");
	return (0);
}
