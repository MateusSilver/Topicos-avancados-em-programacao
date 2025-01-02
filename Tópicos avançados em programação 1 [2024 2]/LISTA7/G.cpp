#include <bits/stdc++.h>
using namespace std;

/**
Lista 7 - G
conte os divisores de X
**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n;

    while(n--){
        cin >> x;

        int divisores = 0;
        for(int i = 1; i*i<=x; i++){
            if(x%i==0){
                divisores++;
                if(x/i!=i){
                    divisores++;
                }
            }
        }

        cout << divisores << "\n";
    }
}

