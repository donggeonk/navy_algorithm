#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 1005;
ll DP[MAX];

int main(){
    FASTIO;

    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> DP[i];
        for (int j = 1; j < i; j++)
            DP[i] = max(DP[i], DP[j] + DP[i - j]);
    }
    cout << DP[n];
    return 0;
}
