//Problem: https://codeforces.com/contest/1611/problem/E1

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

const int MAXN = (int)2e5 + 10;
vector<vector<int>> adj;
int n, k;
int dist[MAXN];
bool frnds[MAXN], ans;

void dfs(int u, int p = -1, int d = 0)
{
	bool ok = 1;
	for (auto v : adj[u]) {
		if (v != p) {
			ok = 0;
			dfs(v, u, d + 1);
		}
	}

	if (ok && d < dist[u]) ans = 1;
}

void bfs()
{
	queue<int> q;
	vector<bool> visited(n, 0);
	rep(i, 0, n) {
		if (frnds[i]) q.push(i), visited[i] = 1;
		else dist[i] = (int)1e9;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto v : adj[u]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = 1;
				dist[v] = dist[u] + 1;
			}
		}
	}
}

void solve()
{
	cin >> n >> k;

	adj = vector<vector<int>> (n);
	mem0(frnds), mem0(dist);
	ans = 0;

	rep(i, 0, k) {
		int x; cin >> x;
		--x;
		frnds[x] = 1;
	}

	rep(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	bfs();
	dfs(0);

	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	cin >> t;
	while (t--) solve();

	return 0;
}