#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "list.h"

#define TAMANHO 1000

int main(int argc, char ** argv){

	SetConsoleOutputCP(CP_UTF8); //Configura o cmd para aceitar acentuação

	FILE * in;
	FILE * in_one;
	//char * linha;
	//char * copia_ponteiro_linha;
	//char * quebra_de_linha;
	//char * palavra;	
	//int contador_linha;

	LISTA * lista;
	char * indice;

	clock_t tempoInicial, tempoFinal;
    double tempoGasto;

	int a = argc;
	printf("%d\n", a);
	printf("Hello World!\n");

	if(argc == 3) {
		tempoInicial = clock();
		in = fopen(argv[1], "r");
		if(strcmp(argv[2], "lista") == 0){
			lista = construir_indexador_lista(in);
			indice = "lista";
		}
		else if(strcmp(argv[2], "arvore") == 0){
			//....
			indice = "arvore";
		}
		else{
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

				//for(Word_Struct * word = lista->first_no; word != NULL; word = word->prox){
					//printf("%s\n", word->word);
				//}			

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

					//printf("%d\n", strcmp(arg_aux, "design"));
					
					tempoInicial = clock();
					if(strcmp(arguments[0], "busca") == 0){
						Word_Struct * word = busca_palavra(arg_aux, lista);
						if(word){
							imprimir(word, argv[1]);
						}
						else{
							printf("Palavra '%s' não encontrada\n", arg_aux);
						}
						
					}
					tempoFinal = clock();
				    tempoGasto = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC; 
				    printf("Tempo de busca: %f ms.\n", tempoGasto);
				}

			}while(strcmp(arguments[0], "fim\n"));
		} 
        else {
			//.....
		}    


		/*contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));

		while(in && fgets(linha, TAMANHO, in)){
			
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

			printf("linha %03d: '%s'\n", contador_linha + 1, linha);

			// fazemos uma copia do endereço que corresponde ao array de chars 
			// usado para armazenar cada linha lida do arquivo pois a função 'strsep' 
			// modifica o endereço do ponteiro a cada chamada feita a esta função (e 
			// não queremos que 'linha' deixe de apontar para o inicio do array).

			copia_ponteiro_linha = linha;

			while( (palavra = strtok(copia_ponteiro_linha, "  -")) ){

				// antes de guardar a palavra em algum tipo de estrutura usada
				// para implementar o índice, será necessário fazer uma copia
				// da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
				// substring dentro da string 'linha', e a cada nova linha lida
				// o conteúdo da linha anterior é sobreescrito.

				printf("\t\t'%s'\n", palavra);
			}

			contador_linha++;
		}

		printf(">>>>> Arquivo carregado!\n");*/

		return 0;
	}

	return 1;
}