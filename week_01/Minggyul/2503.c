#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> m;

void solved(int num, int st, int ba){
    int a = num % 10;
    int b = (num / 10) % 10;
    int c = num / 100;
    
    for (int i = 0; i < m.size(); i++){ // 0, 1, 2, 3 2삭제 -> m.size() = 3변경 2로 접근
        int aa = m[i] % 10;
        int bb = (m[i] / 10) % 10;
        int cc = m[i] / 100;
        
        int st2 = 0, ba2 = 0;
        if (aa == a) st2++;
        if (bb == b) st2++;
        if (cc == c) st2++;
        
        if (aa == b || aa == c) ba2++;
        if (bb == a || bb == c) ba2++;
        if (cc == a || cc == b) ba2++;
        
        if (st != st2 || ba != ba2) {
            m.erase(m.begin() + i);
            i --;
        }
    }
}

int main(){
    FASTIO;
    
    for (int i = 123; i <= 987; i++){
        int a = i % 10;
        int b = (i / 10) % 10;
        int c = i / 100;
        if (a != b && b != c && a != c && a != 0 && b != 0) m.push_back(i);
    }
    
    int t; cin >> t;
    while(t--){
        int num, st, ba;
        cin >> num >> st >> ba;
        
        solved(num, st, ba);
    }
    
    cout << m.size();
    return 0;
}
