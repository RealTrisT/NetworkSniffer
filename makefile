CC:=g++
SRC:=code
OBJ:=obj

#SOURCES:=$(wildcard $(SRC)/*.c)
SOURCES:=$(shell find $(SRC)/ -type f -name '*.cpp')

sniffer:$(SOURCES)
	$(CC) -o $@ $(SOURCES)

