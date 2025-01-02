#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)

/**
    LISTA 12 - B : observe se as pessoas que sentam no onibus seguem as regras
    as pessoas que entram devem sentar ao lado das outras
    cada entrada[i] representa o assento sentado
**/

const int MAXN = 2e5+10;
vector<int> entrada(MAXN);

bool visinhoAtivo(vector<bool> &v, int assento, int n){
    if(assento == 0){
        //cout << "é 0 -> " << v[assento+1] << "\n";
        return v[assento+1];// true se tem um visinho
    }
    if(assento == n-1){
        //cout << "é n-1 -> " << v[assento-11] << "\n";
        return v[assento-1];// true se tem um visinho
    }
    //cout << "analisa se tem vizinho sentado\n";
    return (v[assento-1] == true || v[assento+1] == true);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<bool> v(n,false);// marcação dos sentados

        bool seguiuAsRegras = true;

        cin >> entrada[0];
        v[entrada[0]-1] = true;

        rep(i,1,n){
            cin >> entrada[i];
            v[entrada[i]-1] = true;

            //cout << "v[" << entrada[i]-1 << "] -> true\n";

            if(!visinhoAtivo(v,entrada[i]-1,n)){
                //cout << "não tem vizinho ativo\n";
                seguiuAsRegras = false;
            }
        }
        if(seguiuAsRegras){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
