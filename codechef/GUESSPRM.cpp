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

vector<ll> primes;

 void getPrimeFactors(ll r){
    primes.clear();
    ll num = 10000000000 - r;
    for(ll i=2; i*i<= num; i++){
        if(num % i == 0){
            primes.emplace_back(i);
            // cout << i << endl;
            while( num%i == 0) num /= i;
        }

    }

    if(num > 1) primes.emplace_back(num);

}



int main(){
    
    FastIO
    ll t; cin >> t;

    while(t--){
        ll r,x;
        cout << 1 << " " << 100000 << endl;
        cin >> r;
        // outputv(primes);
        getPrimeFactors(r);

        set<ll> s;
        for(int i=1; i<=100000; i++){
            s.clear();
            for(auto p: primes) {
                // cout << p << endl;
                s.insert((i*i)%p);
            }
            if( s.size() == primes.size()){
                x = i;
                break;
            }
        }

        cout << 1 << " " << x << endl;
        cin >> r;

        ll ans;
        
        for(auto i: primes){
            if((x*x)%i == r){
                ans = i;
                break;
            }
        }

        cout << 2 << " " << ans << endl;
        string ans2;
        cin >> ans2;

        if(ans2 != "Yes") return 0;

        

    }

    
   

    return 0;
}
