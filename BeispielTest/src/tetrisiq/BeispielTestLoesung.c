/*
 * BeispielTest.c
 *
 *  Created on: 27.06.2017
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

/* Es folgen die Aufgaben */            //insgesammt 80 punkte
// **************************
// Aufgabe 1 (10 Punkte)
/**
 * Bestimmt die Anzahl der Vorkommen des Buchstabens 'a' in der
 * Zeichenkette s
 * @param s Zeichenkette
 * @return Anzahl der Vorkommen von 'a'
 */
int counta(char s[]) {
    int counter = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a') {
            counter++;
        }
    }
    return counter;

}

// Aufgabe 2 (15 Punkte)

/**
 * Bestimmt die Summe der Elemente im uebergebenen Array
 * @param values Array der zu summierenden Elemente
 * @param count Anzahl der Elemente in dem Array values
 * @return Summe der Elemente
 */
int sumArray(int values[], size_t count) {
    int sum = 0;
    int i;
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
        values[i] = fkt(values[i]);
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

    filename[strcspn(filename, "\n")] = 0;
    FILE* file = fopen(filename, "r");
    char c;
    int counter = 0;
    while (c != EOF) {
        c = fgetc(file);
        if (c == 'A' || c == 'a') {
            counter++;
        }
    }
    return counter;
    fclose(file);
}

// Aufgabe 5 (20 Punkte)

/**
 * Bestimmt den Durchschnittswert der in der verketteten Liste
 * gespeicherten Werte.
 * @param head Zeiger auf das erste Element der Liste
 * @return Durchschnitt der gespeicherten Werte.
 */
double avgList(Listnode* head) {
    double sum = 0;
    int elemets = 0;
    Listnode* cur = head->next;
    while (cur != NULL) {
        int tmp = cur->data;
        sum += tmp;
        elemets++;
        cur = cur->next;
    }
    return sum / elemets;
}

// Aufgabe 6 (20 Punkte)

// Ein Reiseplan soll in C verwaltet werden
// Erstellen Sie einen typedef Station fuer eine Struktur,
// die eine Station auf der Reise abbildet.
// In der Stuktur sollen Reisetag und Reiseziel
// enthalten sein.
// Erstellen Sie eine Funktion mkSt(tag, ziel), die eine solche Struktur
// auf dem Heap erzeugt und die Eintraege der Struktur den Parametern
// entsprechend fuellt. Die Funktion soll dann einen Zeiger auf die
// Struktur zurueckgeben.

//    typedef struct waypoint_ {  //der stationsname darf nicht länger als 100 zeichen sein
//        char[100] stationsname;
//        int ReiseTag;
//    } station;
//
//    station* mkSt(int tag, char[] name) {
//
//    }

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
    printf("counta, %d \n", counta("aaaaabbaabccc"));
    int values[] = {
    1, 2, 3, 4, 5, 6
    };
    printf("Summe: %d \n", sumArray(values, 6));
//    char filename[] ="/home/alex/test.txt";
//    printf("countFileA: %d", countAFile(filename));
    int v[] = {
    1, 6, -3, 6, 0
    };

    Listnode* head = NULL;
    int i = 0;
    for (i = 0; i < sizeof(v) / sizeof(int); i++)
        head = addFront(head, v[i]);
    printf("Durchschnitt %f\n", avgList(head));

}

//int mainTest(void) {
//    char s[] = "analys
//is";
//    int v[] = {
//    1, 6, -3, 6, 0
//    };
//    int i = 0;
//    Listnode* head = NULL;head
//    printf("%s %d\n", s, counta(s));
//    printf("%d = %d\n", 10, sumArray(v, sizeof(v) / sizeof(int)));
//    for (i = 0; i < sizeof(v) / sizeof(int); i++)
//        printf("%d ", v[i]);
//    printf(" == quad ==> ");
//    applyFkt(v, sizeof(v) / sizeof(int), quad);
//    for (i = 0; i < sizeof(v) / sizeof(int); i++)
//        printf("%d ", v[i]);
//    printf("\n");
//    for (i = 0; i < sizeof(v) / sizeof(int); i++)
//        head = addFront(head, v[i]);
//    printf("Durchschnitt %f\n", avgList(head));
//    freeList(head);
//    return EXIT_SUCCESS;
//}
