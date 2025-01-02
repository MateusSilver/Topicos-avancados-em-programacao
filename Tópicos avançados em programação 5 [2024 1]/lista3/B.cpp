#include <bits/stdc++.h>
using namespace std;

int check(vector<vector<int>> &matriz, int x, int y, int m, int n){
    return ( x>=0 && x<m && y>=0 && y<n) && matriz[x][y] == 0;
}

int preencha(vector<vector<int>> &matriz, int m, int n){
    int i, j;
    for(i = 0; i<m; i++){
        for(j = 0; j<n; j++){
            matriz[i][j] = 0;
        }
    }
}

int mark(vector<vector<int>> &matriz, int x, int y){
    matriz[x][y] = 1;
}

int isolado(vector<vector<int>> &matriz, int x, int y){
    matriz[x][y] = -1;
}

int step(vector<vector<int>> &matriz, int i, int j, int m, int n){
    int x, y;
    int s[2][8] = {{2, 2, 1,1,-2,-2,-1,-1},
                   {1,-1,-2,2, 1,-1,-2, 2}};

    int possibilidades = 0;
    //cout << "step: " << i << " " << j << endl;


    for(int k = 0; k<8;k++){
        x = i + s[0][k];
        y = j + s[1][k];

        if(check(matriz,x,y,m,n)){
            //(matriz, x, y);
            //cout << "possibilidade: " << x << " " << y << endl;
            possibilidades++;
        }
    }

    if(possibilidades == 0){
        isolado(matriz,i,j);
    }
    if(j<n-1 ){
        step(matriz, i, j+1,m,n);
    } else{
        if(i<m-1){
            step(matriz,i+1,0,m,n);
        }
    }
    return 1;
}

void print(vector<vector<int>> &matriz, int x, int y){
    int i, j;
    for(i = 0; i < x; i++){
        for(j = 0; j<y; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int printisolada(vector<vector<int>> &v, int m, int n){
    int i, j;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(v[i][j] == -1){
                cout << i+1 << " " << j+1 << endl;
                return 1;
            }
        }
    }
    return 0;
}


int main(){
    int n;
    cin >> n;
    //vector<vector<vector<int>>> v(n,vector<vector<int>>(n));
    vector<vector<vector<int>>> v(n);
    int i, x, y;
    for(i = 0; i<n; i++){
        cin >> x >> y;
        vector<vector<int>> matriz(x,vector<int>(y,0));
        v[i] = matriz;
        preencha(v[i], x, y);
        //print(v[i], x, y);
    }
    for(i = 0; i<n; i++){
        int lin = v[i].size();
        int col = v[i][0].size();
        step(v[i],0, 0, lin, col);
        //print(v[i], lin, col);
        if(!printisolada(v[i],lin,col)){
            cout << "1 1" << endl;
        }
    }
}
