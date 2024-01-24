#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 10005;
ll n, m, lo = 0, hi = 0, mid;
ll arr[MAX];

bool check(ll tmp){
    
    ll res = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > tmp) res += tmp;
        else res += arr[i];
    }
    return res <= m;
}

int main(){
	FASTIO;

    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        hi = max(hi, arr[i]);
    }
    cin >> m;

    while(lo <= hi){
        mid = (lo + hi) / 2;
        if (check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << lo - 1;
	return 0;
}
// 이분탐색 조건 설정에 어려움을 겪음, 일관성있게 조건 설정하는 방법을 터득하지 못함
