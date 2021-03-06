# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sam <sam@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/02 15:16:50 by sam           #+#    #+#                  #
#    Updated: 2020/10/13 16:21:22 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers_tests
FILES = catchMain mapTest listTest vectorTest queueTest stackTest
SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(SRCS:.cpp=.o)

# Add the directories you need here:
INCLUDE = -I../srcs/list -I../srcs -I../srcs/vector -I../srcs/stack -I../srcs/queue -I../srcs/map

CXXFLAGS = -std=c++11

ifdef asan
 CXXFLAGS += -g -fsanitize=address -fno-omit-frame-pointer -O0
endif

ifeq ($(shell uname), Linux)
 ECHO = -e
endif

# Colours
DARK_GREEN	= \033[0;32m
GREEN		= \033[0;92m
END			= \033[0;0m

PREFIX		= $(DARK_GREEN)$(NAME) $(END)\xc2\xbb

all: $(NAME)

$(NAME): $(OBJS)
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)$(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) $(INCLUDE) -o $@

%.o: %.cpp
	@echo $(ECHO) "$(PREFIX)$(GREEN) Compiling file $(END)$< $(GREEN)to $(END)$@"
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

run: all
	./$(NAME)

clean:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing .o files $(END)$(OUT_DIR)"
	@rm -f $(OBJS)

fclean: clean
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing executable $(END)$(OUT_DIR)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
