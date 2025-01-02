#include <bits/stdc++.h>
using namespace std;

// adivinhe a diagonal do quadrado magico
// lista 10 - B

int main(){
    int matriz[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz[i][j];
        }
    }
    /*for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j];
            cout << " ";
        }
        cout << endl;
    }*/
    matriz[0][0] = floor((matriz[2][1] + matriz[1][2])/2);
    matriz[1][1] = floor((matriz[2][0] + matriz[0][2])/2);
    matriz[2][2] = floor((matriz[0][1] + matriz[1][0])/2);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
