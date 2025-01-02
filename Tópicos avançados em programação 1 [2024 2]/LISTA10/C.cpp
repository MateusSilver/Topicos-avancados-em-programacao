#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long
#define HERE cout << "here\n";

string rightshift(string entrada){
    string sub = entrada.substr(entrada.size()-1, entrada.size());
    string corpo = entrada.substr(0, entrada.size()-1);
    //HERE
    return sub+corpo;
}

string leftshift(string entrada){
    string sub = entrada.substr(0,1);
    string corpo = entrada.substr(1);
    //HERE
    return corpo+sub;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string entrada;
    cin >> entrada;

    string Smax, Smin;
    Smax = Smin = entrada;

    string maxima(entrada.size(),'a');

    rep(i,0,entrada.size()){
        if(maxima<Smax){
            maxima = Smax;
        }
        //HERE

        Smax = rightshift(Smax);
    }

    string minima(entrada.size(),'z');
    rep(i,0,entrada.size()){
        if(minima>Smin){
            minima = Smin;
        }
        //HERE
        Smin = leftshift(Smin);
    }

    cout << minima << "\n" << maxima;

    return 0;
}

