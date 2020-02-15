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


int main(){
    
    FastIO

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

  ll n; cin >> n;
  ll a[n+1];
  ll mini = INT_MAX;
  vector<ll> odd, even;
  ll odd_count = 0, even_count = 0;
  REP(i, n){
        cin >> a[i];
        if(a[i]%2) odd.emplace_back(a[i]), odd_count++, mini = min(mini, a[i]);
        else even.emplace_back(a[i]), even_count++;
    }   

    ll sum_odd = accumulate(all(odd), 0);
    ll sum_ev = accumulate(all(even), 0);

    if(odd_count == 0) cout << 0 << endl;
    else if(odd_count%2) cout << sum_odd+sum_ev << endl;
    else cout << sum_odd + sum_ev - mini << endl;


    return 0;
}
