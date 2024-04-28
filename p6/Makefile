preprocessing: preprocessing.o
	gcc -o preprocessing preprocessing.o
preprocessing.o: preprocessing.c student.h
	gcc -c preprocessing.c

main: main.o print.o
	gcc -o main main.o print.o
main.o: main.c student.h
	gcc -c main.c 
print.o: print.c student.h
	gcc -c print.c

clean:
	rm main main.o preprocessing preprocessing.o student.h.gch print.o