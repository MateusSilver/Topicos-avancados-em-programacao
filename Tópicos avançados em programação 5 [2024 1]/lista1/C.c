#include <stdio.h>

int main(){
    int n;
    int i;
    scanf("%d", &n);

    int x[n];
    int y[n];
    int z[n];

    int somaX = 0;
    int somaY = 0;
    int somaZ = 0;

    for(i=0; i<n; i++){
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
    }
    for(i=0; i<n; i++){
        somaX += x[i];
        somaY += y[i];
        somaZ += z[i];
    }
    if((somaX == 0 && somaY == 0) && somaZ == 0){
        printf("YES");
    } else {
    printf("NO");
    }
    return(0);
}
