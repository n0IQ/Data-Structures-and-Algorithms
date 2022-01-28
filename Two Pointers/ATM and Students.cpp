//Problem: https://codeforces.com/contest/1611/problem/F

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

void solve()
{
	int n;
	ll s;
	cin >> n >> s;

	ll a[n];
	rep(i, 0, n) cin >> a[i];

	int start = -1, end = -1, i = 0, j = 0, mx = 0, l = 0;
	ll sum = s;

	while (j < n) {
		if (sum + a[j] < 0) {
			if (mx < l) {
				mx = l;
				start = i, end = j;
			}

			sum += a[j];
			l++;
			while (i <= j && sum < 0) {
				sum -= a[i];
				i++, l--;
			}
		}
		else {
			l++;
			sum += a[j];
		}

		j++;
	}

	if (mx < l) {
		mx = l;
		start = i, end = j;
	}

	if (start == -1) cout << -1 << '\n';
	else cout << start + 1 << ' ' << end << '\n';
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