IDIR =inc
CC=g++
CFLAGS=-I $(IDIR)

SDIR=src
ODIR=obj
LDIR =lib

LIBS=-lm

_DEPS = morpion.h Plateau.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = morpion.cpp Plateau.cpp
OBJ = $(patsubst %,$(SDIR)/%,$(_OBJ))


$(SDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

morpion: $(OBJ)
	$(CC) -o $(ODIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/* *~ core $(INCDIR)/*~ 