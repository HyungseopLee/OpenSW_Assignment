.PHONY: all basic clean debug

PROJ=$(PWD)
SRC_DIR=$(PROJ)/src
OBJ_DIR=$(PROJ)/obj
INC_DIR=$(PROJ)/include
LIB_DIR=$(PROJ)/lib
BIN_DIR=$(PROJ)/bin

BASIC_SRCS=$(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c
BASIC_OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BASIC_SRCS))

CC=gcc
AR=ar rv

all: $(BIN_DIR)/myapp
$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(LIB_DIR)/libmybasic.a
	$(CC) $^ -L$(LIB_DIR) -lmybasic -I$(INC_DIR) -o $@ 

basic: $(LIB_DIR)/libmybasic.a
$(LIB_DIR)/libmybasic.a: $(BASIC_OBJS)
	$(AR) $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)


debug:
	@echo "BASIC_SRCS: $(BASIC_SRCS)"
	@echo "BASIC_OBJS: $(BASIC_OBJS)"

clean:
	@echo "cleaning directory..."
	rm -rf $(OBJ_DIR)/* $(LIB_DIR)/* $(BIN_DIR)/*;
