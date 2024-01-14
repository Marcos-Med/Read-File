#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAMANHO 1000

typedef int booleano;

typedef struct no{
    int line;
    struct no * prox;
} NO;

typedef struct{
    NO * first_no;
} Lista_Lines;

typedef struct element
{
    char * word;
    int ocorrencias;
    Lista_Lines * lines;
    struct element * prox;
    
} Word_Struct;

typedef struct list
{
    Word_Struct * first_no;
    Word_Struct * last_no;
    
} LISTA;



void string_lower(char string[]){
    for(int i = 0; string[i] != '\0'; i++){
        string[i] = tolower(string[i]);
    }
}

LISTA * criar_lista(){
    LISTA * lista = (LISTA*) malloc(sizeof(LISTA));
    lista->first_no = NULL;
    lista->last_no = NULL;
    return lista;
}

void criar_palavra(char string[], LISTA * lista, int line){
    Word_Struct * palavra = (Word_Struct*) malloc(sizeof(Word_Struct));
    palavra->word = strdup(string);
    palavra->ocorrencias = 1;
    palavra->lines = (Lista_Lines*) malloc(sizeof(Lista_Lines));
    palavra->lines->first_no = (NO*) malloc(sizeof(NO));
    palavra->lines->first_no->line = line;
    palavra->lines->first_no->prox = NULL;
    palavra->prox = NULL;
    
    printf("%s\n", palavra->word);

    if(lista->first_no){
        if(lista->first_no->prox){
            lista->last_no->prox = palavra;
            lista->last_no = palavra;
        }
        else{
            lista->last_no = palavra;
            lista->first_no->prox = lista->last_no;
        }
    }
    else{
        lista->first_no = palavra;
    }

}

void inserir_palavra(char string[], LISTA * lista, int line){
   booleano flag = 0;
    for(Word_Struct * p = lista->first_no; p != NULL; p = p->prox){
        if(strcmp(p->word, string) == 0){
            p->ocorrencias++;
            for(NO * aux = p->lines->first_no;aux != NULL; aux = aux->prox){
                if(aux->line == line){
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                NO * no_line = (NO*) malloc(sizeof(NO));
                no_line->line = line;
                no_line->prox = NULL;
                if(p->lines->first_no){
                    NO * antecessor;
                    for(NO *aux = p->lines->first_no; aux != NULL; aux = aux->prox){
                        antecessor = aux;
                    }
                    antecessor->prox = no_line;

                }
                else{
                    p->lines->first_no = no_line;
                }
            }

            flag = 1;
            break;
            
        }
    }

    if(!flag){
        criar_palavra(string, lista, line);
    }

}

Word_Struct * busca_palavra(char string[], LISTA * lista){
    for(Word_Struct * p = lista->first_no; p != NULL; p = p->prox){
        if(strcmp(string, p->word) == 0){
            return p;
        }
    }

    return NULL;
}

void imprimir(Word_Struct * word, char arg[]){

    int contador_linha = 0;
    NO * aux = word->lines->first_no;
    FILE * in = fopen(arg, "r");

   if(word){
      if(word->ocorrencias == 1){
        printf("Existe 1 ocorrência da palavra '%s' na seguinte linha:\n", word->word);
      }
      else{
        printf("Existem %d ocorrências da palavra '%s' na(s) seguinte(s) linha(s):\n", word->ocorrencias, word->word);
      }

      char * linha = (char*) malloc(sizeof(char) * (TAMANHO + 1));

      while(in && fgets(linha, TAMANHO, in)){
        contador_linha++;
        if(aux){
            if(contador_linha == aux->line){
            printf("linha %03d: '%s'\n", contador_linha, linha);
            aux = aux->prox;
        }
        }
        else{
            break;
        }

      }
   } 

}

LISTA * construir_indexador_lista(FILE * in){
    LISTA * lista = criar_lista();
    char * linha = (char *) malloc((TAMANHO + 1) * sizeof(char));
    char * palavra;
    int contador_linha = 0;
    while(in && fgets(linha, TAMANHO, in)){
         contador_linha++;
         palavra = strtok(linha, " -,.;:()'\"!?/");
         while(palavra != NULL){
            
            string_lower(palavra);
            //printf("%s\n", palavra);
            inserir_palavra(palavra, lista, contador_linha);
            palavra = strtok(NULL, " -,.;:()'\"!?/");
            
         }
    }

    return lista;
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