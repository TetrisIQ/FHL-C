/*
 * Main.c
 *
 *  Created on: 20.06.2017
 *      Author: alex
 */

#include "caesar.h"
#include "anacae.h"
#include <stdio.h>


int main(void) {
	char text[] = "abcdefgh";
//	char text[] = "Bmmf Nfotdifo tjoe gsfj voe hmfjdi bo Xvfsef voe Sfdiufo hfcpsfo.Tjf tjoe nju Wfsovogu voe Hfxjttfo cfhbcu voe	tpmmfo fjoboefs jn Hfjtuf efs Csvfefsmjdilfju cfhfhofo.";
	int offset = 9;

	caesar(text, offset);
	printf("%s \n", text);


		anacae(text);
		printf("%s \n", text);






}
