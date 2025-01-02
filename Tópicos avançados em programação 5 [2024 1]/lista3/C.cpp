// H linhas e W colunas
// o quadrado dentro é o (i,j). 0 to i e 0 to j
// pintar de preto o quadrado
// e pintar dois quadrados
// ver se é possivel pintar 2
#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<char>> &matriz, int x, int y, int m, int n){
    return ( x>=0 && x<m && y>=0 && y<n) && matriz[x][y] == '#';
}

check

int step(vector<vector<char>> &matriz, int i, int j, int m, int n){
    int x, y;
    int s[2][4] = {{0,1,-1,0},
                   {1,0,0,-1}};

    for(int k = 0; k<4; k++){
        x = i + s[0][k];
        y = j + s[1][k];

        if(check(matriz,x,y,m,n) && matriz[i][j] == '#'){
            matriz[x][y] = '#';
            stepB(matriz,x,y,m,n);
            cout << " checou " << x << y << endl;
        }
    }
    for(int k = 0; k<4; k++){
        x = i + s[0][k];
        y = j + s[1][k];

        if(check(matriz,x,y,m,n) && matriz[i][j] == '#'){
            matriz[x][y] = '#';
            step(matriz,x,y,m,n);
            cout << " checou " << x << y << endl;
        }
    }
    return 0;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matriz(n,vector<char>(m));

    int i, j;
    getchar();
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> matriz[i][j];
        }
        getchar();
    }
    step(matriz, 0, 0, n, m);
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cout << matriz[i][j];
        }
        cout << endl;
    }

}


