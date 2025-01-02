#include <stdio.h>

enum exer{
    CHEST,
    BICEPS,
    BACK
};

int max(int a, int b, int c){
    if(a>b && a>c){
        return(CHEST);
    } else {
        if(b>a && b>c){
            return(BICEPS);
        } else {
            if(c>a && c>b){
                return(BACK);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    enum exer exer = CHEST;

    int nchest = 0;
    int nbiceps = 0;
    int nback = 0;

    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i]);
        if(exer == CHEST){
            nchest += v[i];
            exer = BICEPS;
        } else{
            if(exer == BICEPS){
                nbiceps += v[i];
                exer = BACK;
            } else{
                if(exer == BACK){
                    nback += v[i];
                    exer = CHEST;
                }
            }
        }
    }
    int result = max(nchest,nbiceps,nback);
    if(result == BICEPS){
        printf("biceps");
    } else {
        if (result == CHEST){
            printf("chest");
        } else{
            if(result == BACK){
                printf("back");
            }
        }
    }
    return(0);
}
