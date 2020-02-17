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

void dfs(vector<vector<ll>> &g, vector<ll> &vis, ll node,vector<ll> &GCD, vector<ll> &leafNode){

        vis[node] = 1;
        bool isChild = true;
    
        for(auto i: g[node]) {
            if(!vis[i]) {
                isChild = false;
                GCD[i] = __gcd(GCD[i], GCD[node]);
                dfs(g,vis,i,GCD,leafNode); 
            }
        }

        if(isChild) leafNode.emplace_back(node); 
}


int main(){
    
    FastIO

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<vector<ll>> g(n+1);
        vector<ll> m(n+1),GCD(n+1),vis(n+1,0);
        vector<ll> leafNode,ans;
        ll x, y;
        ll parent = 0;
        REP(i ,n-1) cin >> x >> y, g[x].emplace_back(y), g[y].emplace_back(x);
        REP(i, n) cin >> GCD[i];
        REP(i, n) cin >> m[i];

        dfs(g,vis,1,GCD,leafNode);

        sort(all(leafNode));

        for(auto i: leafNode){
            ll x = __gcd(GCD[i], m[i]);
            ll tmp = ( m[i]/x - 1)*x;
            cout << tmp << " ";
        }

        cout << endl;


        

    }

    
   

    return 0;
}
