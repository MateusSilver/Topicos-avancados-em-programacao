#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    long long A[N];

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // 5 = tirostriplos(1) + (5-3) = 2, logo = 3
    long long tirosTriplos = 0;
    long long singleTiros = 0;
    long long totalTiros = 0;

    long long tirosAoTodo = 0;

    for(int i = 0; i<N; i++){
        tirosTriplos = (A[i]/3);

        if(tirosTriplos > 0) {
                tirosTriplos -= 1;
                singleTiros = A[i] - (tirosTriplos)*3;
                totalTiros = singleTiros + tirosTriplos;
        }
        else {
                totalTiros = singleTiros = A[i];
        }
        tirosAoTodo += totalTiros;
        //cout << i << " Triplos: " << tirosTriplos << " Single: " << singleTiros << " Tiros totais: " << totalTiros << endl;
    }

    cout << tirosAoTodo << endl;
}
