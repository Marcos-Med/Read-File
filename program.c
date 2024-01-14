#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "list.h"
#include "arvore.h"

#include <locale.h>

#define TAMANHO 1000

int main(int argc, char ** argv){

	setlocale(LC_ALL,"pt_BR");

	FILE * in;
	FILE * in_one;
	

	LISTA * lista;
	Arvore_binaria * arvore;
	char * indice;

	clock_t tempoInicial, tempoFinal;
    double tempoGasto;

	int a = argc;
	
	if(argc == 3) {
		tempoInicial = clock();
		in = fopen(argv[1], "r");
		if(strcmp(argv[2], "lista") == 0){
			lista = construir_indexador_lista(in);
			indice = "lista";
		}
		else if(strcmp(argv[2], "arvore") == 0){
			//....
			arvore = construir_indexador_arvore(in);
			indice = "arvore";
		}
		else{
			printf("Invalido!\n");
			return 1; //Opção Inválida!
		}

		printf(">>>>> Carregando arquivo...\n");
		printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);
		printf("Numero de linhas no arquivo: %d\n", numero_linhas_file(argv[1]));

		tempoFinal = clock();
        tempoGasto = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC; 
        printf("Tempo para carregar o arquivo e construir o indice: %f ms.\n", tempoGasto);
		
		char input[100];
		char **arguments = (char**) malloc(2 *sizeof(char*));
		char * aux;
		int i;
		
		
		if(strcmp(indice, "lista") == 0){
			do{
				printf("> ");
				fgets(input, sizeof(input), stdin);
				i = 0;
				aux = strtok(input, " ");
				while(aux != NULL){
					arguments[i] = aux;
					aux = strtok(NULL, " ");
					i++;
				}

				arguments[1] = strtok(arguments[1], " ");

				if(strcmp(arguments[0], "busca") != 0 && strcmp(arguments[0], "fim\n") != 0){
					printf("Opção Inválida\n");
				}
				else{
					int j;
					for(j = 0; arguments[1][j] != '\0'; j++);
					char * arg_aux = (char*) malloc((j-1) * sizeof(char));
					for(int i = 0; i < j; i++){
						arg_aux[i] = arguments[1][i];
					}
					arg_aux[j-1] = '\0';

					string_lower(arg_aux);
					
					if(strcmp(arguments[0], "busca") == 0){
						tempoInicial = clock();
						Word_Struct * word = busca_palavra(arg_aux, lista);
						if(word){
							imprimir(word, argv[1]);
						}
						else{
							printf("Palavra '%s' não encontrada\n", arg_aux);
						}
						tempoFinal = clock();
				    	tempoGasto = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC; 
				   	 	printf("Tempo de busca: %f ms.\n", tempoGasto);
					}
					
				}

			}while(strcmp(arguments[0], "fim\n"));
		} 
        else {
			do{
				printf("> ");
				fgets(input, sizeof(input), stdin);
				i = 0;
				aux = strtok(input, " ");
				while(aux != NULL){
					arguments[i] = aux;
					aux = strtok(NULL, " ");
					i++;
				}

				arguments[1] = strtok(arguments[1], " ");

				if(strcmp(arguments[0], "busca") != 0 && strcmp(arguments[0], "fim\n") != 0){
					printf("Opção Inválida\n");
				}
				else{
					int j;
					for(j = 0; arguments[1][j] != '\0'; j++);
					char * arg_aux = (char*) malloc((j-1) * sizeof(char));
					for(int i = 0; i < j; i++){
						arg_aux[i] = arguments[1][i];
					}
					arg_aux[j-1] = '\0';

					string_lower(arg_aux);

					if(strcmp(arguments[0], "busca") == 0){
						tempoInicial = clock();
						NO_ARVORE * word = busca_palavra_arvore(arg_aux, arvore->raiz);
						if(word){
							imprimir_elemento(word, argv[1]);
						}
						else{
							printf("Palavra '%s' não encontrada\n", arg_aux);
						}
						tempoFinal = clock();
				    	tempoGasto = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC; 
				    	printf("Tempo de busca: %f ms.\n", tempoGasto);
					}
					
				} 
			}
			while(strcmp(arguments[0], "fim\n"));
		}    


		return 0;
	}

	return 1;
}