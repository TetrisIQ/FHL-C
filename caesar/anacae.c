/*
 * anacae.c
 *
 *  Created on: 20.06.2017
 *      Author: alex
 */

#include "anacae.h"
#include "caesar.h"
#include <stdio.h>
#include <string.h>
#define MAX 27

void anacae(char string[]) {
    int i = 0;
    int highestValue = 0;
    size_t size = strlen(string);
    char buffer[size];
    char anzahl[MAX];
    int often[MAX] = {
    0
    };
    int position = 0;
    strcpy(buffer, string);
    while (buffer[i] != '\0') {
        if (buffer[i] < 97) { //Quasi cast zum kleinbuchstaben
            buffer[i] += 32;
        }
        findMostUsed(buffer[i], anzahl, often);
        i++;

    }
    for (i = 0; i < MAX; i++) {
        if (often[i] > highestValue) {
            highestValue = often[i];
            position = i;

        }
    }
    highestValue = diffE(anzahl[position]);
    caesar(string, highestValue);
}

void findMostUsed(char buffer, char counts[], int often[]) {
    int i = 0;
    while (i < MAX) {
        if (buffer == counts[i]) {
            often[i] += 1;
            return;
        }
        i++;
    }
    i = 0;
    while (often[i] != 0) {
        i++;
    }
    if (i < MAX) {
        if (buffer != 64) {
            counts[i] = buffer;
            often[i] += 1;
        }
        return;
    }
}

int diffE(char letter) {
    int i = 0;
    int count = 0;
    for (i = letter; i != 101; i++) {
        if (i == 122) {
            i = 97;
            count++;
        }
        count++;
    }
    return count;

}
