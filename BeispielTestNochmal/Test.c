/*
 * Test.c
 *
 *  Created on: 11.07.2017
 *      Author: alex
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct listnode_ {
    int data;
    struct listnode_* next;
} Listnode;

int counta(char s[]);
int sumArray(int values[], size_t count);
void applyFkt(int values[], size_t count, int (*fkt)(int));
int countAFile(char* filename);
double avgList(Listnode* head);
Listnode* addFront(Listnode* head, int item);
void freeList(Listnode* head);

/* Es folgen die Aufgaben */
// **************************

// Aufgabe 1 (10 Punkte)
/**
 * Bestimmt die Anzahl der Vorkommen des Buchstabens 'a' in der
 * Zeichenkette s
 * @param s Zeichenkette
 * @return Anzahl der Vorkommen von 'a'
 */
int counta(char s[]) {
    int counta = 0;
    int i = 0;
    do {
        if (s[i] == 'a') {
            counta++;
        }
        i++;
    }while (s[i] != '\0');

    return counta;
}

// Aufgabe 2 (15 Punkte)

/**
 * Bestimmt die Summe der Elemente im uebergebenen Array
 * @param values Array der zu summierenden Elemente
 * @param count Anzahl der Elemente in dem Array values
 * @return Summe der Elemente
 */
int sumArray(int values[], size_t count) {
    int i;
    int sum = 0;
    for (i = 0; i < count; i++) {
        sum += values[i];
    }
    return sum;
}

// Aufgabe 3 (15 Punkte)

/**
 * Wendet auf jedes Element eines int-Arrays eine Funktion an und
 * ersetzt das Element durch den Rueckgabewert der Funktion.
 * @param values Array von int-Werten
 * @param count Anzahl der Elemente in values
 * @param fkt Funktionspointer auf die anzuwendende Funktion
 */
void applyFkt(int values[], size_t count, int (*fkt)(int)) {
    int i;
    for (i = 0; i < count; i++) {
        fkt(values[i]);
    }

}

// Aufgabe 4 (20 Punkte)

/**
 * Die Funktion ermittelt die Anzahl der 'a' oder 'A' in der
 * uebergebenen Datei.
 * Dazu oeffnet die Funktion die Datei mit fopen
 * liest die Datei zeichenweise mit fgetc ein bis das Ergebnis
 * EOF ist und schliesst die Datei mit fclose
 * @param filename Dateiname
 * @return Anzahl der 'A'/'a' in der Datei
 */
int countAFile(char* filename) {
    FILE* file = fopen(filename, "r");
    int countA = 0;
    char c;
    do {
        c = fgetc(file);
        if (c == 'a' || c == 'A') {
            countA++;
        }
    } while (c != EOF);
    return countA;
}

// Aufgabe 5 (20 Punkte)

/**
 * Bestimmt den Durchschnittswert der in der verketteten Liste
 * gespeicherten Werte.
 * @param head Zeiger auf das erste Element der Liste
 * @return Durchschnitt der gespeicherten Werte.
 */
double avgList(Listnode* head) {
    int sum = 0;
    int count = 0;
    Listnode* newHead = head;
    do {
        sum += newHead->data;
        count++;
        newHead = newHead->next;
    }while (newHead->next != NULL);
    return (double) sum / count;
}

// Aufgabe 6 (20 Punkte)
typedef struct Station_ {
    int tag[];
    char reiseZiel[];
} Station;

// Ein Reiseplan soll in C verwaltet werden
// Erstellen Sie einen typedef Station fuer eine Struktur,
// die eine Station auf der Reise abbildet.
// In der Stuktur sollen Reisetag und Reiseziel
// enthalten sein.
// Erstellen Sie eine Funktion mkSt(tag, ziel), die eine solche Struktur
// auf dem Heap erzeugt und die Eintraege der Struktur den Parametern
// entsprechend fuellt. Die Funktion soll dann einen Zeiger auf die
// Struktur zurueckgeben.

Station* mkSt(int tag, char* reiseZiel) {
    Station* newStation = (Station*) malloc(sizeof(Station));
    newStation->reiseZiel = reiseZiel;
    newStation->tag = tag;
    return newStation;
}

void freeStation(Station* st) {
    if (st == NULL) return;
    free(st);
}



// Ende der Aufgaben

Listnode* addFront(Listnode* head, int item) {
    Listnode* newHead = (Listnode*) malloc(sizeof(Listnode));
    newHead->next = head;
    newHead->data = item;
    return newHead;
}

void freeList(Listnode* head) {
    if (head == NULL) return;
    freeList(head->next);
    free(head);
}

int quad(int x) {
    return x * x;
}

int main(void) {
    char s[] = "analysis";
    int v[] = {
    1, 6, -3, 6, 0
    };
    int i = 0;
    Listnode* head = NULL;
    printf("%s %d\n", s, counta(s));
    printf("%d = %d\n", 10, sumArray(v, sizeof(v) / sizeof(int)));
    for (i = 0; i < sizeof(v) / sizeof(int); i++)
        printf("%d ", v[i]);
    printf(" == quad ==> ");
    applyFkt(v, sizeof(v) / sizeof(int), quad);
    for (i = 0; i < sizeof(v) / sizeof(int); i++)
        printf("%d ", v[i]);
    printf("\n");
    for (i = 0; i < sizeof(v) / sizeof(int); i++)
        head = addFront(head, v[i]);
    printf("Durchschnitt %f\n", avgList(head));
    freeList(head);
    return EXIT_SUCCESS;
}
