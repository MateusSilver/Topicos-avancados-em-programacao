#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
char M[MAXN][MAXN];
int QuantX[MAXN];

#define HERE cout << "passou\n";

/**
Lista 9 - B : localize Xs na grid e printe sua quantidade de cada tamanho
quantidades de X de tamanho 1 até n = tam[1], tam[2], ... tam[n]
**/

int check(int x, int y, int n, int m){
    return (x >= 0 && x <n && y >=0 && y <m);
}

// caminha no X
int caminhaX(int i, int j, int n, int m){
    if(!check(i,j,n,m) || M[i][j] != '#'){
        return 0;
    }
    return 1 + caminhaX(i+1, j+1, n, m);
}

void findX(int i, int j, int n, int m){
    int passo[2][4] = {{-1,-1,1,1},{-1,1,1,-1}};//^<,^>,>v,<v
    int x, y;

    if(M[i][j] != '#'){
        return;
    }
    int countX = 1;
    for(int k = 0; k < 4; k++){
        x = i+passo[0][k];
        y = j+passo[1][k];

        if(check(x,y,n,m) && M[x][y] == '#'){
            countX++;
        }
    }
    if(countX == 5){
        int indice = caminhaX(i+1,j+1,n,m)-1;
        QuantX[indice]++;
    }
}

int minimo(int a, int b){
    if(a>b){
        return b;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cin >> M[i][j];
        }
    }
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            findX(i,j,n,m);
        }
    }

    for(int i = 0; i < minimo(n,m); i++){
        cout << QuantX[i] << " ";
    }

    return 0;
}


