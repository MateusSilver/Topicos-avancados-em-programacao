#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i = a; i < b; i++)
#define ll long long

int main(){
    ll n;
    cin >> n;
    if(n==1){
        cout << "1\n";
        return 0;
    }
    if(n<=3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    ll v[n];

    ll k = n-1;
    if(n%2 == 0){
        for(ll i=0; i<n/2; i++){
            v[i] = k;
            k = k-2;
        }
        k = n;
        for(ll i=(n/2); i<n; i++){
            v[i] = k;
            k = k-2;
        }
    } else {
        for(ll i=0; i<n/2; i++){
            v[i] = k;
            k = k-2;
        }
        k = n;
        for(ll i=(n/2); i<n; i++){
            v[i] = k;
            k = k-2;
        }
    }

    loop(i,0,n){
        cout << v[i];
        if(i == n){
            cout << "\n";
        } else {
            cout << " ";
        }
    }
}
