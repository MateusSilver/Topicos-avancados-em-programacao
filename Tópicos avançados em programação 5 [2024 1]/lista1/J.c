#include <stdio.h>
#include <string.h>

int isInHere(char* a, char x, int n){
    int i;
    for(i=0; i<n; i++){
        if(a[i] == x){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    char buffer;
    char c[1001];
    char getter;

    int i=0;
    do{
        getchar();
        buffer = getchar();
        if(!isInHere(c,buffer,i)){
            if(buffer == '}'){
                getter = buffer;
                break;
            }
            c[i] = buffer;
            i++;
        }
        getter = getchar();
    }while(getter != '}');
    c[i] = '\0';
    int maximum = strlen(c);
    printf("%d", maximum);
    return(0);
}
