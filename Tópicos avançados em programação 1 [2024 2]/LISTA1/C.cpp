#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
/*
void print_queue(queue<int> A){
    queue<int> temp = A;
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << "(fila)\n";
}

void print_stack(stack<int> B){
    stack<int> temp = B;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << "(stack)\n";
}*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> A;
    stack<int> B;
    queue<int> C;

    int n, entrada;
    cin >> n;

    while(n != 0){
        while(!A.empty()){
            A.pop();
        }

        //cout << "A feita\n";
        rep(i,0,n){
            A.push(i+1);
        }
        //cout << "primeira entrada\n";
        cin >> entrada;
        while(entrada != 0){
            while(!C.empty()){
                C.pop();
            }
            while(!B.empty()){
                B.pop();
            }
            if(A.empty()){
                rep(i,0,n){
                    A.push(i+1);
                }
            }
            C.push(entrada);
            //cout << "push in C\n";
            rep(i,1,n){
                //cout << "entrada " << i+1 << "\n";
                cin >> entrada;
                C.push(entrada);
                //cout << "push in C\n";
            }
            //cout << "voce inseriu: ";
            //print_queue(C);
            //cout << "valores: ";
            //print_queue(A);
            while( ( (!B.empty() && !C.empty()) && B.top() == C.front()) || (!A.empty() && !C.empty()) ){
                //cout << "analisando\n";

                if(!B.empty() && C.front() == B.top()){
                    /*cout << "tira de B para C\n";
                    cout << "A: ";
                    print_queue(A);
                    cout << "B: ";
                    print_stack(B);
                    cout << "C: ";
                    print_queue(C);*/
                    C.pop();
                    B.pop();
                } else {
                    /*cout << "tira de A para B\n";
                    cout << "A: ";
                    print_queue(A);
                    cout << "B: ";
                    print_stack(B);
                    cout << "C: ";
                    print_queue(C);*/
                    B.push(A.front());
                    A.pop();
                }
            }
            if(B.empty()){
                cout << "Yes";
            } else {
                cout << "No";
            }
            //cout << "primeira nova entrada\n";
            cin >> entrada;
            cout << "\n";
        }
        cout << "\n";
        cin >> n;
    }

}

