#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

int gcd (int a, int b) {
    return b? gcd(b,a%b) : a;
}

int divisiveis(vector<int> a){
    vector<int> div(*max_element(a.begin(), a.end()),0);
    int n = a.size();
    for(int i = 0; i<n-1; i++){
        int ind = gcd(a[i],a[i+1]);// 3 12 7
        if(div[ind-1]){
            div[ind-1]++;
        }else{
            div[ind-1] += 2;
        }
    }
    int result = max_element(a.begin(),a.end());
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);

    rep(i,0,n){
        cin >> a[i];
    }

    cout << divisiveis(a);

    return 0;
}
