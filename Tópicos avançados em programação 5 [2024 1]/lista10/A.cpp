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



int check_win(tabuleiro* x){
    int i;
    int winnerX = 0;
    int winnerO = 0;
    // diagonais
    if(x->mat[0][0] == x->mat[1][1] && x->mat[1][1] == x->mat[2][2]){
        if(x->mat[0][0] == 'X'){
            winnerX++;
        }
        if(x->mat[0][0] == 'O'){
            winnerO++;
        }
    }
    if(x->mat[0][2] == x->mat[1][1] && x->mat[1][1] == x->mat[2][0]){
        if(x->mat[0][2] == 'X'){
            winnerX++;
        }
        if(x->mat[0][2] == 'O'){
            winnerO++;
        }
    }
    // linhas e colunas
    for(i=0; i<3; i++){
        if(x->mat[i][0] == x->mat[i][1] && x->mat[i][1] == x->mat[i][2]){
            if(x->mat[i][0] == 'X'){
                winnerX++;
            }
            if(x->mat[i][0] == 'O'){
                winnerO++;
            }
        }
        if(x->mat[0][i] == x->mat[1][i] && x->mat[1][i] == x->mat[2][i]){
            if(x->mat[0][i] == 'X'){
                winnerX++;
            }
            if(x->mat[0][i] == 'O'){
                winnerO++;
            }
        }
    }
    // dois vencedores
    if(winnerX > 0 && winnerO > 0){
        return -1;
    }
    // um vencedor
    if(winnerX > 0 || winnerO > 0){
        return 1;
    }

    return(0);
}

int check_velha(tabuleiro* x){
    int i;
    int j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(x->mat[i][j] == '.' && x->mat[i][j] != '.'){
                return(0);
            }
        }
    }
    return(1);
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

int possible(tabuleiro *x){
    int O = 0, X = 0;
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(x->mat[i][j] == 'O'){
                O++;
            }
            if(x->mat[i][j] == 'X'){
                X++;
            }
        }
    }
    if(X > 5 || O > 4){
        return 0;
    }
    if(O != X-1 && O != X){
        return 0;
    }
    return 1;
}

int check_concorrencia(tabuleiro *x){
    int LinhasVencedoras = 0;
    int ColunasVencedoras = 0;
    for(int i = 0; i<3; i++){
        if(x->mat[i][0] == x->mat[i][1] && x->mat[i][1] == x->mat[i][2]){
            if(x->mat[i][0] != '.'){
                LinhasVencedoras++;
            }
        }
    }
    for(int i = 0; i<3; i++){
        if(x->mat[0][i] == x->mat[1][i] && x->mat[1][i] == x->mat[2][i]){
            if(x->mat[0][i] != '.'){
                ColunasVencedoras++;
            }
        }
    }
    if(LinhasVencedoras > 1 || ColunasVencedoras > 1){
        return 0;
    }
    return 1;
}

int check_Owin(tabuleiro* x){
    int winnerO = 0;
    if(x->mat[0][0] == x->mat[1][1] && x->mat[1][1] == x->mat[2][2]){
        if(x->mat[0][0] == 'O'){
            winnerO++;
        }
    }
    if(x->mat[0][2] == x->mat[1][1] && x->mat[1][1] == x->mat[2][0]){
        if(x->mat[0][2] == 'O'){
            winnerO++;
        }
    }
    // linhas e colunas
    for(int i=0; i<3; i++){
        if(x->mat[i][0] == x->mat[i][1] && x->mat[i][1] == x->mat[i][2]){
            if(x->mat[i][0] == 'O'){
                winnerO++;
            }
        }
        if(x->mat[0][i] == x->mat[1][i] && x->mat[1][i] == x->mat[2][i]){
            if(x->mat[0][i] == 'O'){
                winnerO++;
            }
        }
    }

    if(winnerO > 1){
        return -1;
    }
    if(contX(x) != contO(x)){
        return -1;
    }
    if(winnerO == 1){
        return 1;
    }
    return 0;
}

void check(tabuleiro* x){
    int vence = check_win(x);
    int Owin = check_Owin(x);
    if(Owin == -1){
        cout << "no" << endl;
        return;
    }
    if(vence == -1){
        cout << "no" << endl;
        return;
    }
    if(vence == 1){
        if(check_concorrencia(x) == 0){
            cout << "no" << endl;
            return;
        }
    }
    if((vence == 0 || check_velha(x) == 0) && possible(x) == 0){
        cout << "no" << endl;
        return;
    }
    cout << "yes" << endl;
    return;
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
