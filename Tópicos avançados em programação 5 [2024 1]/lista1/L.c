#include <stdio.h>
#include <string.h>

int main(){
    char s[51];
    scanf("%s", s);

    char t[51];
    scanf("%s", t);

    int pos = 1;
    int i;

    for(i=0; i<strlen(t); i++){
        if(pos < strlen(s) && s[pos-1] == t[i]){
            //printf("anda [%c]\n", s[pos-1]);
            pos++;
        }
        //printf("[%c]", t[i]);
    }
    printf("%d", pos);
    return(0);
}
