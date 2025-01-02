#include <bits/stdc++.h>
using namespace std;

const long long int N = 5e5 + 10;
long long int bits[N];
char a[N];

int present(char x){
    long long int i;
    while(a[i] != '\n' && a[i] != '\0'){
        if(a[i] == x){
            return 0;
        }
        i++;
    }
    return 1;
}

long long int feenwick(long long int x){
    long long int soma = 0;
    while(x){
        if(!present(a[x])){
            soma += bits[x];
        }
        x -= (x& - x);
    }
    return soma;
}

void update(long long int x,char valor){
    while(x<N){
        if(!present(valor)){
            bits[x]++;
        }
        x += (x& - x);
    }
}


int main(){
    long long int n, m;
    cin >> n;

    string a;
    char ch;
    while(a.size() < n){
        cin >> ch;
        update(a.size()+1,ch);
        a += ch;
    }

    bits[0] = 0;
    //cout << bits << endl;
    cin >> m;
    long long int l, r, k;
    char cq;
    while(m--){
        cin >> k;
        if(k == 2){
            cin >> l >> r;
            cout << (feenwick(r) - feenwick(l-1)) << endl;
        } else {
            if(k == 1){
                cin >> l >> cq;
                a[l] = cq;
                update(l,cq);
                cout << a << endl;
            }
        }
    }
    return 0;
}


