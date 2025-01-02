#include <bits/stdc++.h>
using namespace std;

/**Lista 7 - C
encontre o numero k que mais divide numeros em um vetor A.
**/

#define rep(i, a, b) for(int i = a; i < b; i++)
#define ll long long

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}



int divisiveis(vector<int> a) {
    int maxElem = *max_element(a.begin(), a.end());
    vector<int> divCount(maxElem + 1, 0);
    int n = a.size();

    for (int num : a) {
        for (int k = 2; k <= num; ++k) {
            if (num % k == 0) {
                divCount[k]++;
            }
        }
    }

    int maxGCDness = 0;
    int bestK = 2;
    for (int k = 2; k <= maxElem; ++k) {
        if (divCount[k] > maxGCDness) {
            maxGCDness = divCount[k];
            bestK = k;
        }
    }

    return bestK;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    cout << divisiveis(a) << "\n";
    return 0;
}
