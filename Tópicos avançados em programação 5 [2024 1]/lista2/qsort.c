#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara(const void *a, const void *b){
    return (*(char*)a - *(char*)b); // maior que 1 = troca, menor que 0 não troca
}


int main(){
    char string[200001];
    scanf("%s", string);

    qsort(string, strlen(string), sizeof(char), compara);

    printf("%s", string);
    return 0;
}

