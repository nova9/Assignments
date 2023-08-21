all: 1_build 2_build

1_build: 4_1/main.c 4_1/queue.c
	gcc 4_1/main.c 4_1/queue.c -o 4_1.out

1: 1_build
	./4_1.out

2_build: 4_2/main.c 4_2/queue.c
	gcc 4_2/main.c 4_2/queue.c -o 4_2.out

2: 2_build
	./4_2.out

clean:
	rm 4_1.out 4_2.out