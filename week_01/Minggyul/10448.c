#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> T;

int main(){
    FASTIO;
    
    for (int i = 1; ; i++){
        int j = (i * (i + 1)) / 2;
        if (j > 1000) break;
        T.push_back(j);
    }
    
    int test; cin >> test;
    int size = T.size();
    while(test--){
        int K; cin >> K;
        bool flag = false;
        for (int i = 0; i < size; i++){
            if (T[i] > K) break;
            for (int j = i; j < size; j++){
                if (T[i] + T[j] > K) break;
                for (int k = j; k < size; k++){
                    if (T[i] + T[j] + T[k] == K) {
                        flag = true;
                        break;
                    }
                    if (T[i] + T[j] + T[k] > K) break;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    
    return 0;
}
