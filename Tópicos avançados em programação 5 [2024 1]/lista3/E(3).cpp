#include <bits/stdc++.h>
using namespace std;

int m[100][100];
int pintar[10000];

int check(int x, int y, int H, int W){
    return (( x>=0 && x<H && y>=0 && y<W) && m[x][y] == 0);
}

void paint(int H, int W){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            m[i][j] = 0;
        }
    }
}

void show(int H, int W){
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}


void anda(int i, int j, int H, int W, int quant, int valor){
    // andei o suficiente
    if(quant == 0){
        return;
    }
    if(check(i,j,H,W) && m[i][j] == 0){// se estou dentro da matriz e a casa é vaga
        m[i][j] = valor;
        if(check(i-1,j, H,W)){// cima
            anda(i-1,j,H,W,quant-1,valor);
        } else {
            if(check(i,j+1, H, W)){// direita
                anda(i, j+1, H,W,quant-1, valor);
            } else {
                if(check(i+1, j, H, W)){//baixo
                    anda(i+1, j, H,W, quant-1, valor);
                } else {
                    if(check(i,j-1, H, W)){// esquerda
                        anda(i,j-1,H,W, quant-1, valor);
                    }
                }
            }
        }
    }
}

void percorre(int i, int j, int H, int W, int quant, int valor){
    int x, y;
    if(m[i][j] != 0){
        return;
    }
    int direcoes[2][8] = {{-1,0,1,0,-1,1,1,-1},{0,1,0,-1,-1,-1,1,1}};// cruz
    for(int k = 0; k < 8; k++){
        x = i + direcoes[0][k];
        y = j + direcoes[1][k];

        if(check(x,y,H,W)){
            m[x][y] = valor;
            // pinta e percorre
            cout << x << " " << y << "anda\n";
            anda(x,y,H,W,quant,valor);
        }
    }

}

int main(){
    int H, W;
    cin >> H >> W;

    paint(H,W);
    show(H,W);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> pintar[i];
    }

    for(int i = 0; i < n; i++){
        percorre(0,0,H,W,i,pintar[i]);
    }
    show(H,W);
}

