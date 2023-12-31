#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100;
int arr[MAX][MAX];

bool check(int row, int col, int size){
    int tmp = arr[row][col];
    for (int i = row; i < row + size; i++){
        for (int j = col; j < col + size; j++){
            if (arr[i][j] != tmp) return false;
        }
    }
    return true;
}

void solved(int row, int col, int size){
    if (check(row, col, size)) cout << arr[row][col];
    else {
        cout << "(";
        size /= 2;
        solved(row, col, size);
        solved(row, col + size, size);
        solved(row + size, col, size);
        solved(row + size, col + size, size);
        cout << ")";
    }
}

int main(){
    FASTIO;

    int N; cin >> N;
    for (int i = 0; i < N; i++){
        string s; cin >> s;
        for (int j = 0; j < N; j++){
            arr[i][j] = s[j] - '0';
        }
    }

    solved(0, 0, N);
    return 0;
}
