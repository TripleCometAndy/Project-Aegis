OBJS = background.o Camera.o gameObject.o main.o Timer.o sdlHandlers.o crusherCaptain.o block.o wall.o ship.o handleEvents.o handleAllStateChanges.o enactAllStateChanges.o cleanLoop.o uGrid.o renderAll.o loadAllFiles.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -O3  -c $(DEBUG)
LFLAGS = -Wall  $(DEBUG) -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

test : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o test

background.o : background.cpp Orion.h
	$(CC) $(CFLAGS) background.cpp

Camera.o : Camera.cpp Orion.h
		$(CC) $(CFLAGS) Camera.cpp

gameObject.o : lib/gameobject/gameObject/gameObject.cpp lib/gameobject/gameObject/gameObject.h
		$(CC) $(CFLAGS) lib/gameobject/gameObject/gameObject.cpp

main.o : main.cpp Orion.h
		$(CC) $(CFLAGS) main.cpp

Timer.o : lib/timer/timer/Timer.cpp lib/timer/timer/Timer.h
	$(CC) $(CFLAGS) lib/timer/timer/Timer.cpp

sdlHandlers.o : lib/sdlhandlers/sdlHandlers/sdlHandlers.cpp lib/sdlhandlers/sdlHandlers/sdlHandlers.h
	$(CC) $(CFLAGS) lib/sdlhandlers/sdlHandlers/sdlHandlers.cpp

crusherCaptain.o : crusherCaptain.cpp Orion.h
	$(CC) $(CFLAGS) crusherCaptain.cpp


block.o : block.cpp Orion.h
	$(CC) $(CFLAGS) block.cpp

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

wall.o : wall.cpp Orion.h
	$(CC) $(CFLAGS) wall.cpp
