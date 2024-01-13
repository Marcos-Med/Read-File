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
	char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha;

	LISTA * lista;
	char * indice;

	clock_t tempoInicial, tempoFinal;
    double tempoGasto;

	if(argc == 2) {
		tempoInicial = clock();
		if(argv[2] == "lista"){
			lista = construir_indexador_lista(in);
			indice = "lista";
		}
		else if(argv[2] == "arvore"){
			//....
			indice = "arvore";
		}
		else{
			return 1; //Opção Inválida!
		}

		in = fopen(argv[1], "r");

		printf(">>>>> Carregando arquivo...\n");
		printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);
		printf("Numero de linhas no arquivo: %d", numero_linhas_file(in));

		tempoFinal = clock();
        tempoGasto = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC; 
        printf("Tempo para carregar o arquivo e construir o indice: %f ms.", tempoGasto);
		
		char * input;
		char **arguments = (char**) malloc(2 *sizeof(char*));
		
		
		if(strcmp(indice, "lista") == 0){
			do{
				printf("> ");
				scanf("%s", input);
				for(int i = 0; i < 2; i++){
					arguments[i] = strtok(input, " ");
				}
				if(strcmp(arguments[0], "busca") != 0 || strcmp(arguments[0], "fim") != 0){
					printf("Opção Inválida\n");
				}
				else{
					tempoInicial = clock();
					if(strcmp(arguments[0], "busca") == 0){
						Word_Struct * word = busca_palavra(arguments[1], lista);
						if(word){
							imprimir(word, in);
						}
						else{
							printf("Palavra '%s' não encontrada\n", arguments[1]);
						}
						
					}
				}

				tempoFinal = clock();
				tempoGasto = (tempoFinal - tempoInicial) * 1000.0 / CLOCKS_PER_SEC; 
				printf("Tempo de busca: %f ms.", tempoGasto);
			}while(strcmp(arguments[0], "fim"));
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