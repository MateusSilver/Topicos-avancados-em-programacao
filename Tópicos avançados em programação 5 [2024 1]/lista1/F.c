#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int teams[n][2];
    int i;
    int j;

    for(i=0; i<n; i++){
        for(j=0; j<2; j++){
            scanf("%d", &teams[i][j]);
        }
    }

    int especialz=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(teams[i][0] == teams[j][1] && i!=j){
                especialz++;
            }
        }
    }
    printf("%d", especialz);
    return(0);
}

