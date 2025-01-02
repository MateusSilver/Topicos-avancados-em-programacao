#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
typedef pair<int, int> ii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    queue<ii> Q;
    ii newpair;
    int t, n;

    cin >> t;
    rep(i,0,t){

        cin >> n;
        rep(j,0,n){
            cin >> newpair.first >> newpair.second;
            Q.push(newpair);
        }

        int tempo = 1;
        while(!Q.empty()) {
            newpair = Q.front();
            while(tempo < newpair.first){
                tempo++;
            }

            if(newpair.second < tempo) {
                cout << "0";
                Q.pop();
                char c = Q.empty() ? '\n' : ' ';
                cout << c;
            } else {
                cout << tempo;
                tempo++;
                Q.pop();
                char c = Q.empty() ? '\n' : ' ';
                cout << c;
            }
        }
    }

    return 0;
}
