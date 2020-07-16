#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> getZ(string s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		z[i] = max(0, min(r - i, z[i - l]));
		while (z[i] + i < n && s[z[i]] == s[z[i] + i])
			z[i]++;
		if (i + z[i] > r) {
			r = i + z[i];
			l = i;
		}
	}
	return z;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	vector<int> z = getZ(s);
	for (int i : z) cout << i << ' ';
	
}
