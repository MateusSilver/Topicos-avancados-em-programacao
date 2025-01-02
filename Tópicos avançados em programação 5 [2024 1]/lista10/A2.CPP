// RESPOSTA CORRETA DA A - FOCAR EM QUANTIDADES
#include <iostream>
#include <stdlib.h>
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
            if(x->mat[i][j] == 'O'){
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
        if(x->mat[0][0] == 'O'){
            winO++;
        }
    }
    if(x->mat[0][2] == x->mat[1][1] && x->mat[1][1] == x->mat[2][0]){
        if(x->mat[0][2] == 'X'){
            winX++;
        }
        if(x->mat[0][2] == 'O'){
            winO++;
        }
    }
    for(i=0; i<3; i++){
        if(x->mat[i][0] == x->mat[i][1] && x->mat[i][1] == x->mat[i][2]){
            if(x->mat[i][0] == 'X'){
                winX++;
            }
            if(x->mat[i][0] == 'O'){
                winO++;
            }
        }
        if(x->mat[0][i] == x->mat[1][i] && x->mat[1][i] == x->mat[2][i]){
            if(x->mat[0][i] == 'X'){
                winX++;
            }
            if(x->mat[0][i] == 'O'){
                winO++;
            }
        }
    }
    // disparidade sem sentido de x e o
    if(quantX > quantO+1 || quantX < quantO){
        //cout << "quantidade disparidade\n";
        return -1;
    }
    // x vence mas quantidade de x = o
    if(winX > 0 && quantX == quantO){
        //cout << "x vence mas nao condiz, quant x = o\n";
        return -1;
    }
    // o vence mas quantidade de o < x
    if(winO > 0 && quantO < quantX){
        //cout << "o vence mas nao condiz, quant x = o\n";
        return -1;
    }
    // dois vencem
    if(winX > 0 && winO > 0){
        //cout << "dois vencem\n";
        return -1;
    }
    // alguem venceu
    if(winX > 0 || winO > 0){
        //cout << "alguem vence\n";
        return 1;
    }
    // ninguem vence, segue o jogo
    //cout << "ninguem vence\n";
    return 0;
}

int check_velha(tabuleiro* x){
    int i;
    int j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(x->mat[i][j] != 'O' && x->mat[i][j] != 'X'){
                return(0);
            }
        }
    }
    return(1);
}

void check(tabuleiro* x){
    if(check_win(x) == -1){
        cout << "no" << endl;
        return;
    }
    cout << "yes" << endl;
}

int main()
{
    tabuleiro A;
    zera(&A);

    int n;
    cin >> n;


    for(int problema = 0; problema < n; problema++){
        for(int i = 0; i<3; i++){
            getchar();
            for(int j = 0; j<3; j++){
                cin >> A.mat[i][j];
            }
        }
        check(&A);
        zera(&A);
    }
}
