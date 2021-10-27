# files in the program
FILES = Btn.cc main.cc MediaLoader.cc Renderer.cc Texture.cc Window.cc

# compiler
CC = g++

# link the libraries
LINK = -lSDL2 -lSDL2_image -lSDL2_mixer

# name of the executable
OUT = niilosoundboard

all : $(FILES)
	$(CC) $(FILES) $(LINK) -o $(OUT)

