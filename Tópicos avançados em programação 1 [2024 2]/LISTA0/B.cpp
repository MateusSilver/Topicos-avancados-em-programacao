#include <bits/stdc++.h>
using namespace std;

int main(){
    // swap 2 equal range of integers in a vector
    int A[100];
    int A1, A2, B1, B2;
    int N;

    cin >> N >> A1 >> A2 >> B1 >> B2;

    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    int razao = B1 - A1;

    for(int i = 0 ; i<N; i++){
        if( (i >= A1-1 && i<A2) || (i>=B1-1 && i<B2) ){
            if(i>= A1-1 && i< A2){
                cout << A[i+razao] << " ";
            }
            if(i>=B1-1 && i< B2){
                cout << A[i-razao] << " ";
            }
        } else {
            cout << A[i] << " ";
        }
    }
    cout << endl;
}
