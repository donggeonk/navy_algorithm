#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 25;
int N, S, res;
int arr[MAX];

void Backtracking(int cnt, int sum){
    if (cnt == N){
        if (sum == S) res ++;
        return ;
    }

    Backtracking(cnt + 1, sum + arr[cnt]);
    Backtracking(cnt + 1, sum);
}

int main(){
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> arr[i];

    Backtracking(0, 0);
    if (S == 0) cout << res - 1;
    else cout << res;
}
