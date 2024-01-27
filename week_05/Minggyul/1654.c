#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 100005;
ll k, n, lo, hi, mid, res;
ll arr[MAX];

ll check (ll mid){
    ll tmp = 0;
    if (mid == 0) return n;
    for (int i = 0; i < k; i++){
        tmp += (arr[i] / mid);
    }
    return tmp;
}

int main(){
	FASTIO;

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }

    while(lo <= hi){
        mid = (lo + hi) / 2;
        if (check(mid) >= n){
            res = max(res, mid);
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << res;
	return 0;
}

// 이분탐색
// 1. 기준값을 정한다.
// 2. T - F 배열 혹은 F - T 배열인지 안다
// 3. T 배열에서 res라는 수를 도입하면서 답을 도출한다.
