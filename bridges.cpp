#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int maxN = 1e5+23;

vector<vector<int>> g;
int h[maxN], d[maxN];
bool used[maxN];

map<pair<int, int>, bool> foo;

void dfs(int v, int p) {
	used[v] = true;
	if (p == -1)
		h[v] = d[v] = 0;
	else
		h[v] = d[v] = h[p] + 1;
	for (int to : g[v]) {
		if (to != p) {
			if (used[to])
				d[v] = min(d[v], h[to]);
			else {
				dfs(to, v);
				d[v] = min(d[v], d[to]);
				if (h[v] < d[to])
					foo[{v + 1, to}] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	g.resize(n);
	vector<pair<int, pair<int, int>>> e;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
		e.push_back({i + 1, {a, b}});
		e.push_back({i + 1, {b, a}});
	}
	for (int i = 0; i < n; i++) {
		if (!used[i])
			dfs(i, -1);
	}
	vector<int> ans;
	int cnt = 0;
	for (auto x : e) {
		if (foo[{x.second.first, x.second.first}]) {
			cnt++;
			ans.push_back(x.first);
		}
	}
	cout << cnt << endl;
	for (int x : ans)
		cout << x << endl;

}
