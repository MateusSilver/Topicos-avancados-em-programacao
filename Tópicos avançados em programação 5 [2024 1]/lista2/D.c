#include <stdio.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int v[n];

    int i, j;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(v[i] + v[j] == m){
                printf("%d %d", i+1, j+1);
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}
