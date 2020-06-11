CC = clang++
CFLAGS = -O0
RepeatedWords: Text
	$(CC) -std=c++17 -o RepeatedWords $(CFLAGS) Main.cpp Text.o
Text:
	$(CC) -std=c++17 -c $(CFLAGS) Text.cpp
clean:
	rm *.o RepeatedWords