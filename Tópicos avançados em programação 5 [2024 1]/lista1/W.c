#include <stdio.h>

int makeone(char* string, int m){
    int i;
    int o = 0;
    int indiceO;
    int n = 0;
    int indiceN;
    int e = 0;
    int indiceE;
    for(i=0; i<m; i++){
        if(string[i] == 'o'){
            //printf("pegou[%c][%d]\n", string[i], i);
            indiceO = i;
            o++;
        }
        if(string[i] == 'n'){
            //printf("pegou[%c][%d]\n", string[i], i);
            indiceN = i;
            n++;
        }
        if(string[i] == 'e'){
            //printf("pegou[%c][%d]\n", string[i], i);
            indiceE = i;
            e++;
        }
    }
    if((o && n) && e){
        string[indiceO] = '*';
        string[indiceN] = '*';
        string[indiceE] = '*';
        return 1;
    } else {
        return 0;
    }
}

int makezero(char* string, int m){
    int i;
    int z = 0;
    int indiceZ;
    int e = 0;
    int indiceE;
    int r = 0;
    int indiceR;
    int o = 0;
    int indiceO = 0;
    for(i=0; i<m; i++){
        if(string[i] == 'z'){
            //printf("pegou[%c][%d]\n", string[i], i);
            indiceZ = i;
            z++;
        }
        if(string[i] == 'e'){
            //printf("pegou[%c][%d]\n", string[i], i);
            indiceE = i;
            e++;
        }
        if(string[i] == 'r'){
            //printf("pegou[%c][%d]\n", string[i], i);
            indiceR = i;
            r++;
        }
        if(string[i] == 'o'){
            //printf("pegou[%c][%d]\n", string[i], i);
            indiceO = i;
            o++;
        }
    }
    if(((z && e) && r) && o){
        string[indiceZ] = '*';
        string[indiceE] = '*';
        string[indiceR] = '*';
        string[indiceO] = '*';
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int n, i, j=0;
    scanf("%d", &n);

    char buffer;
    char string[n];
    char number[n];
    if(n==0){
        return 0;
    }
    getchar();

    for(i=0; i<n; i++){
        string[i] = getchar();
    }
    while(makeone(string,n)){
        number[j] = '1';
        //printf("%c\n", number[j]);
        j++;
    }
    while(makezero(string, n)){
        number[j] = '0';
        //printf("%c\n", number[j]);
        j++;
    }
    number[j] = '\0';
    j = 0;
    while(number[j] != '\0'){
        printf("%c ", number[j]);
        j++;
    }
    return 0;
}

