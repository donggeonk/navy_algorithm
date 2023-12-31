#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 100005;
ll N, arr[MAX], sum[MAX];

ll solved(ll s, ll e){
    if (s == e) return 0;
    if (s + 1 == e) return arr[s] * arr[s];

    ll mid = (s + e) / 2;
    ll res = max(solved(s, mid), solved(mid, e));

    ll h = arr[mid];
    ll l = mid, r = mid;
    while(r - l + 1 < e - s){
        ll p = l > s ? min(h, arr[l - 1]) : -1; 
        ll q = r < e - 1? min(h, arr[r + 1]) : -1; 
        ll w = l == 0? sum[r] : sum[r] - sum[l - 1];

        if (p == -1) {
            h = q;
            r ++;
            w += arr[r];
        }
        else if (q == -1) {
            h = p;
            l --;
            w += arr[l];
        }
        else if ((w + arr[l - 1]) * p >= (w + arr[r + 1]) * q){
            h = p;
            l --;
            w += arr[l];
        }
        else {
            h = q;
            r ++;
            w += arr[r];
        }

        res = max(res, w*h);
    }
    return res;
}

int main(){
    FASTIO;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sum[0] = arr[0];
    for (int i = 1; i < N; i++){
        sum[i] = sum[i - 1] + arr[i];
    }
    cout << solved(0, N);
    return 0;
}
