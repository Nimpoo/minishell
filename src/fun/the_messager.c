/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_messager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayoub <mayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:05:58 by mayoub            #+#    #+#             */
/*   Updated: 2022/12/01 11:10:25 by mayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	the_heredoc_donjon(void)
{
	printf("\
   ▄████████ ███▄▄▄▄       ███        ▄████████    ▄████████  ▄█  ███▄▄▄▄      ▄██████▄           ███        ▄█    █▄       ▄████████     \n\
  ███    ███ ███▀▀▀██▄ ▀█████████▄   ███    ███   ███    ███ ███  ███▀▀▀██▄   ███    ███      ▀█████████▄   ███    ███     ███    ███     \n\
  ███    █▀  ███   ███    ▀███▀▀██   ███    █▀    ███    ███ ███▌ ███   ███   ███    █▀          ▀███▀▀██   ███    ███     ███    █▀      \n\
 ▄███▄▄▄     ███   ███     ███   ▀  ▄███▄▄▄      ▄███▄▄▄▄██▀ ███▌ ███   ███  ▄███                 ███   ▀  ▄███▄▄▄▄███▄▄  ▄███▄▄▄         \n\
▀▀███▀▀▀     ███   ███     ███     ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ███▌ ███   ███ ▀▀███ ████▄           ███     ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀         \n\
  ███    █▄  ███   ███     ███       ███    █▄  ▀███████████ ███  ███   ███   ███    ███          ███       ███    ███     ███    █▄      \n\
  ███    ███ ███   ███     ███       ███    ███   ███    ███ ███  ███   ███   ███    ███          ███       ███    ███     ███    ███     \n\
  ██████████  ▀█   █▀     ▄████▀     ██████████   ███    ███ █▀    ▀█   █▀    ████████▀          ▄████▀     ███    █▀      ██████████     \n\
                                                  ███    ███                                                                              \n\
   ▄█    █▄       ▄████████    ▄████████    ▄████████ ████████▄   ▄██████▄   ▄████████       ▄███████▄   ▄██████▄  ███▄▄▄▄      ▄████████ \n\
  ███    ███     ███    ███   ███    ███   ███    ███ ███   ▀███ ███    ███ ███    ███      ██▀     ▄██ ███    ███ ███▀▀▀██▄   ███    ███ \n\
  ███    ███     ███    █▀    ███    ███   ███    █▀  ███    ███ ███    ███ ███    █▀             ▄███▀ ███    ███ ███   ███   ███    █▀  \n\
 ▄███▄▄▄▄███▄▄  ▄███▄▄▄      ▄███▄▄▄▄██▀  ▄███▄▄▄     ███    ███ ███    ███ ███              ▀█▀▄███▀▄▄ ███    ███ ███   ███  ▄███▄▄▄     \n\
▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ▀▀███▀▀▀     ███    ███ ███    ███ ███               ▄███▀   ▀ ███    ███ ███   ███ ▀▀███▀▀▀     \n\
  ███    ███     ███    █▄  ▀███████████   ███    █▄  ███    ███ ███    ███ ███    █▄       ▄███▀       ███    ███ ███   ███   ███    █▄  \n\
  ███    ███     ███    ███   ███    ███   ███    ███ ███   ▄███ ███    ███ ███    ███      ███▄     ▄█ ███    ███ ███   ███   ███    ███ \n\
  ███    █▀      ██████████   ███    ███   ██████████ ████████▀   ▀██████▀  ████████▀        ▀████████▀  ▀██████▀   ▀█   █▀    ██████████ \n\
                              ███    ███                                                                                                  \n\
    ███        ▄████████    ▄█   ▄█▄    ▄████████       ▄████████    ▄████████    ▄████████    ▄████████                                  \n\
▀█████████▄   ███    ███   ███ ▄███▀   ███    ███      ███    ███   ███    ███   ███    ███   ███    ███                                  \n\
   ▀███▀▀██   ███    ███   ███▐██▀     ███    █▀       ███    █▀    ███    ███   ███    ███   ███    █▀                                   \n\
    ███   ▀   ███    ███  ▄█████▀     ▄███▄▄▄          ███          ███    ███  ▄███▄▄▄▄██▀  ▄███▄▄▄                                      \n\
    ███     ▀███████████ ▀▀█████▄    ▀▀███▀▀▀          ███        ▀███████████ ▀▀███▀▀▀▀▀   ▀▀███▀▀▀                                      \n\
    ███       ███    ███   ███▐██▄     ███    █▄       ███    █▄    ███    ███ ▀███████████   ███    █▄                                   \n\
    ███       ███    ███   ███ ▀███▄   ███    ███      ███    ███   ███    ███   ███    ███   ███    ███                                  \n\
   ▄████▀     ███    █▀    ███   ▀█▀   ██████████      ████████▀    ███    █▀    ███    ███   ██████████                                  \n\
                           ▀                                       \
              ███    ███                \
                                                                      ");
	printf("\n");
}
