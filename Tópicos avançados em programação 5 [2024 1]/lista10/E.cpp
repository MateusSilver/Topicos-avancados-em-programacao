#include <bits/stdc++.h>
using namespace std;

int I;
int  J;

int m[500][500];

void checa_vazia(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] == 0){
                I = i;
                J = j;
            }
        }
    }
    return;
}

int checa_pivo(int n){
    int soma = 0;
    int pivo = 0;

    for(int i = 0; i < n; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            if(i != I){
                soma += m[i][j];
            }
        }
        if(pivo != 0 && soma != pivo){
            return -1;
        }
    }

    for(int i = 0; i < n; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            if(j != J){
                soma += m[j][i];
            }
        }
        if(pivo != 0 && soma != pivo){
            return -1;
        }
    }

    for(int i = 0; i < n; i++){
        soma = 0;
        for(int j = 0; j < n; j++){
            if(j != J){
                soma += m[j][i];
            }
        }
        if(pivo != 0 && soma != pivo){
            return -1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }
}
