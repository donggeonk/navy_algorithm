#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        list<char> L;
        list<char>::iterator p = L.begin();
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '<'){
                if (p != L.begin()) p --;
            }
            else if (s[i] == '>'){
                if (p != L.end()) p ++;
            }
            else if (s[i] == '-'){
                if (p != L.begin()) p = L.erase(--p);
            }
            else L.insert(p, s[i]);
        }
        for (auto it : L) cout << it;
        cout << '\n';
    }
    return 0;
}

/* 5397번 - 키로거 '2'
<, > : 이동
- : 삭제
알파벳 : 입력

List iterator에 대한 이해
*/
