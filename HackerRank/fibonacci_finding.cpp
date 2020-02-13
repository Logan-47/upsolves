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

void mul(ll a[][2], ll b[][2] ){

    ll res[2][2];

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            res[i][j]  =0;
            for(int k=0; k<2; k++){
                res[i][j] = ((res[i][j]%mod) + (a[i][k]*b[k][j])%mod)%mod;
            } 
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a[i][j] = res[i][j];    
        }
    }

}

void power( ll t[][2], ll n){

    ll I[2][2];
    I[0][0] = 0;
    I[0][1] = I[1][0] = I[1][1] = 1;

    // binary exponentiation.
    while(n){
        if(n%2) mul(I, t), n--;
        else mul(t,t), n/=2; 
    }

    for(int i=0;i<2;i++) for(int j=0; j<2;j++) t[i][j] = I[i][j];
    
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
        
       ll a,b,n; cin >> a >> b >> n;
       ll arr[1][2] = {a,b}, ans[1][2];

       if( n < 2 ) cout << arr[0][n] << endl;
       else{

        // transition matrix
        ll t[2][2] = {0,1,1,1};
        
        power(t,n-1);

        // {f1,f2} * (transition_matrix)^n-1 = {fn, fn+1}

        for(int i=0; i<1; i++){
            for(int j=0;j<2; j++){
                ans[i][j] = 0;
                for(int k=0; k<2; k++){
                    ans[i][j] = ((ans[i][j]%mod) + (arr[i][k]*t[k][j])%mod)%mod;
                    }
                }
            }

        cout << ans[0][0] << "\n";

       }


    }

    return 0;
}
