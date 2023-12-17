#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 55;
char arr[MAX][MAX];

int main(){
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }
    
    int res = 64;
    for (int a = 0; a <= N - 8; a++){
        for (int b = 0; b <= M - 8; b++){
            int k = 0;
            for (int i = 0; i < 8; i++){
                for (int j = 0; j < 8; j++){
                    if ((i + j) % 2 == 0 && arr[a + i][b + j] == 'W') k++;
                    else if ((i + j) % 2 == 1 && arr[a + i][b + j] == 'B') k++;
                }
            }
            res = min({res, k, 64 - k});
        }
    }
    
    cout << res;
}
