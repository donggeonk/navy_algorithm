#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 200005;
ll n, c, lo = -1, hi, mid, res;
ll arr[MAX];

ll check(ll mid){
    ll tmp = 1, sum = 0;
    for (int i = 1; i < n; i++){
        //cout << tmp << ' ' << sum << '\n';
        ll d = arr[i] - arr[i - 1];
        if (sum + d < mid) sum += d;
        else {
            sum = 0;
            tmp ++;
        }
    }
    //cout << tmp << '\n';
    return tmp;
}

int main(){
	FASTIO;

    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    hi = arr[n - 1] - arr[0];
    while(lo <= hi){
        mid = (lo + hi) / 2;
        //cout << lo << ' ' << hi << ' ' << "mid = " << mid << '\n';
        if (check(mid) >= c){
            lo = mid + 1;
            res = max(res, mid);
        }
        else hi = mid - 1;
    }

    cout << res;
	return 0;
}

// 이분탐색의 대상을 공유기 간격으로 정하는 것은 어렵지 않았는데 어떻게 그리디하게 탐색하는 것인가 어려웠다.
// F - T 배열인데 이것도 C개 이상이면 참이라는 결론에 도달해야 했다.
// 두 점 사이의 거리가 mid보다 크면 안된다고 생각했는데 그렇지 않다.
