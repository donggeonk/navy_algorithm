#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1234;
char arr[MAX][MAX];
bool fv[MAX][MAX], sv[MAX][MAX];
int dist[MAX][MAX];
int w, h, sx, sy;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> fq;
    
void solved(){
    queue<pair<int, int>> sq;
    sq.push({sx, sy});
    sv[sx][sy] = true;
    dist[sx][sy] = 0;
    
    queue<pair<int,int>> temp;
    while(!sq.empty()){
        while(!fq.empty()){
            int fcx = fq.front().first;
            int fcy = fq.front().second;
            fq.pop();
            
            for (int i = 0; i < 4; i++){
                int fnx = fcx + dx[i];
                int fny = fcy + dy[i];
                if (fnx >= 0 && fnx < w && fny >= 0 && fny < h){
                    if (arr[fnx][fny] != '#' && !fv[fnx][fny]){
                        fv[fnx][fny] = true;
                        arr[fnx][fny] = '*';
                        temp.push({fnx, fny});
                    }
                }
            }
        }
        
        while(!temp.empty()) {
            int a = temp.front().first;
            int b = temp.front().second;
            temp.pop();
            fq.push({a, b});
        }
        
        while(!sq.empty()){
            int scx = sq.front().first;
            int scy = sq.front().second;
            sq.pop();
            
            for (int i = 0; i < 4; i++){
                int snx = scx + dx[i];
                int sny = scy + dy[i];
                if (snx >= 0 && snx < w && sny >= 0 && sny < h){
                    if (arr[snx][sny] == '.' && !sv[snx][sny]){
                        sv[snx][sny] = true;
                        temp.push({snx, sny});
                        dist[snx][sny] = dist[scx][scy] + 1;
                    }
                }
                else { // 발견
                    cout << dist[scx][scy] + 1 << '\n';
                    return;
                }
            }
        }
        
        while(!temp.empty()) {
            int a = temp.front().first;
            int b = temp.front().second;
            temp.pop();
            sq.push({a, b});
        }
    }
    
    cout << "IMPOSSIBLE\n";
}

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        memset(fv, false, sizeof(fv));
        memset(sv, false, sizeof(sv));
        memset(dist, 0, sizeof(dist));
        while(!fq.empty()) fq.pop();
        
        cin >> h >> w;
        for (int i = 0; i < w; i++){
            for (int j = 0; j < h; j++){
                cin >> arr[i][j];
                if (arr[i][j] == '@') sx = i, sy = j;
                if (arr[i][j] == '*') {
                    fq.push({i, j});
                    fv[i][j] = true;
                }
            }
        }
        solved();
    }
    return 0;
}
