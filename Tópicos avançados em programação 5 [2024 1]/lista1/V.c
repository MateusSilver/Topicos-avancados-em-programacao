#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    char string[n];

    int tosanfrancisco = 0;
    int toseatle = 0;
    int i;
    getchar();
    for(i=0; i<n; i++){
        string[i] = getchar();
    }
    char current = string[0];
    for(i=1; i<n; i++){
        if(current != string[i]){
            if(current == 'F'){
                toseatle++;
            } else {
                tosanfrancisco++;
            }
        }
        current = string[i];
    }
    //printf("%d seatle\n", toseatle);
    //printf("%d san francisco\n", tosanfrancisco);

    if(toseatle<tosanfrancisco){
        printf("YES");
    } else {
        printf("NO");
    }
    return(0);
}

