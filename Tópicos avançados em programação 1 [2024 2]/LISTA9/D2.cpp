#include <bits/stdc++.h>
using namespace std;

#define HERE cout << "HERE\n";

/**
Lista 9 - D : encontre a saida do labirinto e printe se existe caminho, o caminho mais curto de A até B
e a string com as cordenadas de A até B, paredes são #
**/

#define loopI(a,b) for(int row = a; row < b; row++)
#define loopJ(a,b) for(int col = a; col < b; col++)

const int N = 1e3+10;
char grid[N][N];
int dist[N][N];

struct caminho{
    pair<int, int> cordenada;
    string path;// "A estrada até aqui - Carry on..."
};

queue<caminho> q;// caminhos visitados para analisar

bool check(int x, int y, int n, int m){
    return (x >= 0 && x <n && y >=0 && y <m) && M[x][y] != '#';
}

void caminha(int inicioI, int inicioJ, int fimI, int fimJ, int n, int m){
    int passos[2][4] = {{-1,0,1,0},{0,1,0,-1}};//^>v<
    char direcao[4] = {'U','R','D','L'};// ^>v<
    int x, y;

    caminho inicio;
    inicio.cordenada = make_pair(inicioI, inicioJ);
    inicio.path = "";

    q.push(inicio);

    M[inicioI][inicioJ] = '#';//marca como parede, não há volta

    while(!q.empty()){
        caminho cam = q.front();
        q.pop();

        loopJ(0,4){
            x = cam.cordenada.first + passos[0][col];
            y = cam.cordenada.second + passos[1][col];

            // chegou a B
            if(x == fimI && y == fimJ){
                cout << "YES\n";
                cout << cam.path.size()+1 << "\n";
                cout << cam.path + direcao[col] << "\n";
                return;
            }

            // anda e coloca os proximos na fila
            if(check(x,y,n,m) && M[x][y] != '#'){
                M[x][y] = '#';
                caminho novo;
                novo.cordenada = make_pair(x, y);
                novo.path = cam.path+direcao[col];
                q.push(novo);
            }
        }
    }
    cout << "NO\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int fi, fj;


    queue<pair<int, int>> q;
    loopI(0,n){
        loopJ(0,m){
            cin >> M[row][col];
            dist[i][j] = N*N;
            if(grid[i][j] =='A'){
                q.push(pmake_pair(i,j));
                dist[i][j] = 0;

            }
            if(grid[i][j] == 'B'){
                fi = i;
                fj = j;
            }

        }
    }
    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();
        for(auto [x,y] : mov){
            x += u;
            y += v;

            if(check(x,y)){
                if(dist[x][y] > dist[u][v]+1){
                    dist[]
                }
            }
        }
    }
    return 0;
}
