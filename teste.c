#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(){

    SetConsoleOutputCP(CP_UTF8);

    char string_one[] = "marcos";

    char string_two[] = "marcos";

    if(strcmp(string_one, string_two) == 0){
        printf("São iguais");
    }
    else{
        printf("São diferentes");
    }


    return 0;
}