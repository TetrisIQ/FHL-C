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
    int i, j;
    char c;
    char* text;
    char* tmp;
    if (NULL == (text = malloc(sizeof(file)))) {
        exit(EXIT_FAILURE);
    }

    if (NULL == (tmp = malloc(sizeof(file)))) {
        exit(EXIT_FAILURE);
    }

    for (i = 0; c != EOF; i++) {
        c = fgetc(file);
        tmp[i] = (c);
        if (c == ' ') {
            tmp[i] = '\n';
            if (strstr(tmp, text) != NULL ) {
                strcat(text, tmp);

            }
            j++;
            i = 0;
        }
    }





       if (c == EOF) { // Dateiende
           printf("ende");
       }
}




