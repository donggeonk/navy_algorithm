#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int arr[11];

int main(){
	FASTIO;

    int V, res = 0;
    for (int i = 0; i < 11; i++){
        cin >> arr[i] >> V;
        res += V * 20;
    }
    sort(arr, arr + 11);

    int sum = 0;
    for (int i = 0; i < 11; i++){
        sum += arr[i];
        res += sum;
    }

    cout << res;
	return 0;
}
