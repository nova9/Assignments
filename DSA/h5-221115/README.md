# Homework 5

> Name: MADUSHA I T

> Temporary ID: 221115

> Email: thathsaramadhhusha@gmail.com

## Tested on

- Linux GCC

## How to compile & run

### Compile
```
make
```

### Run question 1 (5.1)
```
make 1
```

### Run question 2 (5.2)
```
make 2
```

### Run question 3 (5.3)
```
make 3
```

## Description

### Question 1

This is a programme to concatenate two lists. First the user has to enter the first list. Notice that the space is used to separate values. 
```
Enter values for list 1 seperated by spaces: 34 45 56
```
Then the second list.
```
Enter values for list 2 seperated by spaces: 1 2 3
```
After that the concatenated list is shown.
```
List 1:   34 45 56 
List 2:   1 2 3 
Concatenated:   34 45 56 1 2 3 
```

### Question 2

This is a programme to insert values to a list in ascending order. The user will be asked to enter values repeatedly and the resulting list will also be shown.
```
Enter an integer to insert (Enter a letter to exit): 4
List :   4 
Enter an integer to insert (Enter a letter to exit): 23
4 23 
Enter an integer to insert (Enter a letter to exit): 43
4 23 43 
Enter an integer to insert (Enter a letter to exit): 43
4 23 43 43 
Enter an integer to insert (Enter a letter to exit): 2
2 4 23 43 43 
Enter an integer to insert (Enter a letter to exit): 
```
The user can enter a non integer to exit the programme.
```
Enter an integer to insert (Enter a letter to exit): d
```

### Question 3

This is a simple implementation of Queue data structure using lists. User can choose to insert or delete values from the list(queue) and the resulting list(queue) will be shown.
```
1. Insert
2. Delete
Choose(Enter anything else to exit): 1
Enter an integer to insert: 34
List:   34
```