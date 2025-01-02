#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcmpUppercase(char* a, char* b){
    int i;
    for(i=0; i<strlen(a); i++){
        if(a[i] >= 'A' || a[i] <= 'Z'){
            a[i] = tolower((char)a[i]);
        }
    }
    for(i=0; i<strlen(b); i++){
        if(b[i]>='A' || b[i]<='Z'){
            b[i] = tolower((char)b[i]);
        }
    }
    //printf("%s\n", a);
    //printf("%s\n", b);
    return strcmp(a,b);
}

int main(){
    char s1[101];
    char s2[101];

    scanf("%s", s1);
    scanf("%s", s2);

    if(strcmpUppercase(s1,s2) > 0){
        printf("1");
    } else {
        if(strcmpUppercase(s1,s2) == 0){
            printf("0");
        } else {
            if(strcmpUppercase(s1,s2)< 0){
                printf("-1");
            }
        }
    }
    return(0);
}
