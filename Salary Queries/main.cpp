#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX_N = 2e5 + 5;
const int MAX_L = 20; // ~ Log N
const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 7;
const double EPS = 1e-9;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define LSOne(S) (S & (-S))
#define isBitSet(S, i) ((S >> i) & 1)

// use PBDS

void solve() {
    int n, q; cin >> n >> q;
    int arr[n];
    ordered_set os;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        os.insert(arr[i]);
    }
    while (q--) {
        char c; cin >> c;
        if (c == '!') {
            int k, x; cin >> k >> x; k--;
            os.erase(os.find_by_order(os.order_of_key(arr[k])));
            os.insert(x);
            arr[k] = x;
        }
        else {
            int a, b; cin >> a >> b;
            cout << os.order_of_key(b + 1) - os.order_of_key(a) << "\n";
        }
    }
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
