#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>
#define loop(i,a,b) for(ll i=a; i<b; i++)

void encontrarsoma(vector<pp> v, ll n, ll k){
    ll i = 0;
    ll j = n-1;
    pp l, r;

    while(i<j){
        l = v[i];
        r = v[j];
        if(l.first + r.first > k ){
            j--;
        } else {
            if(l.first + r.first < k){
                i++;
            } else {
                if(l.second > r.second ){
                    cout << r.second << " " << l.second << "\n";
                    return;
                } else{
                    cout << l.second << " " << r.second << "\n";
                    return;
                }

            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

void print_(vector<pp> v, ll n){
    pp entrada;
    loop(i,0,n){
        entrada = v[i];
        cout << entrada.first << "\t" << entrada.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    ll k;
    cin >> n;
    cin >> k;

    vector<pp> v;
    ll entrada;

    loop(i,0,n){
        cin >> entrada;
        v.push_back(make_pair(entrada, i+1));
    }


    sort(v.begin(), v.end());
    //print_(v,n);
    encontrarsoma(v,n,k);

    return 0;
}
