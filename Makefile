				
########################################################################
####################### My Makefile ##############################
########################################################################

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror
 

# Makefile settings
NAME = push_swap			
PUSHSRC = tools/linkedlist.c tools/moves1.c tools/push_swap_tools.c tools/push_swap_tools2.c tools/moves2.c\
tools/three.c split/ft_splite.c split/ft_substr.c split/ft_strjoin.c split/ft_atoi.c push_swap.c 
HEADER = pushswap.h


############## The referencing #############

PUSHOBJ = ${PUSHSRC:.c=.o}


# UNIX-based OS variables & settings

RM = rm -rf

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(NAME)


# Builds the app

$(NAME)  : $(PUSHOBJ) $(HEADER)
	$(CC) $(CFLAGS) $(PUSHOBJ) -I $(HEADER) -o $(NAME)


# Building rule for .o files and its .c


################### Cleaning rules for Unix-based OS ###################

clean:
			$(RM) $(PUSHOBJ)

fclean:		clean
			$(RM) push_swap 

re:			fclean all

.PHONY:		all clean fclean re 