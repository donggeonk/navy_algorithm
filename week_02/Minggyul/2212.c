#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 10005;
int arr[MAX];

int main(){
    FASTIO;

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int res = 0;
    vector<int> v;
    for (int i = 1; i < N; i++){
        res += arr[i] - arr[i - 1];
        v.push_back(arr[i] - arr[i - 1]);
    }
    sort(v.rbegin(), v.rend());

    for (int i = 0; i < K - 1 && i < N - 1; i++) res -= v[i];
    cout << res;
    return 0;
}
