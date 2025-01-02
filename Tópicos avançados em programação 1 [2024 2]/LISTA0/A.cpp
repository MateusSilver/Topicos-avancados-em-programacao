#include <bits/stdc++.h>
using namespace std;

int main(){
    // top to bottom, subtract from bottom and add to top
    int A[100];
    int N, K;

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = N-K; i < N; i++){
        cout << A[i] << " ";
    }
    for(int i = 0; i < N-K; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
