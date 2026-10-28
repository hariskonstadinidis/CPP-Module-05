NAME = 	bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -g

BUILD_DIR = build

SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:.o=.d)

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)✓ $(NAME)$(RESET)\n"

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "$(GREEN)✓ $<$(RESET)\n"
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re