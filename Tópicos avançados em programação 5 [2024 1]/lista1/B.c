#include <stdio.h>

int main(){
    int n;
    int i;
    int pares = 0;
    int impares = 0;
    int indicepar = 0;
    int indiceimpar = 0;


    scanf("%d", &n);
    if(n<3){
        return(0);
    }
    int v[n];
    for (i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for(i=0;i<n; i++){
        if(v[i]%2 == 0){
            pares++;
            indicepar = i;
        }
        else {
            impares++;
            indiceimpar = i;
        }
    }
    if(impares > pares){
        printf("%d", indicepar+1);
    } else {
        printf("%d", indiceimpar+1);
    }
}
