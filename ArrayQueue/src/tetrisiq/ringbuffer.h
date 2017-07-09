/*
 * ringbuffer.h
 *
 *  Created on: 02.07.2017
 *      Author: alex
 */

#include <stdlib.h>
#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

/**
 * Zum Inizalisiren einer Queue / eines Ringbuffers
 * @parm size Die Größe der Queue / des Ringbuffers
 */
int rbinit(size_t size);
/**
 * Zum Freigeben des Speichers der Queue / des Ringbuffers
 */
int rbfree();

/**
 * Zum hinzufügen eines neuen Elementes In die vorhandenen Queue / Ringbuffer
 * @parm e Das Char Element das eingefügt werden soll
 */
int rbput(char e);

/**
 * Zum entnehmen eines Elementes aus der Queue / Ringbuffer
 * @return das entfernte element
 */
char rbget();


typedef struct ringbuffer_ {
    size_t size; // Groesse des Puffers
    size_t count; // Anzahl der Elmente im Puffer
    size_t head; // Index des vordersten Elements
    size_t tail; // Index des hintersten Elements
    char* data; // Zeiger auf den Puffer
                // data wird durch malloc auf dem Heap
                // angelegt.
} ringbuffer;

#endif /* RINGBUFFER_H_ */
