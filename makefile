c=gcc
op=-Wall -Wextra

all : es.o livre.o biblio.o tpBiblio.c 	
	$(c) $(op)  es.o livre.o biblio.o tpBiblio.c -o exe

es.o : es.c
	$(c) $(op) -c es.c	
livre.o : livre.c
	$(c) $(op) -c livre.c	
biblio.o : biblio.c
	$(c) $(op) -c biblio.c	


clean:
	rm -f es.o
	rm -f livre.o
	rm -f biblio.o
	rm -f exe
	rm -f ladate
	

