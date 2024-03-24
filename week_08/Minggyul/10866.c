#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int N; cin >> N;
    deque<int> dq;
    while(N--){
        string inp; cin >> inp;
        if (inp == "push_front"){
            int num; cin >> num;
            dq.push_front(num);
        }
        else if (inp == "push_back"){
            int num; cin >> num;
            dq.push_back(num);
        }
        else if (inp == "pop_front"){
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (inp == "pop_back"){
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (inp == "size"){
            cout << dq.size() << '\n';
        }
        else if (inp == "empty"){
            if (dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (inp == "front"){
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
    return 0;
}
