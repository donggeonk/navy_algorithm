#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 10005;
ll A[MAX], B[MAX], C[MAX];

int main(){
	FASTIO;

    ll N, K, D;
    cin >> N >> K >> D;
    for (int i = 0; i < K; i++)
        cin >> A[i] >> B[i] >> C[i];

    ll lo = 0, hi = 1000005, res;
    res = hi;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        ll tmp = 0; // mid까지 들어가는 총 도토리의 개수

        for (int i = 0; i < K; i++){
            if (mid >= B[i]) tmp += (B[i] - A[i]) / C[i] + 1;
            else if (mid >= A[i]) tmp += (mid - A[i]) / C[i] + 1;
        }

        if (tmp < D) lo = mid;
        else {
            res = min(res, mid);
            hi = mid;
        }
    }

    cout << res;
	return 0;
}

// O(N*K)에서 수학적인 수식으로 표현하는 것을 발견하고 O(K*logN)으로 발전시킬 수 있었다.
// 정답이 마지막 도토리가 들어가는 방이기 때문에 이분탐색의 주체를 찾는 것은 쉽다.
