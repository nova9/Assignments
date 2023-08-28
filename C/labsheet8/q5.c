#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int accession_number;
    char *author;
    char *title;
    bool is_issued;
} Book;

typedef struct BookArray {
    Book *data[2000];
    int length;
} BookArray;

void add_book(BookArray *books) {
    printf("Enter the title: ");
    char *title = malloc(sizeof(char) * 256);
    scanf(" %[^\n]", title);
    printf("Enter the author: ");
    char *author = malloc(sizeof(char) * 256);
    scanf(" %[^\n]", author);
    Book *new_book = malloc(sizeof(Book));
    new_book->title = title;
    new_book->author = author;
    new_book->accession_number = books->length;
    books->data[(books->length)++] = new_book;
}

void print_total_amount_of_books(BookArray *books) {
    printf("Total amount of books: %d\n", books->length);
}


void print_book(Book *book) {
    printf("---\nTitle: %s\nAuthor: %s\nAccession number: %d\n---\n",
           book->title,
           book->author,
           book->accession_number
    );
}

void show_details(BookArray *books) {
    printf("Enter accession number: ");
    int accession_number;
    scanf(" %d", &accession_number);
    for (int i = 0; i < books->length; i++) {
        if (books->data[i]->accession_number == accession_number) {
            print_book(books->data[i]);
        }
    }
}

void author_filter(BookArray *books) {
    printf("Enter author name: ");
    char author_name[256];
    scanf(" %[^\n]", author_name);
    for (int i = 0; i < books->length; i++) {
        if (strcmp(books->data[i]->author, author_name) == 0) {
            print_book(books->data[i]);
        }
    }
}

void title_filter(BookArray *books) {
    printf("Enter title: ");
    char title[256];
    scanf(" %[^\n]", title);

    int count = 0;
    for (int i = 0; i < books->length; i++) {
        if (strcmp(books->data[i]->title, title) == 0) {
            count++;
        }
    }
    printf("Number of books with the title %s is %d\n", title, count);
}

void issue(BookArray *books) {
    printf("Enter accession number: ");
    char accession_number[256];
    scanf(" %[^\n]", accession_number);
    for (int i = 0; i < books->length; i++) {
        if (books->data[i]->accession_number == 0) {
            books->data[i]->is_issued = true;
        }
    }
}

int main() {
    BookArray books;
    books.length = 0;

    while (1) {
        printf("####### Menu ###### \n");
        printf("1. Add book\n");
        printf("2. Total amount of books\n");
        printf("3. Show details\n");
        printf("4. Count by title\n");
        printf("5. Filter by author\n");
        printf("6. Issue a book\n");
        printf(": ");

        int choice;
        scanf("%d", &choice);

        printf("\n");

        switch (choice) {
            case 1:
                add_book(&books);
                break;
            case 2:
                print_total_amount_of_books(&books);
                break;
            case 3:
                show_details(&books);
                break;
            case 4:
                title_filter(&books);
                break;
            case 5:
                author_filter(&books);
                break;
            case 6:
                issue(&books);
                break;
        }

        printf("\n");
    }
}