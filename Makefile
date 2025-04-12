OBJS	= main1.o main2.o planificador.o colacp.o ejercicios.o
SOURCE	= ./Proyecto/colacp.c ./Proyecto/planificador.c, ./TP1/main1.c ./TP1/ejercicios.c, ./TP2/main2.c
HEADER	= ./Proyecto/colacp.h ./Proyecto/listadoble.h ./Proyecto/constantes.h, ./TP1/ejercicios.h
OUT	= ./Proyecto/proyecto ./TP1/tp1 ./TP2/tp2

OBJS0	= planificador.o colacp.o
SOURCE0	= ./Proyecto/planificador.c ./Proyecto/colacp.c
HEADER0	= ./Proyecto/colacp.h ./Proyecto/listadoble.h ./Proyecto/constantes.h
OUT0	= ./Proyecto/proyecto

OBJS1	= main1.o ejercicios.o
SOURCE1	= ./TP1/main1.c ./TP1/ejercicios.c
HEADER1	= ./TP1/ejercicios.h
OUT1	= ./TP1/tp1

OBJS2	= main2.o
SOURCE2	= ./TP2/main2.c
HEADER2	= 
OUT2	= ./TP2/tp2

FLAGS	= -g -c -Wall
LFLAGS	= -lm
CC	= gcc

# -g option enables debugging mode 
# -c flag generates object code for separate files

# compile all components of the solution by using a single tag
all:	$(OUT)

# Compile all components of a specific project by using a single tag
proyecto: $(OBJS0)
	$(CC) -g $(OBJS0) -o $(OUT0) $(LFLAGS) && rm -f $(OBJS0)

tp1: $(OBJS1)
	$(CC) -g $(OBJS1) -o $(OUT1) $(LFLAGS) && rm -f $(OBJS1)

tp2: $(OBJS2)
	$(CC) -g $(OBJS2) -o $(OUT2) $(LFLAGS) && rm -f $(OBJS2)

#
# create/compile the individual files &gt;&gt;separately&lt;&lt;
main1.o: ./TP1/main1.c
	$(CC) $(FLAGS) ./TP1/main1.c 

ejercicios.o: ./TP1/ejercicios.c
	$(CC) $(FLAGS) ./TP1/ejercicios.c

main2.o: ./TP2/main2.c
	$(CC) $(FLAGS) ./TP2/main2.c 

planificador.o: ./Proyecto/planificador.c
	$(CC) $(FLAGS) ./Proyecto/planificador.c 

colacp.o: ./Proyecto/colacp.c
	$(CC) $(FLAGS) ./Proyecto/colacp.c 

# clean house
clean:
	rm -f $(OBJS) $(OUT)

