#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(int i = a; i<b; i++)

const int MAXN = 2*1e5+100;
ll A[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    ll sum;

    cin >> n;
    cin >> sum;

    loop(i,0,n){
        cin >> A[i];
    }

    ll l = 0, r = 0;
    ll somaatual = 0;
    ll totalsomasiguais = 0;

    while(r < n || somaatual >= sum){
        if(somaatual == sum){
            totalsomasiguais++;
        }
        if(somaatual >= sum){
            somaatual -= A[l];
            l++;
        }
        else {
            somaatual += A[r];
            r++;
        }

    }
    cout << totalsomasiguais << "\n";
}

/*
 2 4 1 2 7
 l
 r
 dois ponteiros, se < 7 move r, se maior move l, até r = n
 se achou soma = 7 aumenta as somas. e l não pode ser maior que r




*/
