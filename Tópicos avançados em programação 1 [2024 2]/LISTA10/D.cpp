#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
#define ll long long

/*
LISTA 10 - D : busque por quantidade de letras que voce precisa mudar para que uma palavra seja substring da outra
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string t;

    cin >> s >> t;
    int maximo = 0;
    for(int i =0; i<s.size(); i++){
        if(s[i] == t[0]){
            int contador = 1;
            int j = 0;
            while(i+j<s.size() && j<t.size() && s[i] == t[j]){
                contador++;
                j++;
            }
            if(contador > maximo){
                maximo = contador;
            }
        }
    }
    cout << t.size() - maximo;

    return 0;
}
