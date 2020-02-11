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

int main(){
    
    FastIO

    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    
    ll n, l, r; cin >> n >> l >> r;
    vector<int> arr, arr2;

    ll temp = pow(2,l-1);
    ll distinct = l-1;
    for(int i=0; i< n; i++){
        if(distinct > 0) arr.emplace_back(pow(2,distinct)), distinct--;
        else arr.emplace_back(1);
    }

    // outputv(arr);

    temp = pow(2, r-1);
    distinct = 0;
    for(int i=0; i< n; i++){
        if(distinct < r) arr2.emplace_back(pow(2,distinct)), distinct++;
        else arr2.emplace_back(temp);
    }

    // outputv(arr2);

    cout << accumulate(arr.begin(), arr.end(), 0) << " " << accumulate(arr2.begin(), arr2.end(), 0) << endl;
    

    return 0;
}