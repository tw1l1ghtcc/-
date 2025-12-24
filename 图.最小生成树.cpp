#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int x[5001], y[5001];
bool vis[5001];
double dis[5001];
const double MAX = 1e300;
double primMAST(int n) {
	for (int i = 0; i < n; i++) {
		int x0, y0;
		cin >> x0 >> y0;
		x[i] = x0;
		y[i] = y0;
		vis[i] = false;
		dis[i] = MAX;
	}
	vis[0] = true;
	dis[0] = 0;
	double ans = 0.0;
	for (int i = 1; i < n; i++) {
		double dx = x[0] - x[i];
		double dy = y[0] - y[i];
		dis[i] = dx * dx + dy * dy;
	}
	for (int step = 1; step < n; step++) {
		int u = -1;
		double min = MAX;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && dis[i] < min) {
				min = dis[i];
				u = i;
			}
		}
		vis[u] = true;
		ans += sqrt(min);
		for (int j = 0; j < n; j++) {
			if (!vis[j]) {
				double dx = x[u] - x[j];
				double dy = y[u] - y[j];
				double d2 = dx * dx + dy * dy;
				if (d2 < dis[j]) {
					dis[j] = d2;
				}
			}
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	double ans = primMAST(n);
	cout <<fixed<<setprecision(2)<<ans;
	return 0;
}