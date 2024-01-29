#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 133333;
ll n, atk, ch, ca, lo, hi, mid;
ll t[MAX], a[MAX], h[MAX];

int main(){
	FASTIO;

    cin >> n >> atk;
    for (int i = 0; i < n; i++) cin >> t[i] >> a[i] >> h[i];

    hi = 9e18;
    while(lo + 1 < hi){
        bool flag = true;
        mid = (lo + hi) / 2;
        ch = mid;
        ca = atk;
        for (int i = 0; i < n; i++){
            if (t[i] == 1){
                if ((h[i] - 1) / ca > (ch - 1) / a[i]){
                    flag = false;
                    break;
                }
                else {
                    ch -= (h[i] - 1) / ca * a[i];
                }
            }
            else {
                ca += a[i];
                ch = min(ch + h[i], mid);
            }
        }

        if (flag) hi = mid;
        else lo = mid;
    }

    cout << hi;
	return 0;
}

// 1. 몬스터 방에서 HP - 1을 설정하는 것
// 2. lo + 1 < hi 범위에서 hi = mid ,lo = mid로 설정하는 것
