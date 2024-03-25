#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 55;
bool arr[MAX][MAX];
bool visited[MAX][MAX];
int dir_x[] = {-1, 1, 0, 0};
int dir_y[] = {0, 0, -1, 1};
int N, M;

void dfs(int x, int y){
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++){
        int next_x = x + dir_x[i];
        int next_y = y + dir_y[i];
        
        if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M){
            if (arr[next_x][next_y] && !visited[next_x][next_y]) 
                dfs(next_x, next_y);
        }
    }
}

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        int K, x, y, res = 0;
        memset(arr, false, sizeof(arr));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++){
            cin >> y >> x;
            arr[x][y] = true;
        }
        
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (arr[i][j] && !visited[i][j]){
                    dfs(i, j);
                    res ++;
                }
            }
        }
        
        cout << res << '\n';
    }
    return 0;
}
