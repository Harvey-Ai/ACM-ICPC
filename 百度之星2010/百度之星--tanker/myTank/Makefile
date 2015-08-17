CC="g++"
CFLAG=-lwsock32 -lws2_32 -L"D:\file programmes\DEV-CPP\Lib"
obj=ai.o main.o

all: ai main
	$(CC) $(obj) -o a.exe $(CFLAG)

main: main.cpp
	$(CC) main.cpp -c -o main.o

ai: AI.cpp
	$(CC) AI.cpp -c -o ai.o
