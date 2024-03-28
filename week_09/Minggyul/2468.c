#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, h, res;

void dfs(int x, int y, int k){
    visited[x][y] = true;
    
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < n){
            if (arr[nx][ny] > k && !visited[nx][ny]){
                dfs(nx, ny, k);
            }
        }
    }
}

int main(){
    FASTIO;

    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            h = max(h, arr[i][j]);
        }
    }

    for (int k = 0; k <= h; k++){
        memset(visited, false, sizeof(visited));
        int temp = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (arr[i][j] > k && !visited[i][j]){
                    dfs(i, j, k);
                    temp ++;
                }
            }
        }
        res = max(res, temp);
    }
    
    cout << res;
    return 0;
}
