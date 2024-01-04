#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 105;
bool visited[MAXN];
string A[MAXN];

int main(){
    FASTIO;

    string S;
    cin >> S;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    int sl = S.size();
    visited[0] = true;
    for (int i = 0; i < sl; i++){
        if (!visited[i]) continue;

        for (int j = 0; j < n; j++){ // string A[j]
            int al = A[j].size();
            if (i + al > sl) continue; // Fail
            bool flag = true;

            for (int k = 0; k < al; k++){
                if (S[i + k] != A[j][k]) flag = false;
            }
            if (flag) visited[i + al] = true;
        }
    }

    cout << visited[sl];
    return 0;
}
