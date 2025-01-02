#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(i,a,b) for(int i = a; i<b; i++)

void calculaDoces(vector<int> v, ll n){
    ll l = 0;
    ll r = n-1;

    ll somaL = 0;
    ll somaR = 0;
    ll maximo= 0;



    while(l<r){
        //cout << "[" << l << "][" << r << "]\n";
        somaL += v[l];
        somaR += v[r];
        //cout << somaL << " " << somaR << "\n";

        if(somaL == somaR){
            maximo = (l+1)+(n-r);
            //cout << "encontrou igual: " << maximo << "\n";
            //cout << "*" << l+1 << "*" << r+1 << "\n";
        }
            if(somaL-v[l] == somaR && l > 0){
                maximo = (l)+(n-r);
                //cout << "encontrou o proximo igual: " << maximo << "\n";
                //cout << "*" << l << "*" << r+1 << "*\n";
            }
            if(somaR-v[r] == somaL && r+1 < n){
                maximo = (l+1) +(n-(r+1));
                //cout << "encontrou o proximo igual: " << maximo << "\n";
                //cout << "*" << l+2 << "*" << r+2 << "*\n";
            }
            if(somaL+v[l+1] == somaR && l+1 == r){
                maximo = (l+2)+(n-r);
                //cout << "encontrou o proximo igual: " << maximo << "\n";
                //cout << "*" << l+2 << "*" << r+1 << "*\n";
            }
            if(somaL == somaR+v[r-1] && l == r-1){
                maximo = (l+1)+(n-(r-1));
                //cout << "encontrou o proximo igual: " << maximo << "\n";
                //cout << "*" << l+1 << "*" << r << "*\n";
            }


        l++;
        r--;
    }
    //cout << "resultado: ";
    cout << maximo << "\n";
}

void coletaItems(){
    ll n;

    cin >> n;
    vector<int> v;
    int entrada;

    loop(i,0,n){
        cin >> entrada;
        v.push_back(entrada);
    }
    /*loop(i,0,n){
        cout << v[i] << " ";
    }
    cout << "\n";*/

    calculaDoces(v,n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        coletaItems();
    }

}

