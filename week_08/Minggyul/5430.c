#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        string P, Q;
        int n;
        cin >> P >> n >> Q;
        deque<int> dq;
        
        // Parsing
        int cur = 0;
        for (int i = 0; i < Q.size(); i++){
            if (Q[i] == ',' || Q[i] == ']'){
                if (cur != 0)
                    dq.push_back(cur);
                cur = 0;
            } 
            else if (Q[i] == '[') continue;
            else {
                cur = cur * 10 + Q[i] -'0';
            }
        }
        
        // R, D operation
        bool flag = true; // front
        bool end = false;
        for (int i = 0; i < P.size(); i++){
            if (P[i] == 'R') flag = !flag;
            else {
                if (dq.empty()) {
                    cout << "error\n";
                    end = true;
                    break;
                }
                else if (flag) dq.pop_front();
                else dq.pop_back();
            }
        }
        
        // print
        if (!end){
            cout << '[';
            if (flag){
                while(!dq.empty()){
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty()) cout << ',';
                }
            }
            else {
                while(!dq.empty()){
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty()) cout << ',';
                }                
            }
            cout << ']' << '\n';
        }
    }
    return 0;
}
