#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string a;


    cin >> n;
    set<string> v;

    for(int i=0; i<n; i++){
        cin >> a;
        v.insert(a);
    }
    int j = v.size();
    cout << j << endl;
    return 0;
}
