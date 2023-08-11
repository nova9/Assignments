ITEMS = q1 q2 q3 q4

all: $(ITEMS)

%: %.c
	gcc $< -o $*

1: q1
	./q1

2: q2
	./q2

3: q3
	./q3

4: q4
	./q4

clean:
	rm $(ITEMS)