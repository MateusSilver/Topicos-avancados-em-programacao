#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool tree[4*n];
    vector<int> a;
    string s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i< n-1; i++){
        if(s[i] == s[i+1]){
            a.insert(1);
        } else {
            a.insert(0);
        }
    }
}
