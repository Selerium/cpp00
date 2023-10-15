# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jadithya <jadithya@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 18:23:29 by jadithya          #+#    #+#              #
#    Updated: 2023/10/15 18:33:52 by jadithya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS := ${shell uname}

CC := c++

NAME := megaphone

CFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := megaphone.cpp

OBJS := $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@echo "Mandatory:"
	@python3 -m norminette

.PHONY: all bonus clean fclean re norm