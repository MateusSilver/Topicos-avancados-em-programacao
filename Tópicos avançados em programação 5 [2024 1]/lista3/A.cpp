#include <bits/stdc++.h>
using namespace std;

int vs[2][2];

int check(vector<vector<char>> &matriz, int x, int y, int m, int n){
    return ( x>=0 && x<m && y>=0 && y<n) && (matriz[x][y] == '#') && vs[x][y] == 0;
}

int step(vector<vector<char>> &matriz, int i, int j, int m, int n){
    int x, y;
    vs[i][j] = 1;
    int s[2][4] = {{0,1,-1,0},
                   {1,0,0,-1}};
    int soma = 1;
    for(int k = 0; k<4;k++){
        x = i + s[0][k];
        y = j + s[1][k];

        if(check(matriz,x,y,m,n)){
            soma += step(matriz,x,y,m,n);
        }
    }
    return soma;
}

int main(){
    //char matriz[2][2];
    vector<vector<char>> matriz(2,vector<char>(2));
    int cont = 0;
    int firstx, firsty;
    int i, j;
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            cin >> matriz[i][j];
            if(matriz[i][j] == '#'){
                cont++;
                firstx = i;
                firsty = j;
            }
        }
        getchar();
    }
    if(step(matriz,firstx,firsty,2,2) == cont){
        cout << "Yes";
    } else {
        cout << "No";
    }
}
