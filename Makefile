NAME		:= helloWindow

CXX_C		:= c++
CXX_FLAGS	:= -Wall -Wextra -Werror

CC			:= gcc
C_FLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= src
BIN_DIR		:= bin
INC_DIR		:= include

GLAD_DIR	:= $(INC_DIR)/glad
KHR_DIR		:= $(INC_DIR)/KHR

SRC			:= \
			main.cpp \

C_SRC		:= \
			glad.c \

BIN			:= \
			$(addprefix $(BIN_DIR)/, \
			$(SRC:.cpp=.o))

C_BIN		:= \
			$(addprefix $(BIN_DIR)/, \
			$(C_SRC:.c=.o))

GL_FLAGS	:= -lGL
GLFW_FLAGS	:= -lglfw

X11_FLAGS	:= -lX11

LDFLAGS		:= $(GL_FLAGS) $(GLFW_FLAGS) $(X11_FLAGS) -lm

INCLUDE		:= -I$(INC_DIR) -I$(GLAD_DIR) -I$(KHR_DIR)

all: $(NAME)

run: all
	./$(NAME)

$(NAME): $(BIN) $(C_BIN)
	$(CXX_C) $(CXX_FLAGS) $(BIN) $(C_BIN) $(LDFLAGS) -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX_C) $(CXX_FLAGS) $(INCLUDE) -c $< -o $@

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) -rf $(BIN_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

glinfo:
	@glxinfo | grep "OpenGL version"
	@glxinfo | grep "OpenGL renderer"

.PHONY: all run clean fclean re glinfo
