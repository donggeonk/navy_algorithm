#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 100005;
ll n, m, lo, hi, mid;
ll arr[MAX];

bool check (ll mid){
    ll sum = 0, res = 1;
    for (int i = 0; i < n; i++){
        if (arr[i] > mid) return true;
        if (sum + arr[i] > mid){
            sum = arr[i];
            res ++;
        }
        else sum += arr[i];
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
    }

    cout << lo;
	return 0;
}
