#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
bool arr[MAX][MAX], visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int m, n, k ;

int dfs(int x, int y){
    int node = 1;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < m && ny >= 0 && ny < n){
            if (arr[nx][ny] && !visited[nx][ny]){
                node += dfs(nx, ny);
            }
        }
    }

    return node;
}

int main(){
    FASTIO;

    int a, b, c, d;
    cin >> m >> n >> k; // 행과 열
    memset(arr, true, sizeof(arr));
    for (int i = 0; i < k; i++){
        cin >> a >> b >> c >> d;
        for (int x = a; x < c; x++){
            for (int y = b; y < d; y++){
                arr[y][x] = false;
            }
        }
    }

    int temp;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] && !visited[i][j]){
                temp = dfs(i, j);
                pq.push(temp);
            }
        }
    }

    cout << pq.size() << '\n';
    while(!pq.empty()){
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}
