/*
 * Ggt.c
 *
 *  Created on: 02.06.2017
 *      Author: alex
 */

#include <stdio.h>

int prim(int a, int b);
int mainGgt(void) {

	char buffer[21]; // Eingabepuffer
//	char buffer1[21]; // Eingabepuffer
	int a = 0; // Eingabe n
	int b = 0;
	printf("Der grösste gemeinsame von: "); // Ausgabprintf("Eingabe n:");
	fgets(buffer, 21, stdin); // Einlesen von sscanf(buffer, "%d", &n);
	sscanf(buffer, "%d", &a);
	printf("und: "); // Ausgabprintf("Eingabe n:");
	fgets(buffer, 21, stdin); // Einlesen von sscanf(buffer, "%d", &n);
	sscanf(buffer, "%d", &b);
	//noch primfaktor zerlegung soll noch ggt werden :D
	int ret = prim(a, b);
	printf(" %c" , ret);
	return 0;
}

int prim(int a, int b) {
	int i = 1; //abbruchbedingung der while schleife 1 == true
	int prima = 2;
	int primb = 2;
	int anzahla = 0;
	int anzahlb = 0;
	int ret = 0;

	while (i) {
		//für a
		while (!a % prima == 0) {
			prima++;
			anzahla = 0;
		}
		while (a % prima == 0) {
			a = a / prima;
			anzahla++;
		}
		//für b
		while (!b % primb == 0) {
			primb++;
			anzahlb = 0;
		}
		while (b % primb == 0) {
			b = b / primb;
			anzahlb++;
		}

		if ((prima ^ anzahla) >= (primb ^ anzahlb)) {
			ret = prima ^ anzahla;
		}

		if (a < prima || b < primb) {
			i = 0;
		} else {
			i = 1;
		}

	}

	return ret;
}
