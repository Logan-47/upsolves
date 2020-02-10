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
#define N 51
int I[N][N];

void mul(int A[][N], int B[][N], int dim ){

	int res[dim+1][dim+1];

	REP(i, dim){
		REP(j, dim){
			res[i][j] = 0;
			REP(k, dim) res[i][j] = ((res[i][j]%mod) + ((A[i][k]%mod) * (B[k][j]%mod))%mod)%mod;
		}
	}

	REP(i, dim) REP(j, dim) A[i][j] = res[i][j];

}

void power(int A[][N], int dim, int n){

	// make identity matrix.
	REP(i, dim) REP(j ,dim) ( i == j) ? I[i][j] = 1 : I[i][j] = 0;

	// REP(i, n) mul(I , A, dim); // O(m^3 * n)

	// O(m^3*logn)
	while(n){
		if(n%2) mul(I, A, dim), n--;
		else mul(A, A, dim), n/= 2;
	}

	REP(i, dim) REP(j, dim) A[i][j] = I[i][j];

}

void printMat( int A[][N], int dim){
	REP(i, dim){ 
		REP(j , dim){
			cout << A[i][j] << " ";
		}
		br;
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
    	int dim, n; cin >> dim >> n;
    	int a[N][N];
    	REP(i, dim) REP(j, dim) cin >> a[i][j];
    	power(a, dim ,n);
    	printMat(a, dim);


    }

    return 0;
}