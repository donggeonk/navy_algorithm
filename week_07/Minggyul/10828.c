#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < n; i++){
        string inp;
        cin >> inp;
        if (inp == "push") {
            int num; cin >> num;
            s.push(num);
        }
        else if (inp == "pop"){
            if(s.empty()) cout << -1 << '\n';
            else {
            cout << s.top() << '\n';
            s.pop();
            }
        }
        else if (inp == "size"){
            cout << s.size() << '\n';
        }
        else if (inp == "empty"){
            if(s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else{
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }
    return 0;
}
