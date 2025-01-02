#include <bits/stdc++.h>
using namespace std;

struct tabuleiro {
    mat[3][3];
};

int analises(tabuleiro* x){
    //analisa a maior perna
}

int main(){
    tabuleiro D;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> D.mat[i][j];
        }
    }
    // pega a perna maior
    int baseColuna = D.mat[1][0] + D.mat[2][0];
    int baseLinha = D.mat[0][1] + D.mat[0][2];

    int base;

    if(baseLinha > baseColuna){
        base = ceil(baseLinha/3);
    } else {
        base = ceil(baseColuna/3);
    }
    analises(&D);
}

