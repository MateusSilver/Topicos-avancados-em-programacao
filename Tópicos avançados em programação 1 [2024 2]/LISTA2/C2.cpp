// somar tudo da direita l1 - r1/2
// somar tudo da esquerda l2 - r2/2
// anda do centro ate as pontas diminuindo da soma total r1 - l2
// l1-----r1 l2------r2
// '-soma1-' '--soma2-'

#define ll long long
#define loop(i,a,b) for(int i = a; i<b; i++)

#include <bits/stdc++.h>
using namespace std;

int soma(vector<int> v, int l, int n){
    int soma = 0;
    loop(i,l,n){
        soma += v[i];
    }
    return soma;
}

pair<int,int> anda(vector<int> v, int n){
    int l = n/2;
    int r = n/2;
    int mid = n << 1;
    v.sort(v.begin(), v.end()/2);// lado l
    v.sort(v.end()/2+1, v.end());// lado r
    int somaL = soma(v,0,n/2);
    int somaR = soma(v,n/2,n);
    while(l>=0 || r<n){
        if(somaL == somaR){
            return make_pair(l,r);
        } else {
            if(somaL > somaR){

            }
        }
    }
}


int main(){
    int n, t;
    cin >> t;

    while(t--){
        cin >> n;
        vector<int> v;
        int entrada;

        loop(i,0,n){
            cin >> entrada;
            v.push_back(entrada);
        }
        anda(v,n);
    }

}
