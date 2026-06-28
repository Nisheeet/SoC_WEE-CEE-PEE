#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vii = vector<vector<int>>;

#define int ll

#define it(ITR,END) for (int ITR = (0); ITR < (END); ++ITR)
#define ite(ITR,START,END) for (int ITR = (START); ITR < (END); ++ITR)
#define rite(ITR,START,END_INCLUSIVE) for (int ITR = (START); ITR >= (END_INCLUSIVE); --ITR)

#define each(ELEMENT,ITERABLE) for (auto &ELEMENT : ITERABLE)
#define pt(ITER) each(EL,ITER) cout << EL << " "; cout << '\n'
#define vin(VECTER,NUM) vi VECTER(NUM); each(LEE,VECTER) cin >> LEE

#define yn(condition) cout << ((condition) ? "YES\n" : "NO\n")
#define inp(NUMERO) int NUMERO; cin >> NUMERO
#define sip(SENTENC) string SENTENC; cin >> SENTENC

#define len(ITERABLE) (int)(ITERABLE).size()
#define all(ITERABLE) (ITERABLE).begin(), (ITERABLE).end()
#define rall(ITERABLE) (ITERABLE).rbegin(), (ITERABLE).rend()
#define shot(ITERABLE) sort(all(ITERABLE))
#define tall(ITERABLE) sort(rall(ITERABLE))

#define bit_len(NUMERO) (NUMERO == 0 ? 0 : 64 - __builtin_clzll(NUMERO))

#define pb push_back
#define F first
#define S second

void solve(int tc);
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); //comment when interactive
    int TOTAL=1;
    cin >> TOTAL; //comment when singular
    cout << "\n";
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        cout << "\n";
    }
}


void solve(int tc){ //use tc for debugging
    inp(n);
    vin(v,n);
    vi difs(n-1);
    it(i,n-1) difs[i] = v[i+1] - v[i];
    shot(difs);
    vi uniq;
    int cur = 1e9+1;
    each(d,difs){
        if(d != cur){
            cur = d;
            uniq.pb(d);
        }
    }

    if(len(uniq) > 2){
        cout << -1;
        return;
    }
    if(len(uniq) != 2){
        cout << 0;
        return;
    }
    shot(uniq);

    if(!((uniq[1] > 0 and uniq[0] < 0))){
        if(uniq[1] == 0 and uniq[0] == 0) cout << 0;
        else cout << -1;
        return;
    }
    
    int m = uniq[1]-uniq[0];
    each(val,v){
        if(val >= m){
            cout << -1;
            return;
        }
    }
    int c = uniq[1];
    cout << m << " " << c;
}