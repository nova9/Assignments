# Homework 8

> Name: MADUSHA I T

> Index No: 22001158

> Email: thathsaramadhhusha@gmail.com

## Tested on

- Linux GCC

## How to compile & run

### Compile
```
make
```

### Run programme 1
```
make run
```

# Description

This C program primarily implements an AVL (Adelson-Velsky and Landis) tree. The AVL tree is a self-balancing binary search tree, where the difference of heights of left and right subtrees cannot be more than one for all nodes. Here is an explanation of the different parts:

## Struct Node
The Node struct represents a node in the AVL tree. Each node has a key (the value of the node), and two pointers - left and right - that point to the node's left and right child nodes respectively.

## Function print_inorder(Node *node)
This function prints out the nodes of the tree in an in-order traversal (left, root, right). It's a recursive function that calls itself on the left subtree, then prints the key of the current node, and then calls itself on the right subtree.

## Function create_node(int key)
This function creates a new memory space for a node, sets its key to the provided value, and initializes its left and right child pointers as NULL. It returns a pointer to the newly allocated node.

## Function find_height(Node *node)
This function calculates and returns the height of a node in the tree. It does so by recursively checking the heights of the left and right subtrees.

## Function get_balance_factor(Node *node)
This function calculates and returns the balance factor of a node which is the height difference between its left and right sub-tree.

## Functions right_rotate(Node *y) and left_rotate(Node *x)
These functions perform right and left rotation operations on the tree respectively to maintain the balance of the tree.

## Function find_min(Node *node)
This function finds and returns the node with the smallest key in the tree rooted at the given node. It is a helper function used for deleting nodes from the tree.

## Function insert(Node *node, int key)
This function inserts a new node with the given key into the AVL tree. After insertion, it balances the tree if required, using left or right rotations.

## main()
In the main() function, an AVL tree root is created, and nodes with keys 30, 5, 3, 18, 12, 16 and 1 are inserted. Then the print_inorder function is called to print the in-order traversal of the tree.
This code doesn't have a function to delete nodes from the AVL tree. Also, it doesn't free the memory used by the nodes when the program ends, leading to memory leaks.
Remember that this code works with integer keys but you can modify the key attribute of the Node structure to make it work with other datatypes.