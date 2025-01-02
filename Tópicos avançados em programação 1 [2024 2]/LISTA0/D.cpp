// usando set para criar substrings unicas
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    set<string> substrings;
    string temp;
    int n = S.length();

    for(int i = 0; i < n; i++){
        temp = "";
        for(int j = i; j < n; j++){
            temp += S[j];
            substrings.insert(temp);
        }
    }
    cout << substrings.size() << endl;

    /*
    for(auto b: substrings){
        cout << b << endl;
    }
    */
}
