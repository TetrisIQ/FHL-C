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

char findMax(char s[]);
double avgArray(int values[], size_t count);
int exists(int values[], size_t count, int (*fkt)(int));
int capsFile(char* filename);
int maxList(Listnode* head);
Listnode* addFront(Listnode* head, int item);
void freeList(Listnode* head);
int is42(int x);

/* Es folgen die Aufgaben */
// **************************
// Aufgabe 1 (15 Punkte)
/**
 * Bestimmt den haeufigsten Buchstaben in der Zeichenkette s
 * @param s Zeichenkette
 * @return Haeufigster Buchstabe in s
 */
char findMax(char s[]) {
    int i, j = 0;
    int buchstaben[26] = {0};
    int max = 0;
    char ret[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            buchstaben[(s[i] - 'A')]++;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            buchstaben[(s[i] - 'a')]++;
        }
    }

    for (i = 0; i < 26 ; i++) {
        if (buchstaben[i] > max) {
            max = buchstaben[i];
            j = i;
        }
    }
    return ret[j];
}
// Aufgabe 2 (10 Punkte)

/**
 * Bestimmt den Durchschnittswert der Elemente im uebergebenen Array
 * @param values Array der zu summierenden Elemente
 * @param count Anzahl der Elemente in dem Array values
 * @return Durchschnittswert der Elemente
 */
double avgArray(int values[], size_t count) {
    int i = 0;
    int sum;
    for (i = 0; i < count; i++) {
        sum += values[i];
    }
    return (double) sum / count;

}

// Aufgabe 3 (15 Punkte)

/**
 * Wendet auf jedes Element eines int-Arrays eine Funktion an. Die angewendete
 * Funktion muss fuer jedes Element des int-Array 0 (falsch) oder 1 (wahr) liefern.
 * Falls die angewendete Funktion fuer ein Array-Element (wahr) 1 liefert, dann liefert
 * die exists auch wahr. Andernfalls liefert exists falsch.
 * Hinweis: is42 waere eine moegliche solche Funktion fkt.
 * @param values Array von int-Werten
 * @param count Anzahl der Elemente in values
 * @param fkt Funktionspointer auf die anzuwendende Funktion
 * @return 1 falls fkt fuer ein Elemet wahr liefert und 0 sonst.
 */
int exists(int values[], size_t count, int (*fkt)(int)) {
    int i = 0;
    int ret = 1;
    for (i = 0; i < count; i++) {
        if (ret == 0) {
            return ret;
        }
        ret = fkt(values[i]);
    }
    return ret;
}

// Aufgabe 4 (20 Punkte)

/**
 * Die Funktion ermittelt ob die Anzahl der Grossbuchstaben oder der Kleinbuchstaben
 * in der uebergebenen Datei groesser ist.
 * Dazu oeffnet die Funktion die Datei mit fopen
 * liest die Datei zeichenweise mit fgetc ein bis das Ergebnis
 * EOF ist und schliesst die Datei mit fclose
 * Hinweis: Umlaute / Sonderzeichen koennen wie immer unberuecksichtigt bleiben
 * @param filename Dateiname
 * @return wahr falls es mehr Grossbuchstaben als Kleinbuchstaben gibt, falsch sonst
 */
int capsFile(char* filename) {
    int grossBuchstabe = 0;
    int kleinBuchstabe = 0;
    char c;
    FILE* file = fopen(filename, "r");
    do {
        c = fgetc(file);
        if (c >= 'A' && c <= 'Z') {
            grossBuchstabe++;
        }
        if (c >= 'a' && c <= 'z') {
            kleinBuchstabe++;
        }
    } while (c != EOF);

    if (kleinBuchstabe > grossBuchstabe) {
        return 0;
    } else {
        return 1;
    }
}

// Aufgabe 5 (20 Punkte)

/**
 * Bestimmt den maximalen Wert der in der verketteten Liste
 * gespeicherten Werte.
 * @param head Zeiger auf das erste Element der Liste
 * @return Maximaler Wert in Liste falls Liste nicht leer und INT_MIN sonst.
 */
int maxList(Listnode* head) {
    int max = 0;
    Listnode* newHead = head;
    do {
        if (newHead->data > max) {
            max = newHead->data;
        }
    }while (newHead->next != NULL);
    return max;
}

// Aufgabe 6 (20 Punkte)

// Eine Pruefungsliste soll in C verwaltet werden
// Erstellen Sie einen typedef Pruefung fuer eine Struktur.
// In der Stuktur sollen das Fach und seine Note
// enthalten sein.
// Erstellen Sie eine Funktion mkPr(fach, note), die eine solche Struktur
// auf dem Heap erzeugt und die Eintraege der Struktur den Parametern
// entsprechend fuellt. Die Funktion soll dann einen Zeiger auf die
// Struktur zurueckgeben.

typedef struct Pruefungsliste_ {
    char* fach;
    double note;
} Pruefungsliste;

Pruefungsliste* mkPr(char* fach, double note) {
    Pruefungsliste* newPr = (Pruefungsliste*) malloc(sizeof(Pruefungsliste));
    newPr->fach = fach;
    newPr->note = note;
    return newPr;
}

// Aufgabe 7 (20 Bonuspunkte)

/**
 * Die Funktion mix mischt zwei Zeichenketten fair. Aus Christiane und Max wird
 * CMharxistiane.
 * @param src1 Erster zu mischender String
 * @param src2 Zweiter zu mischender String
 * @param dest Zielpuffer fuer das Ergebnis.
 * Der Puffer muss mindestens strlen(src1) + strlen(src2) + 1 Zeichen
 * aufnehmen koennen.
 */

// Ende der Aufgaben
// Die folgenden Hilfsfunktionen koennen Ihnen helfen, falls
// Sie Ihren Code testen moechten.
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

int is42(int x) {
    return x == 42;
}

int main(void) {
}
