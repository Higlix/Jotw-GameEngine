CC=g++

BUILD=build
INCLUDE_DIR_NAME=include
SOURCE_DIR_NAME=source
LIBRARY_DIR_NAME=libraries
OBJECT_DIR_NAME=$(BUILD)/object

SDL_DIR_NAME=SDL2
SDL_INCLUDE_DIR_NAME=$(LIBRARY_DIR_NAME)/$(SDL_DIR_NAME)/include
SDL_LIBRARY_DIR_NAME=$(LIBRARY_DIR_NAME)/$(SDL_DIR_NAME)/build/.libs

SDL_LIB_FLAGS=-lmingw32 -lSDL2main -lSDL2 -Wl,--dynamicbase -Wl,--nxcompat \
-Wl,--high-entropy-va -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 \
-lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid -static

CXXFLAGS=-I$(INCLUDE_DIR_NAME) -I$(SDL_INCLUDE_DIR_NAME)
LDFLAGS=-L$(SDL_LIBRARY_DIR_NAME) $(SDL_LIB_FLAGS)

SOURCE_FILES = $(shell find $(SOURCE_DIR_NAME) -name '*.cpp')
OBJECT_FILES = $(SOURCE_FILES:$(SOURCE_DIR_NAME)/%.cpp=$(OBJECT_DIR_NAME)/%.o)

NAME=jotw

all: $(OBJECT_DIR_NAME) $(NAME)

$(OBJECT_DIR_NAME):
	mkdir -p $@

$(OBJECT_DIR_NAME)/%.o: $(SOURCE_DIR_NAME)/%.cpp
	mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CXXFLAGS)

$(NAME): $(OBJECT_FILES)
	$(CC) -o $(BUILD)/$@ $(OBJECT_FILES) $(LDFLAGS)

clean:
	rm -rf $(OBJECT_DIR_NAME)

fclean: clean
	rm -rf $(BUILD)

re: fclean all
