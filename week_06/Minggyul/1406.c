#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;

    list<char> L;
    int M;
    string s;
    char c;
    cin >> s >> M;

    for (int i = 0; i < s.size(); i++){
        L.push_back(s[i]);
    }
    list<char>::iterator p = L.end(); // cursor 출력을 뒤 문자로 약속하면 된다.
    for (int i = 0; i < M; i++){
        cin >> c;
        if (c == 'L'){ // cursor 왼쪽
            if (p != L.begin()) p--;
        }
        else if (c == 'D'){ // cursor 오른쪽
            if (p != L.end()) p++;
        }
        else if (c == 'B'){ // cursor 앞 삭제
            if (p != L.begin()) p = L.erase(--p);
        }
        else { // cursor 왼쪽에 c 추가
            cin >> c;
            L.insert(p, c);
        }
    }
    
    for(auto it : L) cout << it;
    return 0;
}

/* '3'
List 구현하기가 어렵다
특히, 포인터를 구현해야 된다는 점, 양 끝을 주의해야하는 점

1. 원소의 삽입, 그 자리에 넣고 나머지 뒤로 땡기기
2. 원소의 삭제, 그 원소 없애고 뒤에서 자리 채움

*/
