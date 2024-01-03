#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 105;
const int MOD = 1000000000;
ll DP[MAX][10];

int main(){
    FASTIO;

    int n; cin >> n;
    for (int j = 1; j <= 9; j++) DP[1][j] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= 9; j++){
            if (j == 0) DP[i][j] = (DP[i - 1][j + 1]) % MOD;
            else if (j == 9) DP[i][j] = (DP[i - 1][j - 1]) % MOD;
            else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
        }
    }

    ll res = 0;
    for (int j = 0; j <= 9; j++) res += DP[n][j];
    cout << res % MOD;
    return 0;
}
