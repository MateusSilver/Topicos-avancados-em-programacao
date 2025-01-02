#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        s[i] = s[i]-32;
    }
    cout << s;
    return 0;
}
