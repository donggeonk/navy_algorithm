#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n; cin >> n;
    queue<int> q;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s == "push") {
            int num; cin >> num;
            q.push(num);
        }
        else if(s == "front"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if(s == "back"){
            if(q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
        else if (s == "size"){
            cout << q.size() << '\n';
        }
        else if (s == "empty"){
            if(q.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else {
            if(q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
    }
    return 0;
}
