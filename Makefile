				
########################################################################
####################### My Makefile ##############################
########################################################################

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror
 

# Makefile settings
NAME = push_swap
NAME2 = mychecker			
PUSHSRC = tools/linkedlist.c tools/moves1.c tools/push_swap_tools.c tools/push_swap_tools2.c tools/moves2.c\
tools/quick_sort.c split/ft_splite.c split/ft_substr.c split/ft_strjoin.c split/ft_atoi.c push_swap.c checknbr.c

PUSHSRC2 = tools/linkedlist.c tools/moves1.c tools/push_swap_tools.c tools/push_swap_tools2.c tools/moves2.c\
tools/quick_sort.c split/ft_splite.c split/ft_substr.c  split/ft_atoi.c \
checkertools/get_next_line.c checkertools/checker.c checkertools/chtools.c tools/move3.c checknbr.c

HEADER = pushswap.h


############## The referencing #############

PUSHOBJ = ${PUSHSRC:.c=.o}

PUSHOBJ2 = ${PUSHSRC2:.c=.o}
# UNIX-based OS variables & settings

RM = rm -rf

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(NAME)


# Builds the app

$(NAME)  : $(PUSHOBJ) $(HEADER)
	$(CC) $(CFLAGS) $(PUSHOBJ) -I $(HEADER) -o $(NAME)

bonus: $(NAME2)

$(NAME2)  : $(PUSHOBJ2) $(HEADER)
	$(CC) $(CFLAGS) $(PUSHOBJ2) -I $(HEADER) -o $(NAME2)
# Building rule for .o files and its .c


################### Cleaning rules for Unix-based OS ###################

clean:
			$(RM) $(PUSHOBJ) $(PUSHOBJ2)

fclean:		clean
			$(RM) $(NAME) $(NAME2)

re:			fclean all

.PHONY:		all clean fclean re 