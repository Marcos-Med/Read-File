#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAMANHO 1000

typedef int booleano;

typedef struct no_lista{
    int line;
    struct no_lista * prox;
    
} NO_LINHA;

typedef struct{
    NO_LINHA * fisrt_line;
} LISTA_LINHA;

typedef struct no_arvore{
    char * string;
    int ocorrencias;
    struct no_arvore * esqueda;
    struct no_arvore * direita;
    LISTA_LINHA * lines;
} NO_ARVORE;

typedef struct {
    NO_ARVORE * raiz;
} Arvore_binaria;


Arvore_binaria * criar_arvore(){
    Arvore_binaria * arvore = (Arvore_binaria *) malloc(sizeof(Arvore_binaria));
    arvore->raiz = NULL;
    return arvore;
}

void inserir_rec(NO_ARVORE * word, NO_ARVORE * no_prox){
    if(strcmp(no_prox->string, word->string) < 0){
        if(no_prox->direita){
            inserir_rec(word, no_prox->direita);
        }
        else{
            no_prox->direita = word;
            
        }
    }else{
        if(no_prox->esqueda){
            inserir_rec(word, no_prox->esqueda);
        }
        else{
            no_prox->esqueda = word;
        }
    }
}

void criar_palavra_arvore(char string[], Arvore_binaria * arvore, int line){
   
    NO_ARVORE * palavra = (NO_ARVORE*) malloc(sizeof(NO_ARVORE));
    palavra->string = strdup(string);
  
    palavra->ocorrencias = 1;
    
    palavra->lines = (LISTA_LINHA *) malloc(sizeof(LISTA_LINHA));
    
    palavra->lines->fisrt_line = (NO_LINHA *) malloc(sizeof(NO_LINHA));

    palavra->lines->fisrt_line->line = line;
    
    palavra->lines->fisrt_line->prox = NULL;
    
    palavra->esqueda = NULL;
    
    palavra->direita = NULL;
    
    if(arvore->raiz){
        inserir_rec(palavra, arvore->raiz);
    }
    else{
        arvore->raiz = palavra;
    }
}

NO_ARVORE * busca_palavra_arvore(char string[], NO_ARVORE * no_prox){
    NO_ARVORE * aux = no_prox;
    if(strcmp(string, "") == 0){
        return NULL;
    }
    while(aux != NULL){
        if(strcmp(string,aux->string ) == 0){
            return aux;
        }
        else if(strcmp(string, aux->string) < 0){
            aux = aux->esqueda;
        }
        else{
            aux = aux->direita;
        }
    }

    return NULL;
}

void inserir_palavra_arvore(char string[], Arvore_binaria * arvore, int line){
    booleano flag = 0;//FALSE
    NO_ARVORE * palavra = busca_palavra_arvore(string, arvore->raiz);
    NO_LINHA * antecessor;
    if(palavra){
        palavra->ocorrencias++;
        for(NO_LINHA * aux = palavra->lines->fisrt_line; aux != NULL; aux = aux->prox){
            if(aux->line == line){
                flag = 1;//TRUE
                break;
            }
            antecessor = aux;
        }
        if(!flag){
            antecessor->prox = (NO_LINHA*) malloc(sizeof(NO_LINHA));
            antecessor->prox->line = line;
            antecessor->prox->prox = NULL;
        }
    }
    else{
        criar_palavra_arvore(string, arvore, line);
    }
}

Arvore_binaria * construir_indexador_arvore(FILE * in){
    Arvore_binaria * arvore = criar_arvore();
    char * linha = (char *) malloc((TAMANHO + 1) * sizeof(char));
    char * palavra;
    int contador_linha = 0;
    while (in && fgets(linha, TAMANHO, in))
    {
        contador_linha++;
        palavra = strtok(linha, " -,.;:()'\"!?/");
        while(palavra != NULL){
            string_lower(palavra);
            palavra = retirar_enter(palavra);
            inserir_palavra_arvore(palavra, arvore, contador_linha);
            palavra = strtok(NULL, " -,.;:()'\"!?/");
        }
    }

    
    return arvore;
}

void imprimir_elemento(NO_ARVORE * word, char arg[]){
    int contador_linha = 0;
    NO_LINHA * aux = word->lines->fisrt_line;
    FILE * in = fopen(arg, "r");
    if(word){
        if(word->ocorrencias == 1){
            printf("Existe 1 ocorrência da palavra '%s' na seguinte linha:\n", word->string);
        }
        else{
            printf("Existem %d ocorrências da palavra '%s' na(s) seguinte(s) linha(s):\n", word->ocorrencias, word->string);
        }

        char * linha = (char*) malloc(sizeof(char) * (TAMANHO + 1));

        while(in && fgets(linha, TAMANHO, in)){
           contador_linha++;
            if(aux){
               if(contador_linha == aux->line){
                 printf("linha %03d: %s\n", contador_linha, linha);
                 aux = aux->prox;
               }
            }
            else{
              break;
            }

      }
    }
}