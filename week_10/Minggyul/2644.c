#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
vector<int> v[MAX];
bool visited[MAX];
int n, m, s, e, x, y;

int BFS(int cur){
    visited[cur] = true;
    queue<int> q;
    q.push(cur);
    
    int level = 1;
    while(!q.empty()){
        int size = q.size();
        for (int i = 0; i < size; i++){
            cur = q.front();
            q.pop();
            
            for (int j = 0; j < v[cur].size(); j++){
                int next = v[cur][j];
                if (next == e) return level;
                if (!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        level ++;
    }
    return -1;
}

int main(){
    FASTIO;
    
    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    cout << BFS(s);
    return 0;
}
