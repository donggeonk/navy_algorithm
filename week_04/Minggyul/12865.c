#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 105;
const int MAXK = 100005;
ll DP[MAXN][MAXK], W[MAXN], V[MAXN];

int main(){
    FASTIO;

    ll n, k, res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> W[i] >> V[i];
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            if (j < W[i]) DP[i][j] = DP[i - 1][j];
            else DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
            res = max(res, DP[i][j]);
        }
    }
    cout << res;
    return 0;
}
