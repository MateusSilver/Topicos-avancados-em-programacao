#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int l, r;

    cin >> l >> r;
    cin >> s;

    reverse(s.begin()+l-1,s.begin()+r);
    cout << s;
    return 0;
}
