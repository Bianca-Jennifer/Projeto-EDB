#---------------------------Executável-------------------------
main: arquivos_obj/main.o arquivos_obj/fila.o arquivos_obj/lista.o arquivos_obj/cardapio.o arquivos_obj/menu.o
	gcc arquivos_obj/main.o arquivos_obj/fila.o arquivos_obj/lista.o arquivos_obj/cardapio.o arquivos_obj/menu.o -o main


#----------------------Arquivos obj.---------------------------

 #main.o
arquivos_obj/main.o: Base/main.c Cozinha/fila.h Salao/lista.h Base/menu.h 
	gcc -IBase -ICozinha -ISalao -c Base/main.c -o arquivos_obj/main.o

#fila.o
arquivos_obj/fila.o: Cozinha/fila.c Cozinha/fila.h 
	gcc -IBase -ICozinha -ISalao -c Cozinha/fila.c -o arquivos_obj/fila.o

#lista.o
arquivos_obj/lista.o: Salao/lista.c Salao/lista.h Base/menu.h 
	gcc -IBase -ICozinha -ISalao -c Salao/lista.c -o arquivos_obj/lista.o

#cardapio.o
arquivos_obj/cardapio.o: Base/cardapio.c Base/cardapio.h 
	gcc -c Base/cardapio.c -o arquivos_obj/cardapio.o

#menu.o
arquivos_obj/menu.o: Base/menu.c Base/menu.h Base/cardapio.h Salao/lista.h Cozinha/fila.h 
	gcc -IBase -ICozinha -ISalao -c Base/menu.c -o arquivos_obj/menu.o



#------------Remoção de executável e arquivos obj.--------------
clean:
	rm -f main arquivos_obj/*.o
