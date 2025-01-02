// vetor com 2 casos
/*
1. ele quer a soma entre os cara de l a r
2. considerando que o vetor esta ordenado, fazer a soma dos i maiores ate os j maiores i<j

faça então 2 prefixos, um do vetor ordenado e outro do vetor normal

*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+100;

int A[MAXN];
int B[MAXN];

int main(){
    int n, q;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B, B+n);
    for(int i = 1; i < n; i++){
        A[i] += A[i] + A[i-1];
        B[i] += B[i] + B[i-1];
    }

    int l, r;
    int caso;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> caso >>  l >> r;
        if(caso == 1){
            if(l>1){
                cout << A[r-1] - A[l-2] << "\n";
            } else {
                cout << A[r-1] << "\n";
            }
        }
        if(caso == 2){
            if(l>1){
                cout << A[r-1] - A[l-2] << "\n";
            } else {
                cout << A[r-1] << "\n";
            }
        }
    }
}
