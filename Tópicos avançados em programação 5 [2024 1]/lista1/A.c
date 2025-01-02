#include <stdio.h>

int main(){
    int w;
    int i;

    scanf("%d", &w);
    for(i=2; i<w; i++){
        if((w-i)%2 == 0 && i%2 == 0){
            printf("YES");
            return(0);
        }
    }
    printf("NO");
}
