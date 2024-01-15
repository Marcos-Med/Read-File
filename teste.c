#include <stdio.h>
#include <string.h>
#include <windows.h>

void tratarString(char palavra[]) {
  unsigned int i, k = 0;
  char comAcentos[] = "ÄÅÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛüúûùÇç";
  char semAcentos[] = "AAAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUuuuuCc";
  //Removendo acentos
  for (k = 0; k < strlen(palavra); k++) {

  for (i = 0; i < strlen(comAcentos); i++) {
  if (palavra[k] == comAcentos[i]) {
  palavra[k] = semAcentos[i];
  printf("%c", comAcentos[i]);
  printf("\n");
  }
  }
  }
    }

int main(){

    SetConsoleOutputCP(CP_UTF8);

    char string_one[] = "Você é legal";

    tratarString(string_one);

    printf("%s\n", string_one);
    

    return 0;
}