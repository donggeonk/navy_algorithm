#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 11;
int arr[MAX];

int main(){
	FASTIO;

    int N, K, res = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = N - 1; i >= 0; i--){
        res += (K / arr[i]);
        K %= arr[i];
    }

    cout << res;
	return 0;
}
