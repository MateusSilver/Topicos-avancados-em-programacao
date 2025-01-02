#include <stdio.h>

int print(int* v, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int swapleft(int* v, int n, int max){
    int aux;
    int total = 0;
    while(max>0){
        aux = v[max];
        v[max] = v[max-1];
        v[max-1] = aux;
        total++;
        //print(v,n);
        max--;
    }
    return total;
}

int swapright(int* v, int n, int min){
    int aux;
    int total = 0;
    while(min<n-1){
        aux = v[min];
        v[min] = v[min+1];
        v[min+1] = aux;
        total++;
        min++;
        //print(v,n);
    }
    return total;
}

int max_bubble_sort(int* v, int n){
    int i;
    int max = -1;
    int indicemaximo;
    int min = 9999;
    int indiceminimo;
    for(i=0; i<n; i++){
        if(max < v[i]){
            max = v[i];
            indicemaximo = i;
        }
    }
    int left = swapleft(v,n,indicemaximo);

    for(i=n-1; i>=0; i--){
        if(min > v[i]){
            min = v[i];
            indiceminimo = i;
        }
    }
    int right = swapright(v,n,indiceminimo);

    return left+right;
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];

    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    //print(v,n);
    int total = max_bubble_sort(v, n);
    printf("%d", total);
    return(0);
}
