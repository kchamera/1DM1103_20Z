DEPS = mymathlab.o wczytaj.o operacje.o

mymathlab: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lm

%.o:%.c
	cc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o
test:
	./mymathlab sum x2.txt x.txt
