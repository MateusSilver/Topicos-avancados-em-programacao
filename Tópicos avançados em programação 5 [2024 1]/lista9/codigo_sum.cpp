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
ll a[N], s = 0;

void add(int x)
{
    s += a[x];
}

void rmv(int x)
{
    s-=a[x];
}

ll calc(){
    return s;
}


void solve()
{
    sort(queries.begin(),queries.end(),cmp);
    ans.resize(queries.size());

    int i = 0, j = -1;

    for(auto at:queries)
    {
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

    solve();

    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}
