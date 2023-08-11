all: 1_build 2_build 3_build 4_build 5_build

1_build: prog1.c
	gcc prog1.c -o prog1

1: 1_build
	./prog1

2_build: prog2.c
	gcc prog2.c -o prog2

2: 2_build
	./prog2

3_build: prog3.c
	gcc prog3.c -o prog3

3: 3_build
	./prog3

4_build: prog4.c
	gcc prog4.c -o prog4

4: 4_build
	./prog4

5_build: prog5.c
	gcc prog5.c -o prog5

5: 5_build
	./prog5

clean:
	rm prog1 prog2 prog3 prog4 prog5