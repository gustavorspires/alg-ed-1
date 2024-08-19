all: circulo.o ponto.o cliente.o
	gcc circulo.o ponto.o cliente.o -o cli -std=c99 -Wall

circulo.o:
	gcc -c circulo.c -o circulo.o

ponto.o:
	gcc -c ponto.c -o ponto.o

cliente.o:
	gcc -c cliente.c -o cliente.o

zip: 
	zip -R compacto.zip . '*.c' '*.h' 'Makefile'

clean:
	rm *.o cli

run:
	./cli