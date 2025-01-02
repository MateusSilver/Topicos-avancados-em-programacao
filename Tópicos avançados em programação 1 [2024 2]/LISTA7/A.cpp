#include <bits/stdc++.h>
using namespace std;

/**
7-A
ache um entre 3 culpados baseado no que não e culpado
**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> a >> b;

    if(a == b){
        cout << "-1\n";
        return 0;
    }
    if(a == 1 && b == 2) {
        cout << "3\n";
        return 0;
    }
    if(a == 1 && b == 3){
        cout << "2\n";
        return 0;
    }
    if(a == 2 && b == 1){
        cout << "3\n";
        return 0;
    }
    if(a == 2 && b == 3){
        cout << "1\n";
        return 0;
    }
    if(a == 3 && b == 1){
        cout << "2\n";
    }
    if(a == 3 && b == 2){
        cout << "1\n";
        return 0;
    }
}
