#include <bits/stdc++.h>
using namespace std;

typedef struct tabuleiro{
    char mat[3][3];
}tabuleiro;

void zera(tabuleiro* x){
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            x->mat[i][j] = '.';
        }
    }

}

int contX(tabuleiro* x){
    int quant = 0;
    for(int i = 0; i< 3; i++){
        for(int j = 0; j<3; j++){
            if(x->mat[i][j] == 'X'){
                quant++;
            }
        }
    }
    return quant;
}

int contO(tabuleiro* x){
    int quant = 0;
    for(int i = 0; i< 3; i++){
        for(int j = 0; j<3; j++){
            if(x->mat[i][j] == '0'){
                quant++;
            }
        }
    }
    return quant;
}

int check_win(tabuleiro* x){
    int i;
    int winX = 0;
    int winO = 0;

    int quantX = contX(x);
    int quantO = contO(x);

    if(x->mat[0][0] == x->mat[1][1] && x->mat[1][1] == x->mat[2][2]){
        if(x->mat[0][0] == 'X'){
            winX++;
        }
        if(x->mat[0][0] == '0'){
            winO++;
        }
    }
    if(x->mat[0][2] == x->mat[1][1] && x->mat[1][1] == x->mat[2][0]){
        if(x->mat[0][2] == 'X'){
            winX++;
        }
        if(x->mat[0][2] == '0'){
            winO++;
        }
    }
    for(i=0; i<3; i++){
        if(x->mat[i][0] == x->mat[i][1] && x->mat[i][1] == x->mat[i][2]){
            if(x->mat[i][0] == 'X'){
                winX++;
            }
            if(x->mat[i][0] == '0'){
                winO++;
            }
        }
        if(x->mat[0][i] == x->mat[1][i] && x->mat[1][i] == x->mat[2][i]){
            if(x->mat[0][i] == 'X'){
                winX++;
            }
            if(x->mat[0][i] == '0'){
                winO++;
            }
        }
    }
    // disparidade sem sentido de x e o
    if(quantX > quantO+1 || quantX < quantO){
        cout << "illegal\n";
        //cout << "quantidade disparidade\n";
        return -1;
    }
    // x vence mas quantidade de x = o
    if(winX > 0 && quantX == quantO){
        cout << "illegal\n";
        //cout << "x vence mas nao condiz, quant x = o\n";
        return -1;
    }
    // o vence mas quantidade de o < x
    if(winO > 0 && quantO < quantX){
        cout << "illegal\n";
        //cout << "o vence mas nao condiz, quant x = o\n";
        return -1;
    }
    // dois vencem
    if(winX > 0 && winO > 0){
        cout << "illegal\n";
        //cout << "dois vencem\n";
        return -1;
    }
    // alguem venceu
    if(winX > 0 || winO > 0){
        if(winX > 0){
            cout << "the first player won\n";
        } else {
            cout << "the second player won\n";
        }
        //cout << "alguem vence\n";
        return 1;
    }
    // ninguem vence
    if(quantX + quantO == 9){
        cout << "draw\n";
        return 0;
    }
    // ninguem vence e não é impate, o jogo segue
    if(quantX > quantO){
        cout << "second\n";
    } else {
        cout << "first\n";
    }
    //cout << "ninguem vence\n";
    return 0;
}

int main(){
    tabuleiro A;
    zera(&A);

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin >> A.mat[i][j];
        }
        getchar();
    }
    check_win(&A);
}

