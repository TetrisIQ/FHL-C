/*
 * Main.c
 *
 *  Created on: 22.06.2017
 *      Author: alex
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "wortliste.h"

int main(void) {
    FILE* file;
    char filename[100];
//    int b;      //abbruch int für die 2 schleife
    printf("Welche datei soll Verarbeitet werden. (absoluter Pfad)\n");
    // Dateiname einlesen
    fgets(filename, 100, stdin);
    // das \n aus Dateinamen entfernen
    filename[strcspn(filename, "\n")] = 0;
    file = fopen(filename, "r"); //oeffnen zum Lesen

    if (file == NULL) {
        printf("Fehler Datei konnte nicht gelesen werden!");
        exit(EXIT_FAILURE);
    }    // FEHLER Datei kann nicht geoeffnet werden

    wordlist(file);
//    printf("%f ", file);
}

