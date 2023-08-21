ITEMS = 3_1 3_2 3_3

all: $(ITEMS)

%: %.c
	gcc $< -o $*

1: 3_1
	./3_1

2: 3_2
	./3_2

3: 3_3
	./3_3

clean:
	rm $(ITEMS)