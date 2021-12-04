NAME =	libftprintf.a

INC = ft_printf.h

SRCS = ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c	 ft_printf1.c ft_printf2.c ft_printf.c	
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

AR = ar -rsc


all: $(NAME)

$(NAME):$(OBJS) $(INC)
	$(AR) $(NAME) $(OBJS)                                       

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) 

fclean:clean
	$(RM) $(NAME)

re: fclean all
