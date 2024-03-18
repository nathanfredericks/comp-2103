CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET1 = assignment6
TARGET2 = bonus
all: $(TARGET1) $(TARGET2)

$(TARGET1): $(TARGET1).c
	$(CC) $(CFLAGS) -o $(TARGET1) $(TARGET1).c

$(TARGET2): $(TARGET2).c
	$(CC) $(CFLAGS) -o $(TARGET2) $(TARGET2).c

clean:
	rm $(TARGET1) $(TARGET2)
