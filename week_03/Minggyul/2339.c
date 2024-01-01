#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 22;
int arr[MAX][MAX];

int solved(int sx, int ex, int sy, int ey, int dir){
    int d = 0;
    vector<pair<int, int>> b;

    for (int i = sx; i < ex; i++){
        for (int j = sy; j < ey; j++){
            if (arr[i][j] == 1) b.push_back({i, j});
            if (arr[i][j] == 2) d++;
        }
    }

    if (d == 1 && b.size() == 0) return 1;
    if (d == 0) return 0;
    if (b.size() == 0) return 0;

    int res = 0;
    if (dir != 1){
        for(int k = 0; k < b.size(); k++){
            bool flag = true;
            int x = b[k].first;

            for (int j = sy; j < ey; j++){
                if (arr[x][j] == 2) {
                    flag = false;
                    break;
                }
            }

            if (flag) res += solved(sx, x, sy, ey, 1) * solved(x + 1, ex, sy, ey, 1);
        }
    }

    if (dir != 2){
        for(int k = 0; k < b.size(); k++){
            bool flag = true;
            int y = b[k].second;

            for (int i = sx; i < ex; i++){
                if (arr[i][y] == 2) {
                    flag = false;
                    break;
                }
            }

            if (flag) res += solved(sx, ex, sy, y, 2) * solved(sx, ex, y + 1, ey, 2);
        }        
    }

    return res;
}

int main(){
    FASTIO;

    int N; cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    int res = solved(0, N, 0, N, 0);
    if (res == 0) cout << -1;
    else cout << res;
    return 0;
}
