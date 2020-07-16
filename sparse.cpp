#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
const int mlog = 17;

int t[mlog][maxn];
int a[maxn];

inline int ask(int l, int r) {
	int k = __lg(r - l + 1);
	return min(t[k][l], t[k][r - (1 << k) + 1]);
	//return (t[k][l] < t[k][r - (1 << k) + 1] ? t[k][l] : t[k][r - (1 << k) + 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i]; 
	
	for (int i = 0; (1 << i) <= n; i++) {
		for (int j = 0; j + (1 << i) <= n; j++) {
			if (i != 0)
				t[i][j] = min(t[i - 1][j], t[i - 1][j + (1 << (i - 1))]);
			else
				t[i][j] = a[j];
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << ask(l, r) << "\n";
	}
	
}
