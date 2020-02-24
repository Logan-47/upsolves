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

bool isPrime(int n){
	for(int i=2; i*i<=n;i++){
		if(n%i == 0) return false;
	}
	return true;
}


bool isValid(int a, int b){
	int cnt = 0;
	while(a > 0){
		if(a%10 != b%10) cnt+=1;
		a /= 10; b /= 10;
	}	

	if(cnt == 1) return true;
	else return false;
}


void buildGraph(vector<vector<int>> &g){
	vector<int> primes;
	for(int i=1000; i<= 9999; i++){
		if(isPrime(i)) primes.emplace_back(i);
	}

	for(int i=0 ;i<primes.size();i++){
		for(int j=i+1; j< primes.size(); j++){
			int a = primes[i];
			int b = primes[j];

			if(isValid(a,b)) g[a].emplace_back(b), g[b].emplace_back(a);
		}
	}
}

void bfs(int n, vector<vector<int>> &g, vector<int> &vis, vector<int> &dist){
	queue<int> q;
	q.push(n);
	vis[n] = 1;
	dist[n] = 0;

	while(!q.empty()){
		int cur = q.front();
		q.pop();

		for(auto i: g[cur]){
			if(vis[i] == 0){
				vis[i] = 1;
				q.push(i);
				dist[i] = dist[cur]+1;
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
    ll t; cin >> t;
    while(t--){
    	ll a, b; cin >> a >> b;
    	vector<vector<int>> g(10001);
    	vector<int> vis(10001, 0), dist(10001,-1);
    	buildGraph(g);
    	bfs(a,g,vis,dist);

    	if(dist[b] == -1) cout << "Impossible\n";
    	else cout << dist[b] << endl;
    }





    return 0;
}