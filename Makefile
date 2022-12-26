NAME = pushswap.a
CC = cc
CFLAGS =-Wall -Wextra -Werror
AR = ar -rc
LIBFT_H = pushswap.h
FILES = linkedlist.c\
		SaSbPaPb.c\
				
OBJS =$(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $@ $^

%.o :%.c $(LIBFT_H)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(OBJS_BOUNUS)

fclean: clean
	rm -f $(NAME)
	
re: clean all