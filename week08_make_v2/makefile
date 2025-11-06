.PHONY: all basic_ops advanced_ops clean

PROJ=$(PWD)
SRC_DIR=$(PROJ)/src
OBJ_DIR=$(PROJ)/obj
INC_DIR=$(PROJ)/include
LIB_DIR=$(PROJ)/lib
BIN_DIR=$(PROJ)/bin

STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a
CC=gcc

CFLAGS=-I$(INC_DIR) -lm
LDFLAGS=-L$(LIB_DIR) -lmybasic -lmyadvanced


all: $(BIN_DIR)/myapp
$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(STATIC_LIBS)
	$(CC) $< -o $@ $(LDFLAGS) $(CFLAGS)

basic_ops: 
	$(MAKE) -C basic_ops
advanced_ops: 
	$(MAKE) -C advanced_ops

clean:
	rm -rf $(BIN_DIR)/* $(LIB_DIR)/*;
	$(MAKE) -C basic_ops clean;
	$(MAKE) -C advanced_ops clean