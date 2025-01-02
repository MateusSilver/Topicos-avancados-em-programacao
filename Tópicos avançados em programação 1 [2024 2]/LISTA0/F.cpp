#include <bits/stdc++.h>
using namespace std;

long long countCraken = 0;

void craken(long long* A, long long i){
    countCraken++;
    if(countCraken%3 == 0){
        A[i] -= 3;
    } else {
        A[i] -= 1;
    }
    return;
}

int main(){
    long long N;
    cin >> N;

    long long A[N];
    for(long long i = 0; i < N; i++){
        cin >> A[i];
    }
    for(long long i = 0; i < N; i++){
        while(A[i] > 0){
            craken(A,i);
            /*for(int j = 0; j<N; j++){
                cout << A[j] << " ";
            }
            cout << endl;*/
        }
    }
    cout << countCraken << endl;
}
