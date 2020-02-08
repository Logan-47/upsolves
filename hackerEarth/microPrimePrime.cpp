#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using ll = long long;
#define whatis(x) cout << "> "<<#x << " ==> " << x << endl;
#define br cout<< endl;
#define vi vector<int>
#define vii vector<ll>
#define all(v) begin(v),end(v)
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define inputv(a) forall(i,0,a.size()) cin>>a[i]
#define outputv(a) for(auto i:a) cout<<i<<" ";br;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define print(x) cout << x <<'\n';
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
bool arr[1000001];
ll primePrime[1000001] = {0};


void seive(){
    ll maxN = 1000000;
    arr[0] = arr[1] = true;
    for(int i=2; i*i<=maxN; i++){
        if(!arr[i]){
            for(int k = i*i; k <= maxN; k+=i)
                arr[k] = true;
        }
    }

    ll cnt = 0;
    for(int i=0; i<=maxN; i++){
        if(!arr[i]){
            cnt+=1;
        }
        if(!arr[cnt]){
            primePrime[i] = 1;      
        }
        
    }

    for(int i=1; i<=maxN; i++)
        primePrime[i]+=primePrime[i-1];

}

int main(){
    
    FastIO

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    seive();
    ll t; cin >> t;
    while(t--){
        ll cnt = 0;
        ll l,r; cin >> l >> r;
        print(primePrime[r] - primePrime[l-1]);
    }
    

    return 0;
}