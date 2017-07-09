/*
 * ringbuffer.c
 *
 *  Created on: 02.07.2017
 *      Author: alex
 */

#include "ringbuffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


ringbuffer queue;

// zum Initialisieren eines Ringbuffers.
int rbinit(size_t size) {
    queue.size = size;
    queue.count = 0;
    queue.head = 0;
    queue.tail = 0;
    queue.data = malloc(size * sizeof(char));

    return 1;

}
//zum Freigeben des belegten Speicherplatzes
int rbfree() {
    free(queue.data);
    return 1;
}
// zum Hinzufügen eines einzelnen Zeichens am Ende.
int rbput(char e) {
    if (queue.count == queue.size) {
           printf("Die Warteschlange ist voll!\n");
           return 0;
       }

       queue.tail++;

       if (queue.count == 0 && *(queue.data) == '\0') {
           queue.tail = 0;
       }
       if (queue.tail == queue.size) {
           queue.tail = 0;
       }

       queue.count++;
       *(queue.data + queue.tail) = e;
       return 1;
}

//zum Herausholen und zurückliefern eines Zeichens vom Anfang.
char rbget() {
    if (queue.count == 0) {
        printf("Kein Element in der Warteschlange!");
        return 0;
    }
    char c = *(queue.data + queue.head);
    *(queue.data + queue.head) = '\0';
    queue.head++;

    if (queue.head == queue.size) {
        queue.head = 0;
    }

    queue.count--;
    return c;

}
