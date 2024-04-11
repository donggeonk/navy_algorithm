#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 35;
char b[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int L, R, C, si, sj, sk, ei, ej, ek;

void bfs(){
    queue<pair<pair<int,int>, int>> q;
    q.push({{sj, sk}, si});
    visited[sj][sk][si] = true;
    
    while(!q.empty()){
        int cj = q.front().first.first;
        int ck = q.front().first.second;
        int ci = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++){
            int nj = cj;
            int nk = ck;
            int ni = ci;
            if (i == 5) {
                ni --;
            }
            else if (i == 4){
                ni ++;
            }
            else {
                nj += dx[i];
                nk += dy[i];
            }
            
            if (nj >= 0 && nj < R && nk >= 0 && nk < C && ni >= 0 && ni < L){
                if (b[nj][nk][ni] != '#' && !visited[nj][nk][ni]){
                    dist[nj][nk][ni] = dist[cj][ck][ci] + 1;
                    visited[nj][nk][ni] = true;
                    q.push({{nj, nk}, ni});
                }
            }
        }
    }
}

int main(){
    FASTIO;
    
    string buffer;
    while(true){
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;
        
        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        for(int i = 0; i < L; i++){
            for (int j = 0; j < R; j++){
                for (int k = 0; k < C; k++){
                    cin >> b[j][k][i];
                    if (b[j][k][i] == 'S') {
                        sj = j, sk = k, si = i;
                    }
                    if (b[j][k][i] == 'E'){
                        ej = j, ek = k, ei = i;
                    }
                }
            }
            getline(cin, buffer);
        }
        
        bfs();
        if (visited[ej][ek][ei]) cout << "Escaped in " << dist[ej][ek][ei] << " minute(s).\n";
        else cout << "Trapped!\n";
    }
    
    return 0;
}
