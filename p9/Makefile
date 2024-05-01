main: main.o table.o vector_keys.o vector_values.o
	gcc -o main main.o table.o vector_keys.o vector_values.o
main.o: main.c vectors_table.h
	gcc -c main.c
table.o: table.c vectors_table.h
	gcc -c table.c
vector_keys.o: vector_keys.c vectors_table.h
	gcc -c vector_keys.c
vector_values.o: vector_values.c vectors_table.h
	gcc -c vector_values.c

clean:
	rm main main.o table.o vector_keys.o vector_values.o