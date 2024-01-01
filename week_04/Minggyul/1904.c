#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 1000005;
ll DP[MAX];

int main(){
    FASTIO;

    int N; cin >> N;
    DP[1] = 1, DP[2] = 2;
    for (int i = 3; i <= N; i++){
        DP[i] = DP[i - 1] + DP[i - 2];
        DP[i] %= 15746;
    }

    cout << DP[N];
    return 0;
}
