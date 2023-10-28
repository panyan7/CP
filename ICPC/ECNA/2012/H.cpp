#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Edmonds-Karp with SPFA for min cost max flow
struct FlowEdge {
    int u, v;
    long long cap, cost, flow = 0;
    FlowEdge(int u, int v, long long cap, long long cost) : u(u), v(v), cap(cap), cost(cost) {}
};
struct MinCostFlow {
    vector<vector<int>> adj;
    vector<FlowEdge> edges;
    vector<pair<long long, long long>> ans;
    const long long INF = 1e18;
    int n, m = 0;
    int s, t;
    MinCostFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
    }
    void add_edge(int u, int v, long long cap_, long long cost_) {
        edges.emplace_back(u, v, cap_, cost_);
        edges.emplace_back(v, u, 0, -cost_);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
    }
    void shortest_paths(int v0, vector<long long>& d, vector<int>& p) {
        d.assign(n, INF);
        d[v0] = 0;
        vector<bool> inq(n, false);
        queue<int> q;
        q.push(v0);
        p.assign(n, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for (int id : adj[u]) {
                int v = edges[id].v;
                if (edges[id].cap > 0 && d[v] > d[u] + edges[id].cost) {
                    d[v] = d[u] + edges[id].cost;
                    p[v] = id;
                    if (!inq[v]) {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    long long flow(long long k = -1) {
        if (k == -1) k = INF;
        long long flow = 0;
        long long cost = 0;
        vector<long long> d;
        vector<int> p;
        while (flow < k) {
            shortest_paths(s, d, p);
            if (d[t] == INF)
                break;
            long long f = k - flow;
            int cur = t;
            while (cur != s) {
                f = min(f, edges[p[cur]].cap);
                cur = edges[p[cur]].u;
            }
            flow += f;
            cost += f * d[t];
            cur = t;
            while (cur != s) {
                edges[p[cur]].flow += f;
                edges[p[cur]^1].flow -= f;
                edges[p[cur]].cap -= f;
                edges[p[cur]^1].cap += f;
                cur = edges[p[cur]].u;
            }
            ans.push_back({flow, cost});
        }
        if (k < INF && flow < k)
            return -1;
        else
            return cost;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cc = 0;
    while (true) {
        cc++;
        int n; cin >> n;
        if (n == 0)
            break;
        vector<vector<int>> f(n, vector<int>(n, 0));
        vector<vector<int>> u(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> f[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> u[i][j];
        int s = 2*n, t = 2*n+1;
        MinCostFlow G1(2*n+2, s, t);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G1.add_edge(i, j+n, 1, f[i][j]);
        for (int i = 0; i < n; i++)
            G1.add_edge(s, i, 1, 0);
        for (int i = 0; i < n; i++)
            G1.add_edge(i+n, t, 1, 0);
        ll ftime = 0, utime = 0;
        ftime = G1.flow(n);
        vector<int> worker_ft(n, 0);
        vector<int> assign1(n, 0);
        vector<int> assign2(n, 0);
        vector<int> sofa_ft(n, 0);
        for (auto& e : G1.edges) {
            if (e.flow > 0 && e.u < n && e.v >= n && e.v < 2*n) {
                assign1[e.u] = e.v-n;
                worker_ft[e.u] = e.cost;
                sofa_ft[e.v-n] = e.cost;
            }
        }
        MinCostFlow G2(2*n+2, s, t);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G2.add_edge(i, j+n, 1, max(worker_ft[i], sofa_ft[j]) + u[i][j]);
        for (int i = 0; i < n; i++)
            G2.add_edge(s, i, 1, 0);
        for (int i = 0; i < n; i++)
            G2.add_edge(i+n, t, 1, 0);
        ll total_time = G2.flow(n);
        vector<int> worker_total_time(n, 0);
        for (auto& e : G2.edges) {
            if (e.flow > 0 && e.u < n && e.v >= n && e.v < 2*n) {
                assign2[e.u] = e.v-n;
                utime += u[e.u][e.v-n];
                worker_total_time[e.u] = e.cost;
            }
        }
        cout << "Case " << cc << ":\n";
        for (int i = 0; i < n; i++) {
            cout << "Worker " << i+1 << ": ";
            cout << assign1[i]+1 << " " << assign2[i]+1 << " " << worker_total_time[i] << "\n";
        }
        cout << "Total idle time: " << total_time-ftime-utime << "\n";
    }
}
