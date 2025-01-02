#include <bits/stdc++.h>
using namespace std;

/**
Lista 7 - D
liste os divisores de N
**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << "1\n";
    for(int i = 2; i<=n/2; i++){
        if(n%i==0){
            cout << i << "\n";
        }
    }
    cout << n << "\n";

    return 0;
}

