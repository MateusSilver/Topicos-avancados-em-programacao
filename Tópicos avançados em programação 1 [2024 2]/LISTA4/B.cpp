#include <bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a; i<b; i++)

int main(){
    int n;
    char buffer[8][8];
    int indI, indJ;
    loop(i,0,8){
        for(int j = 0; j<8; j++){
            cin >> buffer[i][j];
            if(buffer[i][j] == '*'){
                indI = i;
                indJ = j;
            }
        }
        getchar();
    }
    char indJchar = 'a'+indJ;
    cout << indJchar << 8-indI << "\n";
}
