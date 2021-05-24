ORACLE=test.sh    

all: lib
    
lib:
	make -C $(CHISEL_BENCHMARK_HOME)/benchmark/lib    
    
reduce: lib
	make CFLAGS=-Wno-error
	. setenv
	cp src/$(NAME) ./$(NAME).origin
	chisel --build ./$(ORACLE) -- make src/$(NAME)