#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 100005;
ll DP[MAX];

int main(){
    FASTIO;

    int n; cin >> n;
    for (int i = 1; i * i <= MAX; i++){
        DP[i * i] = 1;
    }
    
    for (int i = 1; i <= n; i++){
        if (!DP[i]) DP[i] = MAX;
        for (int j = 1; j * j <= i; j++){
            DP[i] = min(DP[i], DP[j * j] + DP[i - j * j]);
        }
    }

    cout << DP[n];
    return 0;
}
