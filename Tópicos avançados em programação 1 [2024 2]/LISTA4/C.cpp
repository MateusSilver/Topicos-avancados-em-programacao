#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i<b; i++)
const int MAXN = 2e5+100;
const int INF = 1e9+100;

int A[MAXN];
long long SUF[MAXN];
int B[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    rep(i,0,n){
        cin >> A[i];
        B[i] = A[i];
    }

    sort(A, A+n);
    for(int i = n-1; i>=0; i--){
        SUF[i] = A[i];
        if(i < n-1){
            SUF[i] += SUF[i+1];// somas de cima abaixo dos valores maiores do vetor ordenado
        }
    }

    for(int i = 0; i <n; i++){
        int l=0, r = n-1, mid, ans = n;
        while(l<=r){
            mid = l + ((r-l)>>1);
            if(A[mid]>B[i]){
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout << SUF[ans] << " ";
    }
    cout << "\n";

    return 0;
}

