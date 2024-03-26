#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100005;
int s[MAX], res;
bool visited[MAX], finished[MAX];

void dfs(int cur){
    visited[cur] = true;
    int next = s[cur];
    
    if (!visited[next]) dfs(next);
    else {
        if (!finished[next]){ // cylce 발견
            res ++;
            for (int i = next; i != cur; i = s[i]) res ++;
        }
    }
    finished[cur] = true;
}

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for (int i = 1; i <= n; i++) cin >> s[i];
        
        res = 0;
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        for (int i = 1; i <= n; i++)
            if (!visited[i]) dfs(i);
        cout << n - res << '\n';
    }
    return 0;
}
