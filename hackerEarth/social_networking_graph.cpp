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

void bfs(int n, vector<vector<int>> &g, vector<int> &vis, vector<int> &distance, int &cnt, int dis){
		
		vis[n] = 1;
		queue<int> q;
		q.push(n);
		distance[n] = 0;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(auto i: g[cur]){
				if(vis[i] == 0){
					q.push(i);
					vis[i] = 1;
					distance[i] = distance[cur]+1;
					if(distance[i] == dis) cnt+=1;

				}

			}
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

    ll n, e; cin >> n >> e;
    vector<vector<int>> g(n+1);
    int u, v;
    REP(i ,e) cin >> u >> v, g[u].emplace_back(v), g[v].emplace_back(u);
    int m; cin >> m;
    while(m--){
	    vector<int> vis(n+1),distance(n+1,0);

    	int src,dis; cin >> src >> dis;
    	int cnt = 0;
    	bfs(src,g,vis,distance,cnt,dis);
    	cout << cnt << endl;
    	
    }


    return 0;
}