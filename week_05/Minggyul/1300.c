#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long

int main(){
    FASTIO;

    ll N, K;
    cin >> N >> K;

    ll lo = 0, hi = N * N + 1, mid, res;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        ll tmp = 0;
        
        for (ll i = 1; i <= N; i++)
            tmp += min(mid / i, N); // i * N까지만 가능하므로
        
        if (tmp >= K){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res;
    return 0;
}

// lo <= hi 범위를 찾는 것이 힘들다.
// B[k]를 이분탐색의 대상으로 한다.
// min(mid / i, N)
