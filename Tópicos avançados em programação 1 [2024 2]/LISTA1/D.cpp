#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a; i<b; i++)

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    queue<char> Sequencia;
    char c;
    while(cin >> c && c != '\n'){
        Sequencia.push(c);
    }
    while(!Sequencia.empty()){
        cout << Sequencia.front() << "\n";
        Sequencia.pop();
    }
}

