#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100005;
int arr[2][MAX], DP[2][MAX];

int main(){
    FASTIO;

    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for (int i = 0; i < N; i++) cin >> arr[0][i];
        for (int i = 0; i < N; i++) cin >> arr[1][i];

        DP[0][0] = arr[0][0];
        DP[1][0] = arr[1][0];
        DP[0][1] = DP[1][0] + arr[0][1];
        DP[1][1] = DP[0][0] + arr[1][1];

        for (int i = 2; i < N; i++){
            DP[0][i] = max({DP[1][i - 1], DP[1][i - 2], DP[0][i - 2]}) + arr[0][i];
            DP[1][i] = max({DP[0][i - 1], DP[0][i - 2], DP[1][i - 2]}) + arr[1][i];
        }

        cout << max(DP[0][N - 1], DP[1][N - 1]) << '\n';
    }
    return 0;
}
