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
            a.push_back(1);
        } else {
            a.push_back(0);
        }
    }
    for(int i = 0; i< a.size(); i++){
        cout << a[i] << endl;

    }

}

// para trocar numero usar s[i] ^= 1

// fazer query de maximos
// update a cada encontro de hotel
/*
h = [3,2,4,1,5,5,2,6]
max = [0,3,3,4,4,5,5,5,6] // maximos entre h[i] e atual começando de 0
p = [4,4,7,1,1]
