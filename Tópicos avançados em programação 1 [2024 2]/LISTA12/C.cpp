#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
LISTA 12 - C : dados campos com necessidade de fertilizantes como matriz, use quantidade
de fertilizante disponivel para minimizar de maneira uniforme as necessidades de fertilizante de modo a
ter um valor maximo de necessidade de fertilizante em um campo e exiba na tela
**/

const int MAXN = 1000;
int MATRIZ[MAXN][MAXN];

void printMATRIZ(int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << MATRIZ[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

void retiraFertilizante(int n, int m){
    int imaximo = 0;
    int jmaximo = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(MATRIZ[i][j] > MATRIZ[imaximo][jmaximo]){
                imaximo = i;
                jmaximo = j;
            }
        }
    }
    MATRIZ[imaximo][jmaximo]--;
    //printMATRIZ(n,m);
}

void printMax(int n, int m){
    int imaximo = 0;
    int jmaximo = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(MATRIZ[i][j] > MATRIZ[imaximo][jmaximo]){
                imaximo = i;
                jmaximo = j;
            }
        }
    }
    cout << MATRIZ[imaximo][jmaximo] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    ll fertilizantesNecessarios = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> MATRIZ[i][j];
            fertilizantesNecessarios += MATRIZ[i][j];
        }
    }
    ll fertilizantesObtidos;
    cin >> fertilizantesObtidos;

    /*if(fertilizantesNecessarios == 0){
        cout << "0\n";
        return 0;
    }

    cout << (fertilizantesNecessarios - fertilizantesObtidos)/(n*m) << "\n";*/
    if(fertilizantesNecessarios < fertilizantesObtidos){
        cout << "0\n";
        return 0;
    }

    while(fertilizantesObtidos--){
        retiraFertilizante(n,m);
    }
    printMax(n,m);

    return 0;
}
