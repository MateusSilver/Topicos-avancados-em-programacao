#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    while((n/100) * ((n%100)/10) != n%10){
        //printf("%d * %d = %d\n", n/100, (n%100)/10, n%10);
        n++;
    }
    printf("%d", n);
    return 0;
}
