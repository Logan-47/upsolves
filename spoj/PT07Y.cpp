#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using ll = long long;
#define whatis(x) cout << "> "<<#x << " ==> " << x << endl;
#define br cout<< endl;
#define vi vector<int>
#define vii vector<ll>
#define REP(i, k) for(int i=1; i<=k;i++)
#define all(v) begin(v),end(v)
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define inputv(a) forall(i,0,a.size()) cin>>a[i]
#define outputv(a) for(auto i:a) cout<<i<<" ";br;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define print(x) cout << x << " ";
#define outputvp(a) for(auto i:a) {for(auto j: i) {cout<<j.first<<" " << j.second << ", ";}br;}
using namespace std;
template <typename T, typename V>
auto split(T st, V delim) {
    char s[sizeof(st)];
    strcpy(s, st.c_str()); 
        char * m; 
        m = strtok(s, delim);
        vector<int> vc;
        while(m != NULL){
            vc.emplace_back(atoi(m));
            m = strtok(NULL, delim);
        }
        return vc;
    }
ll mod = 1e9+7;



void dfs(ll n,vector<vector<ll>> &g, vector<ll> &vis){
	vis[n] = 1;
	for(auto i: g[n]){
		if(vis[i] == 0) dfs(i,g,vis);
	}
}

int main(){
	
	FastIO

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

   ll n, m; cin >> n >> m;
   vector<vector<ll>> g(n+1);
   vector<ll> vis(n+1,0);
   ll u, v;
   REP(i, m) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
   ll cnt = 0;
   REP(i, n) if(vis[i] == 0) dfs(i,g,vis), cnt+=1;

   if(cnt == 1 && m == n-1) cout << "YES\n";
   else cout << "NO\n";

    return 0;
}