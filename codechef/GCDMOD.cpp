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

ll power(ll a, ll n, ll md){
    ll res = 1;
    while(n){
        if(n%2) res = ((res%md) *(a%md))%md, n--;
        else a = ((a%md)*(a%md))%md, n/=2;
    }

    return res;
}

ll GCD(ll a, ll b, ll n){
    if( a==b ) return (power(a,n,mod) + power(b,n,mod))%mod;

    ll candidate = 1;
    ll num = a - b;
    for(ll i=1; i*i <= num; i++){
        if( num % i == 0){
            ll tmp = (power(a,n,i) + power(b,n,i))%i;
            if(tmp == 0) candidate = max(candidate, i);
            tmp = (power(a,n,num/i) + power(b,n,num/i))%(num/i);
            if(tmp == 0) candidate = max(candidate, num/i);
        }
    }

    return candidate%mod;
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
    ll a, b , n; cin >> a >> b >> n;
    cout << GCD(a,b,n) << endl;
   }

    return 0;
}
