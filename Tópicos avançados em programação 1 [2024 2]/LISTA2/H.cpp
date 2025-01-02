#include <bits/stdc++.h>
using namespace std;

void insert_v(vector<int, int> v, int n, int x){
    for(int i = 0; i<n; i++){
        pair<int, int> entrada = v[i];
        if(v[i].first() == x){
            entrada[i].second() = entrada[i].second()+1;
            return;
        }
    }
    entrada.push_back(make_pair(x,1));
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, entrada;
    cin >> n;

    vector<long long> playlistUnique;


    for(long long i = 0; i<n; i++){
        cin >> entrada;
        playlistUnique.insert_v(entrada);
    }
    long long l = 0;
    long long r = n;

    while(l <= r){
        for(int i = l; i <= r; i++){

        }
    }





    return 0;
}

