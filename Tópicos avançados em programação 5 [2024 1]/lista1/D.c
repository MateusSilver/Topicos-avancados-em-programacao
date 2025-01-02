#include <stdio.h>
#include <math.h>

int min(int a, int b, int c){
    if(a<b && a<c){
        return a;
    }
    if(b<a && b<c){
        return b;
    }
    if(c<a && c<b){
        return c;
    }
    return a;
}

int main(){
    int Nfriends;
    int Nbottles;
    int BottlesMilliliters;
    int Nlimes;
    int NlimeSlices;
    int salt;
    int requiredMilliliters;
    int requiredSalt;

    scanf("%d %d %d %d %d %d %d %d", &Nfriends, &Nbottles, &BottlesMilliliters, &Nlimes, &NlimeSlices, &salt, &requiredMilliliters, &requiredSalt);

    int toasts = 0;
    int totalMilliliters = Nbottles*BottlesMilliliters;

    int totalSlices = Nlimes*NlimeSlices;

    int dividedMilliliters;
    int dividedSalt;
    int dividedSlices;

    dividedMilliliters = floor(totalMilliliters/(Nfriends*requiredMilliliters));
    dividedSlices = floor(totalSlices/Nfriends);
    dividedSalt = floor(salt/(requiredSalt*Nfriends));

    toasts = min(dividedMilliliters, dividedSlices, dividedSalt);

    printf("%d", toasts);
    return(0);
}
