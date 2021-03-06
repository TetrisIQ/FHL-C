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

    int offset = 1;
    char text[101];
    char buffer[3];
    char choose[3];

    printf("========================================\n");
    printf("=       Ver/Ent - Schluesselung        =\n");
    printf("========================================\n\n");

    printf("Wähle 1 fuer Verschluesseln \nwähle 2 fuer Entschlüsseln\n");
    fgets(choose, 3, stdin);

    switch (choose[0]) {
        case '1': {
            //Verschlüüseln
            printf(
                    "Bitte gib ein Text ein. Es werden aber nur 100 zeichen eingelesen werden\n");
            //        fgets(text, 101, stdin);
            fgets(text, 101, stdin);
            printf(
                    "Bitte gib ein offset ein, um den der text verschoben werden soll\n");
            fgets(buffer, 3, stdin);
            sscanf(buffer, "%d", &offset);
            caesar(text, offset);
            printf("%s ", text);
        }
            break;
        case '2': {
            //entschlüsseln
            printf(
                    "Bitte gib einen zu entschlüsselenen text ein. Bitte beachte das er nicht länger als 100 Zeichen sein darf\n");
            fgets(text, 101, stdin);
            anacae(text);
            printf("%s ", text);
        }
            break;
        case '3': {
            char newText[] =
                    "Bmmf Nfotdifo tjoe gsfj voe hmfjdi bo Xvfsef voe Sfdiufo hfcpsfo.Tjf tjoe nju Wfsovogu voe Hfxjttfo cfhbcu voe      tpmmfo fjoboefs jn Hfjtuf efs Csvfefsmjdilfju cfhfhofo.";
            anacae(newText);
            printf("%s ", newText);
            printf("\nAllgemeine Erklärung der Menschenrechte");
        }
            break;
        default:
            printf("Falsche eingabe");
    }

}
