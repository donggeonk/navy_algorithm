#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100005;
int arr[105], DP[MAX];

int main(){
    FASTIO;

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i <= k; i++){
        DP[i] = MAX;
        for (int j = 0; j < n; j++){
            if (arr[j] <= i && DP[i - arr[j]] != MAX)
                DP[i] = min(DP[i], DP[i - arr[j]] + 1);
        }
    }

    if (DP[k] == MAX) cout << -1;
    else cout << DP[k];
    return 0;
}
