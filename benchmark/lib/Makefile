all: filewrap.a memwrap.a

%.a : %.o
	ar -rc lib$@ $<
	ranlib lib$@

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o *.a
