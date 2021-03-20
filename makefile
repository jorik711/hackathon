CC=g++
CFLAGS=-c -Wall -Wextra

all: chat

chat: main.o User.o Message.o Chat.o
	$(CC) main.o User.o Message.o Chat.o -o chat

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

User.o: User.cpp
	$(CC) $(CFLAGS) -c User.cpp

Message.o: Message.cpp
	$(CC) $(CFLAGS) -c Message.cpp

Chat.o: Chat.cpp
	$(CC) $(CFLAGS) -c Chat.cpp
clean:
	rm -rf *.o 
