OBJS = background.o gameObject.o uGrid.o main.o Timer.o sdlHandlers.o ship.o handleEvents.o handleAllStateChanges.o enactAllStateChanges.o cleanLoop.o  renderAll.o loadAllFiles.o loop.o inputHandler.o loopWrite.o
CC = g++
CFLAGS = -std=c++11 -Wall -O3  -c -g

Aegis: $(OBJS)
	$(CC) $(OBJS) -I/usr/include -lSDL2  -I/usr/local/lib -lSDL2_image -I/usr/local/lib -lSDL2_mixer -lX11 -o Aegis

background.o: background.cpp Orion.h
	$(CC) $(CFLAGS) background.cpp

gameObject.o : lib/gameobject/gameObject/gameObject.cpp lib/gameobject/gameObject/gameObject.h
			$(CC) $(CFLAGS) lib/gameobject/gameObject/gameObject.cpp

main.o : main.cpp Orion.h
			$(CC) $(CFLAGS) main.cpp

Timer.o : lib/timer/timer/Timer.cpp lib/timer/timer/Timer.h
		$(CC) $(CFLAGS) lib/timer/timer/Timer.cpp

sdlHandlers.o : lib/sdlhandlers/sdlHandlers/sdlHandlers.cpp lib/sdlhandlers/sdlHandlers/sdlHandlers.h
		$(CC) $(CFLAGS) lib/sdlhandlers/sdlHandlers/sdlHandlers.cpp


ship.o : ship.cpp Orion.h
		$(CC) $(CFLAGS) ship.cpp

handleEvents.o : lib/handleevents/handleEvents/handleEvents.cpp lib/handleevents/handleEvents/handleEvents.h
		$(CC) $(CFLAGS) lib/handleevents/handleEvents/handleEvents.cpp


handleAllStateChanges.o : lib/handleallstatechanges/handleAllStateChanges/handleAllStateChanges.cpp lib/handleallstatechanges/handleAllStateChanges/handleAllStateChanges.h
			$(CC) $(CFLAGS) lib/handleallstatechanges/handleAllStateChanges/handleAllStateChanges.cpp

enactAllStateChanges.o : lib/enactallstatechanges/enactAllStateChanges/enactAllStateChanges.cpp lib/enactallstatechanges/enactAllStateChanges/enactAllStateChanges.h
			$(CC) $(CFLAGS) lib/enactallstatechanges/enactAllStateChanges/enactAllStateChanges.cpp

cleanLoop.o : lib/cleanloop/cleanLoop/cleanLoop.cpp lib/cleanloop/cleanLoop/cleanLoop.h
			$(CC) $(CFLAGS) lib/cleanloop/cleanLoop/cleanLoop.cpp

uGrid.o : lib/ugrid/uGrid/uGrid.cpp lib/ugrid/uGrid/uGrid.h
		$(CC) $(CFLAGS) lib/ugrid/uGrid/uGrid.cpp

renderAll.o : lib/renderall/renderAll/renderAll.cpp lib/renderall/renderAll/renderAll.h
		$(CC) $(CFLAGS) lib/renderall/renderAll/renderAll.cpp

loadAllFiles.o : lib/loadallfiles/loadAllFiles/loadAllFiles.cpp lib/loadallfiles/loadAllFiles/loadAllFiles.h
		$(CC) $(CFLAGS) lib/loadallfiles/loadAllFiles/loadAllFiles.cpp

loop.o : loop.cpp Orion.h
	$(CC) $(CFLAGS) loop.cpp

inputHandler.o : lib/inputhandler/inputHandler/inputHandler.cpp lib/inputhandler/inputHandler/inputHandler.h
	$(CC) $(CFLAGS) lib/inputhandler/inputHandler/inputHandler.cpp

loopWrite.o : loopWrite.cpp Orion.h
	$(CC) $(CFLAGS) loopWrite.cpp
