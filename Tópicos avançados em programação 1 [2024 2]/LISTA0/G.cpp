#include <bits/stdc++.h>
using namespace std;

typedef struct ball {
    long long number;
    long long quant;
}ball;

void removeball(vector<ball>& A, int numero){
    for(auto it = A.begin(); it != A.end(); ++it){
        if(it->number == numero){
            it->quant--;
            if(it->quant <= 0){
                A.erase(it);
            }
            return;
        }
    }
}

void print(vector<ball> A){

    /*for(auto it: A){
        cout << it.number << " ";
    }*/
    cout << A.size() << endl;
}

void insertball(vector<ball>& A, int item){
    ball* b = NULL;
    for(auto& it: A){
        if(it.number == item){
            b = &it;
        }
    }

    if(b){
        b->quant++;
    } else {
        A.push_back({item,1});
    }
}

int main(){
    long long N;
    cin >> N;

    vector<ball> A;

    int key;
    long long valor;

    while(N--){
        cin >> key;
        if(key == 3){
            cout << A.size() << endl;
        }
        if(key == 2){
            cin >> valor;
            removeball(A, valor);
        }
        if(key == 1) {
            cin >> valor;
            insertball(A, valor);
        }
    }
}
