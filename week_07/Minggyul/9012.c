#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        string s;
        stack<char> st;
        cin >> s;
        bool flag = true;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') st.push('(');
            else {
                if (st.empty()) {
                    flag =false;
                    break;
                }
                else st.pop();
            }
        }
        if (st.empty() && flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
