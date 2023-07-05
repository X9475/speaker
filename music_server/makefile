PROJ   = ../bin/app ../bin/music ../bin/server
RM     = rm -rf
CFLAGS = -Wall -g -rdynamic

all: $(PROJ)

../bin/app: app.c
	gcc $^ -o $@ -ljson-c -lpthread $(CFLAGS)

../bin/music: music.c
	gcc $^ -o $@ -ljson-c -lpthread $(CFLAGS)

../bin/server: main.cpp player.cpp server.cpp
	g++ $^ -o $@ -ljsoncpp -levent $(CFLAGS)


clean:
	$(RM) $(PROJ) *.o 
