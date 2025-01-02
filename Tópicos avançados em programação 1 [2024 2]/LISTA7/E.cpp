#include <bits/stdc++.h>
using namespace std;

/**
Lista 7 - E
conte os divisores de C, entre A e B;
**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> divide_C;

    int a,b,c;
    cin >> a >> b >> c;

    for(int i = 1; i<=c/2; i++){
        if(c%i==0){
            //cout << "divisor de " << c << ": " <<  i << "\n";
            divide_C.push_back(i);
        }
    }
    divide_C.push_back(c);

    int divisores = 0;
    for(int i = 0; i<divide_C.size(); i++){
        if(divide_C[i] >= a && divide_C[i] <= b){
            //cout << divide_C[i] << "\n";
            divisores++;
        }
    }
    cout << divisores << "\n";

    return 0;
}
