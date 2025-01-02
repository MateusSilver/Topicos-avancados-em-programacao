#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nos(n,0);

    int de, para;
    for(int i = 0; i < n-1; i++){
        cin >> de >> para;
        nos[de-1]++;
        nos[para-1]++;
    }
    for(int i = 0; i<n; i++){
        if(nos[i] == n-1){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}

