#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 1000

void string_lower(char string[]){
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = tolower(string[i]);
    }
}

int numero_linhas_file(char arg[]){
    char * linha = (char *) malloc((TAMANHO + 1) * sizeof(char));
    FILE * in;
    int contador_linha = 0;
   
   in = fopen(arg, "r");

    while(in && fgets(linha, TAMANHO, in)){
        contador_linha++;
    }

    return contador_linha;
}

char * retirar_enter(char * palavra){
    int i;
    for(i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] == '\n'){
            break;
        }
    }

    char * new_palavra = (char*) malloc((i+1)*sizeof(char));
    for(int j = 0; j < i; j++){
        new_palavra[j] = palavra[j];
    }
    new_palavra[i] = '\0';
    return new_palavra;
}

