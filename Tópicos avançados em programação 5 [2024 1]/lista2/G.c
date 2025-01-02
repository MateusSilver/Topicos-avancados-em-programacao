#include <stdio.h>

int modulo(int a, int b){
    return a-b > 0?  a-b : b-a;
}

int main(){
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int v[n];
    int w[m];
    int i, j;
    int menor = 999999999;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for(i=0; i<m; i++){
        scanf("%d", &w[i]);
    }
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(modulo(w[j],v[i]) < menor){
                menor = modulo(w[j],v[i]);
            }
        }
    }
    printf("%d", menor);
    return 0;

}
