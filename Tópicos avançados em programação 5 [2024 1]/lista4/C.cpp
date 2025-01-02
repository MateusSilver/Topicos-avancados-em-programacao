#include <bits/stdc++.h>
using namespace std;

queue<pair <int, int>> q;

int check(vector<vector<int>> &matriz, vector<vector<int>> &vs, int x, int y, int m, int n){
    return ( x>=0 && x<m && y>=0 && y<n) && vs[x][y] == 0;
}

vector<vector<int>> soma;

int step(vector<vector<int>> &matriz, vector<vector<int>> &vs, int i, int j, int m, int n){
    int x, y;
    int peso = matriz[i][j];
    int s[2][4] = {{0,1,-1,0},
                   {1,0,0,-1}};
    while(!q.empty()){
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    for(int k = 0; k<4;k++){
        x = i + s[0][k]*peso;
        y = j + s[1][k]*peso;

        if(check(matriz,vs,x,y,m,n)){
            soma[x][y] = soma[i][j]+1;
            q.push(make_pair(x,y));
            vs[x][y] = 1;
        }
        }
    }
    return soma[m-1][n-1];
}

int main(){
    int n, m;
    cin >> n >> m;

    int cont = 0;
    vector<vector<int>> grafo(n, vector<int>(m));
    vector<vector<int>> vs(n, vector<int>(m,0));
    char peso;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> peso;
            grafo[i][j] = (int)(peso - '0');
        }
    }
    q.push(make_pair(0,0));
    vs[0][0] = 1;
    cout << step(grafo,vs,0,0,n,m);
}

