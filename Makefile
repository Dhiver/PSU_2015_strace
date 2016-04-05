##
## Makefile for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace
## 
## Made by Bastien DHIVER
## Login   <dhiver_b@epitech.net>
## 
## Started on  Thu Mar 31 13:20:36 2016 Bastien DHIVER
## Last update Tue Apr  5 14:42:32 2016 florian videau
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -pedantic -std=c99 -D_GNU_SOURCE
CFLAGS	+= -I$(INCF)

NAME	= strace

SRCF	= src/

INCF	= include/

SRCS	= $(SRCF)strace.c		\
	  $(SRCF)utils.c		\
	  $(SRCF)trace.c		\
	  $(SRCF)signals.c		\
	  $(SRCF)printing.c		\
	  $(SRCF)find_executable.c

OBJS	= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
