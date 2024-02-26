#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 55;
int arr[MAX];

int main(){
    FASTIO;

    int N, M, res = 0;
    deque<int> dq;
    cin >> N >> M;
    for (int i = 0; i < M; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) dq.push_back(i);
    
    for (int i = 0; i < M; i++){
        int a = find(dq.begin(), dq.end(), arr[i]) - dq.begin();
        int b = dq.size() - 1;
        if (a > b - a + 1){
            res += b - a + 1;
            for (int j = 0; j <= b - a; j++){
                int c = dq.back();
                dq.pop_back();
                dq.push_front(c);
            }
        }
        else {
            res += a;
            for (int j = 0; j < a; j++){
                int c = dq.front();
                dq.pop_front();
                dq.push_back(c);
            }
        }
        dq.pop_front();
    }
    
    cout << res;
    return 0;
}
// deque 사용법
// find함수를 사용할 수 있다.
