# Name of the project
PROJECT_NAME= PontesDeKonigsberg

# .cpp Files
CPP_SOURCE=$(wildcard ./source/*.cpp)

# .hpp Files
HPP_SOURCE=$(wildcard ./include/*.h)

# Object Files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(CPP_SOURCE)))

# Compiler
CC=g++

# Flags for Compiler
CC_FLAGS=-c -I ./include/


# Linker Flags
LINKER_FLAGS=-Wall -Llsfml-bin -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio


# Compilation and linking
all: objFolder ./bin/$(PROJECT_NAME)

./bin/$(PROJECT_NAME):	$(OBJ)
				@ echo 'Bulding binary using G++ linker: $@'
				$(CC) -o $@ $^ $(LINKER_FLAGS)
				@ echo 'Finished buiding binary: $@'
				@ echo ' '
				@ echo '#!/usr/bin/env bash' > mec-executavel-linux
				@ echo ' ' >> mec-executavel-linux
				@ echo 'cd compilado-Linux && ./PontesDeKonigsberg && cd -' >> mec-executavel-linux
				@ chmod +x mec-executavel-linux

./objects/%.o: ./source/%.cpp
				@ echo 'Building target using G++ compiler: $<'
				$(CC) -o $@ $< $(CC_FLAGS)
				@ echo ' '

./objects/main.o: ./source/main.cpp $(HPP_SOURCE)
		    @ echo 'Building target using G++ compiler: $<'
		    $(CC) -o $@ $< $(CC_FLAGS)
		    @ echo ' '

objFolder:
			@ mkdir -p objects

clean:
		    @ rm -r objects
			@ rm ./bin/$(PROJECT_NAME)
