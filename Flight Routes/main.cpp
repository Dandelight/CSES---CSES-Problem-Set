#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 1e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e15 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

int n, m, k;
vii adj[MAX_N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vi cnt(n + 1, 0), ans;
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, 1});
    while (!pq.empty() && cnt[n] < k) {
        auto [d, u] = pq.top(); pq.pop();
        if (u == n) ans.push_back(d);
        cnt[u]++;
        if (cnt[u] <= k) {
            for (auto [v, w] : adj[u]) {
                pq.push({d + w, v});
            }
        }
    } 
    for (ll x : ans) cout << x << " ";
    cout << "\n";   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t  << ": ";
        solve();
    }
}
