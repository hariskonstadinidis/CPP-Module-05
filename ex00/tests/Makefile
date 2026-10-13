NAME = test_bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -g -std=c++11

BUILD_DIR = build

SRC = $(wildcard *.cpp) $(filter-out ../main.cpp,$(wildcard ../*.cpp))
OBJ = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRC)))
DEP = $(OBJ:.o=.d)

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)✓ $(NAME)$(RESET)\n"

$(BUILD_DIR)/%.o: %.cpp Makefile | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -I.. -c $< -o $@

$(BUILD_DIR)/%.o: ../%.cpp Makefile | $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -I.. -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

test: $(NAME)
	./$(NAME)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re test