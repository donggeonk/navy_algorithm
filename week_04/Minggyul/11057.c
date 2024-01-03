#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 1005;
const int MOD = 10007;
ll DP[MAX][10];

int main(){
    FASTIO;

    int n; cin >> n;
    for (int j = 0; j <= 9; j++) DP[1][j] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= 9; j++){
            if(j == 0) DP[i][j] = DP[i - 1][j] % MOD;
            else DP[i][j] = (DP[i][j - 1] + DP[i - 1][j]) % MOD;
        }
    }

    int res = 0;
    for (int j = 0; j <= 9; j++) res += DP[n][j] % MOD;
    cout << res % MOD;
    return 0;
}
