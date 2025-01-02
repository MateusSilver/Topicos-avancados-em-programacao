#include <stdio.h>

struct mountain {
    int height;
    char name[16];
};
typedef struct mountain mountain;


// insertion sort
void sort(mountain* m, int n){
    int i;
    int j = 0;
    mountain aux;

    for(i=1; i<n; i++){
        aux = m[i];
        j = i-1;

        while(j>=0 && m[j].height < aux.height){
            m[j+1] = m[j];
            j--;
        }
        m[j+1] = aux;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    mountain m[n];
    int i;

    for(i=0; i<n; i++){
        scanf("%s %d", &m[i].name, &m[i].height);
    }
    sort(m,n);
    printf("%s", m[1].name);

    return 0;
}

