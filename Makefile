## ## Makefile for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace
## 
## Made by Bastien DHIVER
## Login   <dhiver_b@epitech.net>
## 
## Started on  Thu Mar 31 13:20:36 2016 Bastien DHIVER
## Last update Sun Apr 10 21:40:43 2016 Bastien DHIVER
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -pedantic -std=c99
CFLAGS	+= -I$(INCF)

NAME	= strace

SRCF	= src/

INCF	= include/

SRCS	= $(SRCF)strace.c		\
	  $(SRCF)utils.c		\
	  $(SRCF)trace.c		\
	  $(SRCF)signals.c		\
	  $(SRCF)printing.c		\
	  $(SRCF)find_executable.c	\
	  $(SRCF)print_fct.c		\
	  $(SRCF)print_fct_again.c	\
	  $(SRCF)init_tabs.c		\
	  $(SRCF)print_signals.c	\
	  $(SRCF)print_strs.c		\
	  $(SRCF)print_execve.c

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
