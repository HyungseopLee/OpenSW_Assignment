.PHONY=all clean debug

PROJ=$(PWD)
SRC_DIR=$(PROJ)/src
OBJ_DIR=$(PROJ)/obj
INC_DIR=$(PROJ)/include
LIB_DIR=$(PROJ)/lib
BIN_DIR=$(PROJ)/bin
SRCS=$(SRC_DIR)/myadd.c $(SRC_DIR)/mysub.c $(SRC_DIR)/mymul.c $(SRC_DIR)/mydiv.c $(SRC_DIR)/mypow.c $(SRC_DIR)/mymod.c
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
CC=gcc

all: $(BIN_DIR)/myapp

$(BIN_DIR)/myapp : $(SRC_DIR)/myapp.c shared_lib
	$(CC) $< -L$(LIB_DIR) -lmyops -o $@ -I$(INC_DIR)

shared_lib: $(LIB_DIR)/libmyops.so.1.0
	ln -s libmyops.so.1.0 $(LIB_DIR)/libmyops.so.1
	ln -s libmyops.so.1 $(LIB_DIR)/libmyops.so

$(LIB_DIR)/libmyops.so.1.0: $(OBJS)
	$(CC) -shared -Wl,-soname=libmyops.so.1 $^ -o $@ -lc -lm

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c -fPIC $< -o $@ -I$(INC_DIR)

debug:
	@echo "OBJS: $(OBJS)"
clean:
	rm -rf $(LIB_DIR)/* $(OBJ_DIR)/* $(BIN_DIR)/*