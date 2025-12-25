#include<iostream>
using namespace std;
int map[1005][1005];
int MAX = 1e9;
long long dis[1005];
bool vis[1005];
void creatMap(int n, int m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				map[i][j] = 0;
			}
			else {
				map[i][j] = MAX;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		int dist;
		cin >> a >> b >> dist;
		map[a][b] = map[b][a] = dist;
	}
	return;
}
void dijkstra(int n, int t) {
	for (int i = 1; i <= n; i++) {
		dis[i] = MAX;
		vis[i] = false;
	}
	dis[t] = 0;
	for (int step = 1; step <= n; step++) {
		int u = -1;
		long long min = MAX;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && dis[i] < min) {
				min = dis[i];
				u = i;
			}
		}
		if (u == -1) {
			break;
		}
		vis[u] = true;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && map[u][j] < MAX) {
				long long nd = dis[u] + map[u][j];
				if (nd < dis[j]) {
					dis[j] = nd;
				}
			}
		}
	}
}
void count(long long* dp, long long* order,int n,int t) {
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		order[i] = i;
	}
	dp[t] = 1;
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = i + 1; j <= n; j++) {
			if (dis[order[j]] < dis[order[pos]]) {
				pos = j;
			}
		}
		int temp = order[i];
		order[i] = order[pos];
		order[pos] = temp;
	}
	for (int k = 1; k <= n; k++) {
		int u = order[k];
		if (dis[u] == MAX)break;
		for (int v = 1; v <= n; v++) {
			if (map[u][v] < MAX) {
				if (dis[v] > dis[u]) {
					dp[v] += dp[u];
				}
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	creatMap(n, m);
	int s, t;
	cin >> s >> t;
	long long dp[1005];
	long long order[1005];
	dijkstra(n, t);
	count(dp, order, n, t);
	cout << (dp[s] == 0 ? -1 : dp[s]);
	return 0;

}

