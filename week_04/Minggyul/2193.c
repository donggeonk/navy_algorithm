#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 95;
ll DP[MAX][2];

int main(){
    FASTIO;

    int N; cin >> N;
    DP[1][1] = 1;
    for (int i = 2; i <= N; i++){
        DP[i][0] = DP[i - 1][0] + DP[i - 1][1];
        DP[i][1] = DP[i - 1][0];
    }

    cout << DP[N][0] + DP[N][1];
    return 0;
}
