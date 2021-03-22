IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=../bin

_DEPS = init_head.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = init.o module.o event_manager.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

module: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
