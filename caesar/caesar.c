/*
 * caesar.c
 *
 *  Created on: 20.06.2017
 *      Author: alex
 */

#include "caesar.h"
#include <stdio.h>

void caesar(char text[], char offset) {
	unsigned int i = 0;
	int j = 0;
	for (i = 0;; i++) {
		if (text[i] != '\0') {
			if ((text[i] >= 65 && text[i] <= 90)
					|| (text[i] >= 97 && text[i] <= 122)) { // überprüfung auf A-Z oder a-z
				for (j = 0; j < offset; j++) { // erhöhen um offset

					if (text[i] == 90) { // falls das Zeichen Z ist / setzen wir auf @
						text[i] = 64;
					}
					if (text[i] == 122) { //falls das Zeichen z ist /setzen wir auf ,
						text[i] = 96;
					}

					text[i] += 1;
				}

			}else {
				break;
			}
		}
	}

//	unsigned int i = 0;
//	int j = 0;
//	for (i = 0;; i++) {
//		if (text[i] != '\0') {
//			if ((text[i] > 64 && text[i] < 91)
//					|| (text[i] > 96 && text[i] < 123)) {
//				for (j = 0; j < offset; j++) {
//					if (text[i] == 90) {
//						text[i] = 65;
//						text[i] -= 1;
//					}
//					if (text[i] == 122) {
//						text[i] = 97;
//						text[i] -= 1;
//					}
//					text[i] += 1;
//				}
//			}
//		} else {
//			break;
//		}
//	}
}

