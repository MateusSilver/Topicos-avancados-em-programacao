#include <bits/stdc++.h>
using namespace std;

/**
LISTA 12 - A : dado um numero com caracteres abc -> bca cab
**/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char a, b, c;
    cin >> a >> b >> c;

    cout << b << c << a << " ";
    cout << c << a << b << "\n";

    return 0;
}
