#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
int arr[MAX];

int main(){
	FASTIO;

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < K; i++) cin >> arr[i];

    map<int,int> m;
    int idx;
    for (idx = 0; m.size() < N; idx++){
        m[arr[idx]] ++;
    }

    int res = 0;
    for (; idx < K; idx++){
        if (m.find(arr[idx]) != m.end()) continue;

        int a, b = -1;
        for (auto it : m){
            bool flag = false;
            int tmp = it.first;
            for (int i = idx + 1; i < K; i++){
                if (arr[i] == tmp) {
                    flag = true;
                    a = i;
                    break;
                }
            }
            if (flag) b = max(b, a);
            else {
                m.erase(tmp);
                break;
            }
        }

        if (m.size() == N) m.erase(arr[b]);
        m[arr[idx]]++;
        res ++;
    }

    cout << res;
    return 0;
}
