#include <stdio.h>
#include <stdbool.h>

struct person {
    int num;
    bool e;
};

bool pickTeam(struct person* v, int n, int k){
    int i;
    int team = 0;
    for(i=0; i<n && team<3; i++){
        if(v[i].e == false && v[i].num + k <= 5){
            v[i].e = true;
            team++;
        }
    }
    if(team == 3){
        return true;
    }
    return false;
}

int main(){
    int n, k, total = 0;
    scanf("%d", &n);
    scanf("%d", &k);

    struct person v[n];
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &v[i].num);
        v[i].e = false;
    }
    while(pickTeam(v, n, k)){
        total++;
    }
    printf("%d", total);
    return(0);
}
