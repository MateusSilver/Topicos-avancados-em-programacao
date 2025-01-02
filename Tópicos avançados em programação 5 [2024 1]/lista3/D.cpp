#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<char>> &matriz, vector<vector<int>> &checked, int x, int y, int m, int n){
    return ( x>=0 && x<m && y>=0 && y<n);
}

bool isCross( vector<vector<char>> &matriz, vector<vector<int>> &checked, int i, int j, int m, int n){
    int x, y;
    int s[2][4] = {{ 1,1,-1,-1},
                   {-1,1, 1,-1}};
    int soma = 0;
    if(matriz[x][y] == '#'){
        soma++;
    }
    for(int k = 0; k<4; k++){
        x = i + s[0][k];
        y = j + s[1][k];

        if(check(matriz,checked,x,y,m,n) && matriz[x][y] == '#'){
            soma++;
        }
    }
    if(soma == 5){
        return true;
    }
    return false;
}

int cross(vector<vector<char>> &matriz, vector<vector<int>> &checked, int x, int y, int m, int n){
    if(check(matriz,checked,x+1,y+1,m,n) && matriz[y+1][x+1] == '#'){
        return 1 + cross(matriz,checked,x+1,y+1,m,n);
        cout << "cruz segue 1" << endl;
    }
    return 0;
}

int step(vector<vector<char>> &matriz, vector<vector<int>> &checked, vector<int> &quantX, int i, int j, int m, int n){
    int x, y;
    cout << "step " << i << j << endl;
    int s[2][8] = {{0,1,1, 1, 0,-1,-1,-1},
                   {1,1,0,-1,-1,-1, 0, 1}};
    int soma = 0;
    if(matriz[i][j] == '#'){
        soma++;
    }
    int tamX = 0;
    for(int k = 0; k<8;k++){
        x = i + s[0][k];
        y = j + s[1][k];

        if(check(matriz,checked,x,y,m,n) && checked[x][y] == 0){
            checked[x][y] = 1;
            step(matriz,checked,quantX,x,y,m,n);
            if(isCross(matriz, checked,i,j,m,n)){
                tamX = cross(matriz, checked,x,y,m,n);
                quantX[tamX-1]++;
            }
        }
    }
    return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> checked(n,vector<int>(m));
    int tam;
    if(n<=m){
        tam = n;
    } else {
        tam = m;
    }
    vector<int> quantX(tam);

    int i, j;
    //getchar();
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> grid[i][j];
        }
        getchar();
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "adicionou " << i << j << endl;
            checked[i][j] = 0;
        }
    }
    for(i=0; i<n; i++){
        quantX[i] = 0;
    }
    step(grid, checked, quantX, n/2, m/2, n,m);
    for(int i=0; i<tam; i++){
        cout << quantX[i];
        if(i < tam-1){
            cout << " ";
        }
    }
    cout << endl;
}
