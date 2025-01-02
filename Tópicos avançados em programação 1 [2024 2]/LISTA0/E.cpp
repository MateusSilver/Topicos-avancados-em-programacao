#include <bits/stdc++.h>
using namespace std;

int counts_positives(vector<int> v, int n){
    int positives = 0;
    for(int i = 0; i<n; i++){
        if(v[i] > 0){
            positives++;
        }
    }
    return positives;
}

int sort_reference(int a, int b){
    return a > b;
}

int main(){
    int N;
    int num;

    cin >> N;
    vector<int> A;
    for(int i = 0; i < N; i++){
        cin >> num;
        A.push_back(num);
    }

    int operacoes = 0;
    while(counts_positives(A,N) > 1) {
        sort(A.begin(), A.end(),sort_reference);
        A[0]--;
        A[1]--;
        operacoes++;
        /*for(int n : A){
            cout << n << " ";
        }
        cout << endl;*/
    }
    cout << operacoes << endl;
}
