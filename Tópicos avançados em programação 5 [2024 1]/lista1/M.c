#include <stdio.h>
#include <string.h>

void wording(char* word){
    if(strlen(word) == 0){
        return;
    }
    if(strlen(word)<= 10){
        printf("%s\n",word);
        return;
    }
    char firstchar = word[0];
    char lastchar = word[strlen(word)-1];
    printf("%c", firstchar);
    printf("%d", strlen(word)-2);
    printf("%c\n", lastchar);

}

int main(){
    int n;
    int i;

    scanf("%d", &n);
    char word[n][101];

    for(i=0; i<n; i++){
        getchar();
        scanf("%[^\n]", word[i]);
    }
    for(i=0; i<n; i++){
        wording(word[i]);
    }
    return(0);
}

