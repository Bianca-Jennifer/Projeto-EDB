main:main.o fila.o lista.o cardapio.o menu.o
	gcc main.o fila.o lista.o cardapio.o menu.o -o main

main.o:main.c fila.h lista.h menu.h
	gcc c main.c

fila.o:fila.c fila.h
	gcc -c fila.c

lista.o:lista.c lista.h menu.h
	gcc -c lista.c

cardapio.o:cardapio.c cardapio.h
	gcc -c cardapio.c

menu.o:menu.c menu.h cardapio.h lista.h fila.h
	gcc -c menu.c