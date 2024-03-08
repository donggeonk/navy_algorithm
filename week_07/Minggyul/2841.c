#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

stack<int> S[10];

int main(){
    FASTIO;
    
    int N, P, res = 0;
    cin >> N >> P;
    for (int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        if (S[a].empty()) {
            S[a].push(b);
            res ++;
        }
        else if (S[a].top() < b){
            S[a].push(b);
            res ++;
        }
        else {
            while(S[a].top() > b){
                res ++;
                S[a].pop();
                if (S[a].empty()) {
                    S[a].push(b);
                    res ++;
                    break;
                }
            }
            if (S[a].top() != b){
                res ++;
                S[a].push(b);
            }
        }
    }
    
    cout << res;
    return 0;
}

/* 2841 외계인의 기타 연주
1. stack이 비어있으면 넣는다.
2. stack의 top보다 넣어야하는게 크면 넣는다.
3. stack의 top보다 넣어야하는게 작으면 팝한다.
+ stack의 top이 같으면 그냥 둔다.
*/
