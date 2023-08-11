all: 1_build 2_build 3_build

1_build: 5_1.c
	gcc 5_1.c includes/list.c -o 5_1.out

1: 1_build
	./5_1.out


2_build: 5_2.c
	gcc 5_2.c includes/list.c -o 5_2.out

2: 2_build
	./5_2.out


3_build: 5_3.c
	gcc 5_3.c includes/list.c -o 5_3.out

3: 3_build
	./5_3.out

clean:
	rm 5_1.out 5_2.out 5_3.out