#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 100005;
ll n, m, lo, hi, mid; 
ll arr[MAX];

bool check(ll tmp){
    ll sum = 0, res = 1;
    for (int i = 0; i < n; i++){
        if (arr[i] > tmp) return true;
        if (sum + arr[i] > tmp){
            res ++;
            sum = arr[i];
        }
        else sum += arr[i];
        // cout << arr[i] << ' ' << res << '\n';
    }
    return res > m;
}

int main(){
	FASTIO;

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];

    hi = INT_MAX / 2;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
       // cout << lo << ' ' << hi << '\n';
    }

    cout << lo;
	return 0;
}

// 이분탐색의 기준 값을 블루레이 크기의 최댓값으로 정한 것이 참신했다.
// 이분탐색의 기준 값이 하나의 항보다 작다면 성립하지 않기 때문에 이를 처리해줘야 한다.
