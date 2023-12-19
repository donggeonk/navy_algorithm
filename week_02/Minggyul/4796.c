#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
	FASTIO;

    int L, P, V;
    for(int t = 1; ; t++){
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        int res = (V / P) * L;
        if ((V % P) > L) res += L;
        else res += (V % P);

        cout << "Case " << t << ": " << res << '\n';
    }
	return 0;
}
