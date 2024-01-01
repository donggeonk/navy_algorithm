#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1000005;
int DP[MAX];

int main(){
    FASTIO;

    int N; cin >> N;
    DP[1] = 0, DP[2] = 1, DP[3] = 1;
    for (int i = 4; i <= N; i++){
        DP[i] = DP[i - 1] + 1;
        if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
        if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
    }

    cout << DP[N];
    return 0;
}
