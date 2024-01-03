#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 1005;
const int MOD = 10007;
ll DP[MAX][MAX];

int main(){
    FASTIO;

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        DP[i][0] = DP[i][i] = 1;
    }
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= i - 1; j++){
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % MOD;
        }
    }

    cout << DP[n][k];
    return 0;
}
