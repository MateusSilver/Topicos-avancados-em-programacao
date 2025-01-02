#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    pair < int, int > v[n];
    int i, j;
    for(i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v,v+n);

    i=0;
    j=n-1;

    while(i<j){
        if(v[i].first + v[j].first == m){
                cout << v[j].second+1 << " " << v[i].second+1;
                return 0;
        }
        if(v[i].first + v[j].first > m){
            j--;
        }
        if(v[i].first + v[j].first < m){
            i++;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}

