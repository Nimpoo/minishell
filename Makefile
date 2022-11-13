# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 13:22:13 by Palmi             #+#    #+#              #
#    Updated: 2022/11/13 17:47:25 by noalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation variables
CC		:= gcc
FLAGS	:= -Lvendor/readline/lib -lreadline
CFLAGS	:= -Werror -Wextra -Wall 

# Name of the final executable
NAME	:= minishell

# All needed files
SRC		:=	src/env.c \
			src/main.c \

OBJ		:= $(SRC:.c=.o)

# All needed library
LIB		:=	src/libft/libft.a \
			src/printf/printf.a \

# Colors for differents prints
GREEN	:= "\033[0m\033[1;32m"
CYAN	:= "\033[0m\033[1;36m"
YELLOW	:= "\033[0m\033[1;33m\033[3;33m"
RESET	:= "\033[0m"

# Compile all .c files
.c.o: $(SRC)
	@printf $(GREEN)"\r\033[KCompiling objects... "$(YELLOW)"<$<> ⏳ "$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# Compile all .o files
$(NAME): $(OBJ)
	@printf $(GREEN)"\r\033[KObjects compiled succesfully ✅\n"$(RESET)
	@make -C src/libft
	@make -C src/printf
	@printf $(CYAN)"\r\033[KCompiling '$(NAME)'... ⏳"$(RESET)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -I include/ -o $(NAME)
	@printf $(GREEN)"\r\033[KSuccess compiling '$(NAME)' ✅\n"$(RESET)
	@printf "\n"
	@printf "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗\n"
	@printf "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║\n"
	@printf "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║\n"
	@printf "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║\n"
	@printf "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n"
	@printf "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"
	@printf "\n"
	@printf "██████╗  ██████╗ ██╗     ███╗   ██╗ █████╗ ██████╗ ███████╗███████╗███████╗\n"
	@printf "██╔══██╗██╔═══██╗██║     ████╗  ██║██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝\n"
	@printf "██████╔╝██║   ██║██║     ██╔██╗ ██║███████║██████╔╝█████╗  █████╗  █████╗\n"
	@printf "██╔═══╝ ██║   ██║██║     ██║╚██╗██║██╔══██║██╔══██╗██╔══╝  ██╔══╝  ██╔══╝\n"
	@printf "██║     ╚██████╔╝███████╗██║ ╚████║██║  ██║██║  ██║███████╗██║     ██║\n"
	@printf "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝\n"
	@printf "\n"

# Default command to launch
all: libs $(NAME)

# Compile and run minishell
run: all
	@./$(NAME)

# Vendor
vendor:
	@mkdir vendor

# Readline
vendor/readline: vendor
	@printf $(CYAN)"\r\033[KInstallation of readline... ⏳\n"$(RESET)
	@sh install_readline.sh
	@printf $(GREEN)"Readline installed ✅\n"$(RESET)

readline: vendor/readline

# Library necessary to compile
libs: readline

# Print our god
polnareff:
	@echo ""
	@echo "                            . ...**/##/***.,,*,                                 "
	@echo "                        ,.****//(#(#.###%((//(###(*/*(/*                        "
	@echo "                  .,.,,.*/((#%#(&((%%/*&&&#(//(/(##//(//((                      "
	@echo "                ,,,,.,,*//#/%###%#%(#(%&&/(##((##/*#(/**((((*                   "
	@echo "               .,,.*,*/,*/%(#&##%(/(%%(((#(#((//////(/(/*(//(//                 "
	@echo "              .,.,.,/..//,,/,/#%((#(**//////#((///(/*#//,/(//////               "
	@echo "            ,....,,*/.,.*/(#*/%#(//*(*///(/(#/#*(%,/,/#(/**/*/((/*.             "
	@echo "            .....,,*,**,*((*/,#((/(,*,,*/.(**(/,///////(((#(*(./(/(/            "
	@echo "           ...,,*,.,././//////,///*/*/,,,,..,*,*//(((,/##/(//*/,(#(**.          "
	@echo "           ...,*,,,,/**(/,.,*(*/,**.,**,.,****,,*/***,**((##(##*(*//*/          "
	@echo "          ..,...,.***/*,,..*,***,*,,.,,,.*,*/*,*,,*/*,****/*/#(*(///,,,         "
	@echo "         .,..,/.,*,**/,/,*/,***,*/,*,.,,.,..,,.****/,*******///*/(**//**        "
	@echo "          .,,,,*,(/*,//*****/*,,*******//*,**//**,**(/,***/(*,*((***/*,**.      "
	@echo "          ,.*.**,*((*,((#((/(##//////(#%%*. ./(#%###(...*,**((#,***,*****       "
	@echo "          ,,..//(/,,,,,**,.  .*(&&*...*&&&@@@@&@@&&&&.,*%/*/((//**(/////*,      "
	@echo "       .....,,*/***#@@@@@@@@@&%,,.....%#&@@&&@&&&%&&@. (%//,***,,/*((,,**,.     "
	@echo "        .,.,,**/(#*,%&@@@@@@@&&% *,.,..%%%%%%%%%&&%(..,*(***///*.(*/*/,,,**     "
	@echo "         .,.,,.**#(.*(&&&&&&%%%&.*,.... .*(((*,   *#(,,,/****#//,,****.*,,.     "
	@echo "          ,..,,,**/(#* .*/(*. .//,,..,.../(#####(/*,,,,/****,**./(/,/**,,*      "
	@echo "            ,.,*,***(#%(#####%#%%/*,,*#*....,..,,,,,,,,//(/*/(/,.///****,,.     "
	@echo "            .,...,,/*((((##(//(#%%%%%*.,,,...,,,,,,,,,,*(&//(%/(*,(/******,.    "
	@echo "            ..,..,,,**/*(#((//(##((*,///*,,*/,,,,,,,,**/%(&%(//#////********.   "
	@echo "             .,,,,//**////(#(((#%%(/*,,,,,,,,,*******/((#%/%&/(*/**/////**,,    "
	@echo "               ..,,,,.*/*(#/(#(#((((////**,,,,,,***/#(//#&&%%(*,(,***,**/**//   "
	@echo "               .,..,,.,**(####(#(/*,,,,,.,.,,,,*((#(//*/(%#%/(/**//,,,,,*/*///(("
	@echo "               ...,..,,,*(((/#%#(((/*********((##(//****/(##(/*,/,,*,*,,*,//////"
	@echo "               ,,,,**,,*/(##(&%###%########%%##(/********/(/((/**,**,,**////(///"
	@echo "         .......*(**#**/*//((&&#(%%%%##%%%%##(//****,,***/(///*.,,,*,*((/(//((//"
	@echo "   ..........,,..,#%%##%&&%%&&&&(##@@&&%%%%%#((/****,,****/(/*,*,,,*#(((/((//(/("
	@echo ""

# Just a cute loading bar
load:
	@printf '\r █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 0%%\r'
	@sleep .01
	@printf '\r ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 5%%\r'
	@sleep .01
	@printf '\r ███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 10%%\r'
	@sleep .01
	@printf '\r ████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 15%%\r'
	@sleep .01
	@printf '\r █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 20%%\r'
	@sleep .01
	@printf '\r ██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 25%%\r'
	@sleep .01
	@printf '\r ███████▒▒▒▒▒▒▒▒▒▒▒▒▒▒ - 30%%\r'
	@sleep .01
	@printf '\r ████████▒▒▒▒▒▒▒▒▒▒▒▒▒ - 35%%\r'
	@sleep .01
	@printf '\r █████████▒▒▒▒▒▒▒▒▒▒▒▒ - 40%%\r'
	@sleep .01
	@printf '\r ██████████▒▒▒▒▒▒▒▒▒▒▒ - 45%%\r'
	@sleep .01
	@printf '\r ███████████▒▒▒▒▒▒▒▒▒▒ - 50%%\r'
	@sleep .01
	@printf '\r ████████████▒▒▒▒▒▒▒▒▒ - 55%%\r'
	@sleep .01
	@printf '\r █████████████▒▒▒▒▒▒▒▒ - 60%%\r'
	@sleep .01
	@printf '\r ██████████████▒▒▒▒▒▒▒ - 65%%\r'
	@sleep .01
	@printf '\r ███████████████▒▒▒▒▒▒ - 70%%\r'
	@sleep .01
	@printf '\r ████████████████▒▒▒▒▒ - 75%%\r'
	@sleep .01
	@printf '\r █████████████████▒▒▒▒ - 80%%\r'
	@sleep .01
	@printf '\r ██████████████████▒▒▒ - 85%%\r'
	@sleep .01
	@printf '\r ███████████████████▒▒ - 90%%\r'
	@sleep .01
	@printf '\r ████████████████████▒ - 95%%\r'
	@sleep .01
	@printf '\r █████████████████████ - 100%%\r'
	@sleep .08

# Clean all .o and .a files
clean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@rm -rdf $(OBJ)
	@make -C src/libft clean
	@make -C src/printf clean
	@printf $(GREEN)"\r\033[Kcleaned 🗑\n"$(RESET)

# Same as 'clean' but clean minishell too
fclean:
	@printf $(CYAN)"\r\033[KErasing objects... "$(RESET)"⏳ "
	@rm -rdf $(OBJ)
	@make -C src/libft fclean
	@make -C src/printf fclean
	@printf $(GREEN)"\r\033[KObjects cleaned 🗑\n"$(RESET)
	@printf $(CYAN)"\r\033[KErasing binary file... "$(RESET)"⏳ "
	@rm -rdf $(NAME) test_parser
	@printf $(GREEN)"\r\033[KBinary file cleaned 🗑\n"$(RESET)
	@printf $(GREEN)"\r\033[KForce cleaned 🗑\n"$(RESET)

# Clean readline
fclean_readline:
	@printf $(CYAN)"\r\033[KErasing readline... "$(RESET)"⏳ "
	@rm -rdf vendor
	@printf $(GREEN)"\r\033[KReadline cleaned 🗑\n"$(RESET)

# Clean all and recompile minishell
re: fclean all

.PHONY: all clean fclean re libs readline polnareff load fclean_readline run update
