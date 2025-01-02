#include<bits/stdc++.h>
using namespace std;

const int N = 200100;
const int K = 450;
typedef long long ll;

struct query{
    int idx, l, r;
};

bool cmp(query x, query y)
{
    if(x.l/K == y.l/K)
    {
        if((x.l/K)%2 == 1)
            return x.r > y.r;
        return x.r < y.r;
    }
    return x.l/K < y.l/K;
}

vector<ll> ans;
vector<query> queries;
ll a[N];
ll s[N];
int sizeS = 0;

void add(int x)
{

    s[a[x]-1] += 1;
    //cout << "add in " << a[x] << " " << s[a[x]] << "\n";

    if(a[x] > sizeS){
        sizeS = a[x];
    }
}

void rmv(int x)
{

    s[a[x]-1] -= 1;
    //cout << "rmv in " << a[x] << " " <<  s[a[x]] <<"\n";

}

ll calc(){
    //cout << "calculating result\n";
    int resultado;
    for(int i = 0; i<=sizeS; i++){
        //cout << s[i] << " ";
        resultado += s[i]*s[i]*i;
    }
    return resultado;
}


void solve()
{
    sort(queries.begin(),queries.end(),cmp);
    ans.resize(queries.size());

    int i = 0, j = -1;

    for(auto at:queries)
    {
        //cout << "in queries\n";
        int l,r,idx;
        l = at.l;
        r = at.r;
        idx = at.idx;

        while(j < r)
        {
            j++;
            add(j);
        }
        while(j > r)
        {
            rmv(j);
            j--;
        }

        while(i < l)
        {
            rmv(i);
            i++;
        }

        while(i > l)
        {
            i--;
            add(i);
        }

        ans[idx] = calc();
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < q; i++)
    {
        query aux;
        cin >> aux.l >> aux.r;
        aux.l--;
        aux.r--;
        aux.idx = i;
        queries.push_back(aux);
    }

    //cout << "solving\n";
    solve();

    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}
