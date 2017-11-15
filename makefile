LIBS = cell.o lifegame.o image.o util.o lifeobj.o
FILES = main.o $(LIBS)
OUTPUT = lgfilter
N = 1
I = image.bmp
O = ./output/output.bmp
RUST_SRC = ./rustsrc
RUST_LIB = ./rustlib
build: $(FILES)
	cc -O3 -o $(OUTPUT) $(FILES)

share: $(LIBS)
	cc -O3 -shared -fPIC -o lg.so $(LIBS)

run: c
	./$(OUTPUT)

c: $(FILES)
	cc -O3 -o $(OUTPUT) $(FILES)

.c.o:
	cc -c $<

cell.o: cell.h
lifegame.o: lifegame.h
image.o: image.h
util.o: util.h
lifeobj.o: lifeobj.h

clean:
	rm output*.bmp
