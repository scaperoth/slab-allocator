#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

CC = gcc
CFLAGS = -Wall -g -O3
INCLUDES = 
LFLAGS = 
LIBS = 
SRCS = slab.c 
OBJS = $(SRCS:.c=.o)
MAIN = slab

.PHONY: clean

all: $(MAIN)
	@echo  $(SRCS) has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)