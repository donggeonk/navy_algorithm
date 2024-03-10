#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;

    while(true){
        string s;
        getline(cin, s);
        if (s == "#") break;

        // 공백 기준 자르기
        stack<string> st;
        bool flag = false;
        for (int i = 0; i < s.size(); i++){
            int start = i + 1;
            if (s[i] == '<'){
                while(s[i] != '>') i++;
                string tmp = s.substr(start, i - start);
                if(tmp.back() == '/') continue;
                if(tmp.find(" ") != -1) tmp = tmp.substr(0, tmp.find(" "));
                
                if(tmp[0] == '/') {// 닫는 태그
                    tmp = tmp.substr(1);
                    if(!st.empty() && st.top() == tmp){
                        st.pop();
                    }
                    else if(st.empty()){
                        cout << "illegal\n";
                        flag = true;
                        break;
                    }
                }
                else st.push(tmp);
            }
        }
        
        if (flag) continue;
        if(!st.empty()) cout << "illegal\n";
        else cout << "legal\n";
    }
    return 0;
}
/* 5076 Web Pages
illegal
1. 닫는 태그가 있을 때 스택이 비어있다 
2. 스택 탑과 닫는 태그와 다르다
3. 스택이 비어있지 않다
*/
