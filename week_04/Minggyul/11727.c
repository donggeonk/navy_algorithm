#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 1005;
ll DP[MAX];

int main(){
    FASTIO;

    int n; cin >> n;
    DP[1] = 1, DP[2] = 3;
    for (int i = 3; i <= n; i++) DP[i] = (DP[i - 2]*2 + DP[i - 1]) % 10007;
    cout << DP[n];
    return 0;
}
