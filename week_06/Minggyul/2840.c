#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int N, K, a, b = 0;
    vector<char> v;
    char c;
    cin >> N >> K;
    for (int i = 0; i < N; i++) v.push_back('?');
    
    for (int i = 0; i < K; i++){
        cin >> a >> c;
        a %= N;
        
        if (b - a >= 0) b -= a;
        else b = b - a + N;
        
        if (v[b] != '?' && v[b] != c) {
            cout << '!';
            return 0;
        }
        else v[b] = c;
    }
    
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (v[i] != '?' && v[i] == v[j]) {
                cout << '!';
                return 0;
            }
        }
    }
    
    for (int i = 0; i < N; i++) cout << v[(i + b) % N];
    return 0;
}

// 반시계 방향 이해가 힘들다.
