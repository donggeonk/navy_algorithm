#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
int arr[MAX], DP[MAX];

int main(){
	FASTIO;
	
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i < n; i++){
		DP[i] = arr[i];
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i]) DP[i] = max(DP[i], DP[j] + arr[i]);
		}
		res = max(res, DP[i]);
	}
	
	cout << res;
	return 0;
}
