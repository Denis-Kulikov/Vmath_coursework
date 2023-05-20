CC = gcc

APP_NAME = ex
TEST_NAME = test

# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -w
CFLAGS_TEST = -I src -MMD
CPPFLAGS = -I src -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)
TEST_OBJ_PATH = $(OBJ_DIR)/$(TEST_DIR)

SRC_EXT = c
APP_RUN = $(BIN_DIR)/./$(APP_NAME)
TEST_CHECK = $(BIN_DIR)/./$(TEST_NAME)

APP_SOURCES = $(shell find $(SRC_DIR)/ -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)

# LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
# LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d)
# DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: src/%.c
	$(CC) -c $(CFLAGS) $< -o $@


.PHONY: clean
clean:
	rm -f $(APP_PATH) $(LIB_PATH)
	rm -rf $(DEPS) $(APP_OBJECTS) $(LIB_OBJECTS)
	
.PHONY: run
run: $(APP_RUN)
	$(APP_RUN)

