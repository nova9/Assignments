#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

#include "queue.h"

char *get_string() {
    int size = 16;

    char *str = malloc(sizeof(char) * size);;
    int len = 0;

    int ch;
    while (EOF != (ch = getchar()) && ch != '\n') {
        str[len++] = ch;
        if (len == size) {
            str = realloc(str, sizeof(char) * (size += size));
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

void play(char *song) {
    printf("playing: %s\n", song);
    sleep(1);
}

int main() {
    Queue *song_queue = init_queue(999);

    char *song;
    while (strlen(song) != 0) {
        printf("Enter a song (Enter nothing to play): ");
        song = get_string();
        if (strlen(song) != 0)
            enqueue(song_queue, song);
    }

    while (1) {
        play(dequeue(song_queue));

        if(is_empty(song_queue)) {
            break;
        }
    }
}