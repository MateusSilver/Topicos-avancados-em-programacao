#include <bits/stdc++.h>
using namespace std;

int maxoperations = 0;



void print_matriz(char* x, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            cout << x[(i*j)+j];
        }
        cout << endl;
    }
    return;
}

void check_vertical(char* x, int tam){
    for(int i = 0; i < tam-3; i++){
        for(int j = 0; j < tam; j++){
            if(x[(i*tam)+j] == x[((i+1)*tam)+j] && x[((i+1)*tam)+j] == x[((i+2)*tam)+j]){
                if(x[((i+2)*tam)+j] != '.'){
                    if(x[((i+2)*tam)+j] == 'X'){
                        x[((i+2)*tam)+j] = 'O';
                    } else {
                        x[((i+2)*tam)+j] = 'X';
                    }
                }
            }
        }
    }
    print_matriz(x,tam);
    return;
}

void corrige_matriz(char* x, int tam){
    check_vertical(x,tam);
    //check_horizontal(x,tam);
}

int main(){
    int n;
    int tam;
    char buffer[90000];

    cin >> n;
    while(n--){
        cin >> tam;
        getchar();
        for(int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                cin >> buffer[(i*tam)+j];
            }
            getchar();
        }
        print_matriz(buffer, tam);
        corrige_matriz(buffer, tam);
    }
    return 0;
}
