PROJ=$(shell pwd)
SRC_DIR=$(PROJ)/src
OBJ_DIR=$(PROJ)/obj
LIB_DIR=$(PROJ)/../lib
INC_DIR=$(PROJ)/../include

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

AR=ar rv
CC=gcc

.PHONY: all clean debug

all: $(LIB_DIR)/libmyadvanced.a

$(LIB_DIR)/libmyadvanced.a : $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR);
	$(CC) -c $< -o $@ -I$(INC_DIR)

debug:
	@echo "SRC_DIR: $(SRC_DIR)"
	@echo "LIB_DIR: $(LIB_DIR)"
	@echo "INC_DIR: $(INC_DIR)"
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"

clean:
	rm -rf $(OBJ_DIR)/*;