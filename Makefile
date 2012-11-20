CC=gcc
LDFLAGS=
EXECUTABLE=des
SOURCE= \
	src/main.c \
	include/declaration.h

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE)
	$(CC) $(SOURCE) -c -o $@