#include <stdio.h>

int desmarcados(char* string, int n){
    int i;
    for(i=0; i<n; i++){
        if(string[i] != '*'){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n, i;
    scanf("%d", &n);

    char marking[n];
    for(i=0; i<n; i++){
        marking[i] = '*';
    }
    // mahmoud = even
    //ehab = odd
    // n-a
    int a=1;
    int mahmoud = 1;
    int ahab = 0;
    while(desmarcados(marking, n)){
        if(mahmoud){
            for(i=0; i<n; i++){
                if(marking[i] == '*' && n-(i+1) == 0){
                    mahmoud = 0;
                    ahab = 1;
                    marcar(marking, i);
                    break;
                }
            }
        }
        if(ahab){
            for(i=0; i<n; i++){
                if(marking[i] == '*' && n-(i+1) != 0){
                    mahmoud = 1;
                    ahab = 0;
                    marcar(marking, i);
                    break;
                }
            }
        }
    }
    if(mahmoud){
        printf("Ahab");
    } else {
    printf("Mahmoud");
    }

}

