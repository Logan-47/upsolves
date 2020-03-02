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

ll find(ll n, vector<ll> &parent){
	vector<ll> temp;
	while(parent[n] > 0) temp.emplace_back(n), n = parent[n];
	for(auto i: temp) parent[i] = n;
	return n;
}

void Union(ll a, ll b, vector<ll> &parent){
	parent[a] += parent[b];
	parent[b] = a;
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
    ll u, v;
    vector<ll> parent(n+1,-1);
    REP(i,m){
     cin >> u >> v;
     u = find(u,parent);
     v = find(v,parent);

     if(u != v) Union(u,v,parent);
 	}
 	ll ans = 1;
 	REP(i,n){
 		if(parent[i] < 0) ans = ((ans%mod) * (-parent[i])%mod)%mod;
 	} 

 	cout << ans%mod << endl;


    return 0;
}