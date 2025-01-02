#include <stdio.h>

int indiceof(int* v,int  n, int x){
    int i;
    for(i=0; i<n; i++){
        if(v[i] == x){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];

    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    for(i=0; i<n; i++){
        printf("%d ", indiceof(v,n,i+1));
    }

    return(0);
}

