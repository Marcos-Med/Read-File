#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void remover_pontuacao(char *palavra) {
    int i, j;

    // Percorre a palavra e mantém apenas os caracteres alfabéticos
    for (i = 0, j = 0; palavra[i] != '\0'; i++) {
        if (isalpha(palavra[i])) {
            palavra[j++] = tolower(palavra[i]);
        }
    }

    // Adiciona o caractere nulo de término da string
    palavra[j] = '\0';
}

int main() {

    setlocale(LC_ALL, "pt_BR");

    char palavra[] = "Opinião,";  // Exemplo de palavra com pontuação
    printf("Palavra original: %s\n", palavra);

    // Chama a função para remover pontuação
    remover_pontuacao(palavra);

    printf("Palavra sem pontuação: %s\n", palavra);

    return 0;
}