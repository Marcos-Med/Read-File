#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1;
#define FALSE 0;

typedef int boolean;

typedef struct element
{
    char * word;
    int ocorrencias;
    Lista_Lines * lines;
    struct element * prox;
    
} WORD;

typedef struct list
{
    WORD * first_no;
    WORD * last_no;
    
} LISTA;

typedef struct no{
    int line;
    struct no * prox;
} NO;

typedef struct{
    NO * first_no;
} Lista_Lines;


LISTA * criar_lista(){
    LISTA * lista = (LISTA*) malloc(sizeof(LISTA));
    lista->first_no = NULL;
    lista->last_no = NULL;
    return lista;
}

void criar_palavra(char string[], LISTA * lista, int line){
    WORD * palavra = (WORD*) malloc(sizeof(WORD));
    palavra->word = string;
    palavra->ocorrencias = 1;
    palavra->lines = (Lista_Lines*) malloc(sizeof(Lista_Lines));
    palavra->lines->first_no = (NO*) malloc(sizeof(NO));
    palavra->lines->first_no->line = line;
    palavra->lines->first_no->prox = NULL;
    palavra->prox = NULL;
    
    if(lista->first_no){
        lista->last_no = palavra;
        lista->first_no->prox = lista->last_no;
    }
    else{
        lista->first_no = palavra;
    }

}

void inserir_palavra(char string[], LISTA * lista, int line){
   boolean flag = FALSE;
    for(WORD * p = lista->first_no; p != NULL; p = p->prox){
        if(strcmp(p->word, string) == 0){
            p->ocorrencias++;
            for(NO * aux = p->lines->first_no;aux != NULL; aux = aux->prox){
                if(aux->line == line){
                    flag = TRUE;
                    break;
                }
            }
            if(!flag){
                NO * no_line = (NO*) malloc(sizeof(NO));
                no_line->line = line;
                no_line->prox = NULL;
                if(p->lines->first_no){
                    NO * antecessor;
                    for(NO *aux = p->lines->first_no->prox; aux != NULL; aux = aux->prox){
                        antecessor = aux;
                    }
                    antecessor->prox = no_line;

                }
                else{
                    p->lines->first_no = no_line;
                }
            }
            
        }
        else{
            criar_palavra(string, lista, line);
        }
    }

}