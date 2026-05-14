#include <bits/stdc++.h>
using namespace std;

vector<int> g[200005];
bool visited[200005];
long long cnt;

void dfs(int u) {
    visited[u] = true;
    cnt++;
    for (int v : g[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt = 0;
            dfs(i);
            ans *= (1LL << (cnt - 1));
        }
    }

    cout << ans;
}