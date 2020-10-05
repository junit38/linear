#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmery <jmery@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 15:56:49 by jmery             #+#    #+#              #
#    Updated: 2014/01/19 19:26:04 by jmery            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIB = srcs

FLAG = -Wall -Wextra -Werror

SRCS_PREDICT = 	$(LIB)/data.c \
				$(LIB)/get_next_line.c \
				$(LIB)/predict.c \
				$(LIB)/price.c

SRCS_TRAINER = 	$(LIB)/data.c \
				$(LIB)/get_next_line.c \
				$(LIB)/maths.c \
				$(LIB)/normalize.c \
				$(LIB)/model.c \
				$(LIB)/price.c \
				$(LIB)/set.c \
				$(LIB)/tools.c \
				$(LIB)/trainer.c \
				$(LIB)/training.c

SRCS_PRESCISION = $(LIB)/data.c \
				$(LIB)/get_next_line.c \
				$(LIB)/prescision.c \
				$(LIB)/price.c \
				$(LIB)/tools.c

OBJS_PREDICT = $(SRCS_PREDICT:.c=.o)

OBJS_TRAINER = $(SRCS_TRAINER:.c=.o)

OBJS_PRESCISION = $(SRCS_PRESCISION:.c=.o)

all: ft_predict ft_trainer ft_prescision

ft_predict: $(OBJS_PREDICT)
	make -C libft/
	gcc $(FLAG) -o ft_predict $(OBJS_PREDICT) -L. libft/libft.a

ft_trainer: $(OBJS_TRAINER)
	make -C libft/
	gcc $(FLAG) -o ft_trainer $(OBJS_TRAINER) -L. libft/libft.a

ft_prescision: $(OBJS_PRESCISION)
	make -C libft/
	gcc $(FLAG) -o ft_prescision $(OBJS_PRESCISION) -L. libft/libft.a

%.o: %.c
	gcc $(FLAG) -c $< -o $@ -I includes

clean:
	make clean -C libft/
	rm -f $(OBJS_PREDICT)
	rm -f $(OBJS_TRAINER)
	rm -f $(OBJS_PRESCISION)

fclean: clean
	rm -f ./libft/libft.a
	rm -f ft_predict
	rm -f ft_trainer
	rm -f ft_prescision

re: fclean all

