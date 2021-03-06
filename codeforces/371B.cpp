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

    ll n,m; cin >> n >> m;
    if(n == m) cout << 0 << endl;
    else{
        ll cnt2 = 0, cnt3 = 0, cnt5 = 0, c1 = 0, c2 = 0, c3 = 0;

        while(n){
            if(n%2 == 0) cnt2+=1, n/=2;
            else if(n%3 == 0) cnt3+=1, n/=3;
            else if(n%5 == 0) cnt5+=1, n/=5;
            else break; 
        }

        while(m){
            if(m%2 == 0) c1+=1, m/=2;
            else if(m%3 == 0) c2+=1, m/=3;
            else if(m%5 == 0) c3+=1, m/=5;
            else break;
        }

        if( n == m) cout << (abs(cnt2 - c1) + abs(cnt3 - c2) + abs(cnt5-c3)) << endl;
        else cout << -1 << endl;
    }

    return 0;
}
