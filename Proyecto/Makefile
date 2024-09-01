#
# In order to execute this &quot;Makefile&quot; just type &quot;make&quot;
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= main.o apple.o banana.o main2.o oracle.o banana.o
SOURCE	= main.c apple.c banana.c, main2.c oracle.c banana.c
HEADER	= apple.h banana.h orange.h
OUT	= myproject1 myproject2

OBJS0	= main.o apple.o banana.o
SOURCE0	= main.c apple.c banana.c
HEADER0	= apple.h banana.h
OUT0	= myproject1

OBJS1	= main2.o oracle.o banana.o
SOURCE1	= main2.c oracle.c banana.c
HEADER1	= orange.h banana.h
OUT1	= myproject2

FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= gcc

# -g option enables debugging mode 
# -c flag generates object code for separate files

# compile all components of the solution by using a single tag
all:	$(OUT)

# Compile all components of a specific project by using a single tag
myproject1: $(OBJS0)
	$(CC) -g $(OBJS0) -o $(OUT0) $(LFLAGS)

myproject2: $(OBJS1)
	$(CC) -g $(OBJS1) -o $(OUT1) $(LFLAGS)

#
# create/compile the individual files &gt;&gt;separately&lt;&lt;
main.o: main.c
	$(CC) $(FLAGS) main.c 

apple.o: apple.c
	$(CC) $(FLAGS) apple.c 

banana.o: banana.c,
	$(CC) $(FLAGS) banana.c, 

main2.o: main2.c
	$(CC) $(FLAGS) main2.c 

oracle.o: oracle.c
	$(CC) $(FLAGS) oracle.c 

banana.o: banana.c
	$(CC) $(FLAGS) banana.c 

# clean house
clean:
	rm -f $(OBJS) $(OUT)

