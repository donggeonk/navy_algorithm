#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, r, c, res;

void solved(int row, int col, int size){
    if (row == r && col == c) {
        cout << res;
        exit(0);
    }

    if (r >= row && r < row + size && c >= col && c < col + size){
        size /= 2;
        solved(row, col, size);
        solved(row, col + size, size);
        solved(row + size, col, size);
        solved(row + size, col + size, size);
    }
    else res += size * size;
}

int main(){
    FASTIO;

    cin >> N >> r >> c;
    solved(0, 0, pow(2, N));
    return 0;
}
