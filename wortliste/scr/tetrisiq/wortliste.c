/*
 * wortliste.c
 *
 *  Created on: 22.06.2017
 *      Author: alex
 */

#include "wortliste.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void wordlist(FILE* file) {
    int i;
    char c;
    char* text;
    char* tmp;
//    int charSizeOfFile = countCharInFile(file);
    /*
     wie bekomm ich die größe des files es Kann teoretisch ja jedes wort nur einmal vorkommen
     also kann ich im schlechtesten fall das gesamte file widergeben um kein speicher
     zwischendrinn neu zu erstellen, will ich einfach einspeicher erstellen der so groß ist
     wie das file selbst. Dann hab ich keine probleme mit dem speicher.
     */
//    if (NULL == (text = malloc((charSizeOfFile * sizeof (char))))) {
//        exit(EXIT_FAILURE);
//    }
//
//    if (NULL == (tmp = malloc((charSizeOfFile * sizeof (char))))) {
//        exit(EXIT_FAILURE);
//    }
    if (NULL == (text = malloc((file)))) {
        exit(EXIT_FAILURE);
    }

    if (NULL == (tmp = malloc((file)))) {
        exit(EXIT_FAILURE);
    }

    while (1) {
        i = -1;
        do {
            if (c == EOF) {     //abbruch bedingung in der Funktion
                printf(text);   //ausgabe des distincten textes
                free(tmp);
                free(text);     //freigeben der speicherblöcke
                return;         //return
            }
            i++;
            c = fgetc(file);    //nimmt das erste zeichen aus dem file
            tmp[i] = c;
            if (tmp[i] == ' ' || tmp[i] == '.' || tmp[i] == ','
                    || tmp[i] == '\n') { // die möglichen abschlüsse eines wortes
                tmp[i] = '\n'; // zur schöneren darstellung hänge ich ein absatz drann
                tmp[++i] = '\0';                //abschließend die \0
            }
        } while (tmp[i] != '\0');               //Überprüft auf wort ende

        if (strstr(text, tmp) == NULL) { //überprüft ob der String tmp im String text vorhanden ist
            strcat(text, tmp);
        }

    }

}

int countCharInFile(FILE* file) {
    int count = 0;
    char c;
    while (c != EOF) {
        c = fgetc(file);
        if (c == EOF) {
            return count;
        }
        count++;
    }
    return count;
}
