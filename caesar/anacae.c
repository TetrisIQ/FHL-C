/*
 * anacae.c
 *
 *  Created on: 20.06.2017
 *      Author: alex
 */

#include "anacae.h"
#include "caesar.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

//	101 || 69 ist e

void anacae(char* text) {
int textSize = StringLength(text);

findCharacterE(text, textSize);
}

char findCharacterE(char* text, int textSize) {
	int ret = 0;
	int i;
	char e, c;
	int a, b;
	while (text[i] != '\0') {
			c = toupper(encrypted[i]);
			indexInCharCounter = contains(chars, c, charCount);
			if (indexInCharCounter) {
				frequency[indexInCharCounter] = frequency[indexInCharCounter] + 1;
			}
			else {
				chars[charCount] = c;
				frequency[charCount] = 1;
				charCount++;
			}
			i++;
	}
		printf("%c ", e);
	i = 0;

	char offset = 'E' - e;
	caesar(text, offset);

	return ret;

}

int charRate(char* text, char c, int textSize) {
	int counter = 0;
	int i;
		for (i = 0; i <= textSize; i++) {
			if (text[i] == c) {
				counter++;
			}
		}
	return counter;

}

int StringLength(char* text) {
	int i = 0;
	while (text[i] != '\0') {
		i++;
	}
	return i;
}

