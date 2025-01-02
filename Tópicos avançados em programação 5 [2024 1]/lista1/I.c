#include <stdio.h>

struct restaurant{
    int fi;
    int ti;
};

int main(){
    int n;
    int k;
    int i;

    scanf("%d", &n);
    scanf("%d", &k);

    int maximum = -999999999;
    int joy = 0;

    struct restaurant r[n];
    for(i=0; i<n; i++){
        scanf("%d %d", &r[i].fi, &r[i].ti);
    }
    for(i=0; i<n; i++){
        if(r[i].ti > k){
            joy = r[i].fi-(r[i].ti-k);
        } else {
            joy = r[i].fi;
        }
        if(joy > maximum){
            maximum = joy;
        }
    }
    printf("%d", maximum);
    return(0);
}
