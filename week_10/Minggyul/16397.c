#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100000;
int visited[MAX];
int n, t, g;

void bfs(){
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if (visited[x] > t + 1) break;
        if (x == g) {
            cout << visited[x] - 1;
            return;
        }

        if (x + 1 >= 0 && x + 1 < MAX){
            if (!visited[x + 1]){
                visited[x + 1] = visited[x] + 1;
                q.push(x + 1);
            }
        }

        int nx, i;
        for (i = 1; i <= 2 * x; i *= 10);
        nx = 2 * x - i / 10;
        
        if (2 * x >= 0 && 2 * x < MAX){
            if (!visited[nx]){
                visited[nx] = visited[x] + 1;
                q.push(nx);
            }
        }
    }

    cout << "ANG";
}

int main(){
    FASTIO;

    cin >> n >> t >> g;
    if (n == g) cout << 0;
    else bfs();
    return 0;
}
