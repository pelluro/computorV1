# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mipham <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 14:27:12 by mipham            #+#    #+#              #
#    Updated: 2019/05/07 14:27:16 by mipham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = computor

_GREEN = $'\x1b[32m
_CYAN = $'\x1b[36m
_RED = $'\x1b[31m
_YELLOW = $'\x1b[33m
_PURPLE = $'\x1b[35m
_BLUE = $'\x1b[34m


CXX := clang++
CXXFLAGS := -std=c++98

incfiles := functions.h
srcfiles := functions.cpp Monome.cpp Polynome.cpp main.cpp
objects  := $(subst .cpp,.o, $(srcfiles))

all: $(NAME)

$(NAME): $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o $(NAME)
	@echo "${_BLUE}computor generate${_END} ${_PURPLE}[!${_END}]"

%.o: %.cpp $(incfiles)
	$(CXX) $(CXXFLAGS) -I ./  -o $@ -c $<

clean:
	rm -f $(objects)
	@echo "${_CYAN}cleaning objects files${_END} ${_PURPLE}[!${_END}]"

fclean: clean
	rm -f $(NAME)
	@echo "${_RED}delete $(NAME) ${_END}${_GREEN}[!${_END}]"

re: fclean all

.PHONY : all, re, clean, fclean
