#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;


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
#define shot(ITERABLE) sort(all(ITERABLE))
#define tall(ITERABLE) sort((ITERABLE).rbegin(), (ITERABLE).rend())

#define bit_len(NUMERO) (NUMERO == 0 ? 0 : 64 - __builtin_clzll(NUMERO))

#define pb push_back
#define F first
#define S second

void solve(int tc);
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); //comment when interactive
    int TOTAL=1;
    // cin >> TOTAL; //comment when singular
    cout << "\n";
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        cout << "\n";
    }
}

void solve(int tc){ //use tc for debugging
    inp(n); inp(m);
    vin(v,n);
    shot(v);
    unordered_map<string,int> fr;
    it(i,m){
        sip(f);
        if(fr.find(f) == fr.end()) fr[f] = 1;
        else fr[f]++;
    }
    vi frq;
    each(x,fr) frq.pb(x.S);
    tall(frq);
    int l = len(frq);
    int smol=0,big=0;
    it(i,l) smol += v[i]*frq[i];
    it(i,l) big += v[n-i-1]*frq[i];
    cout << smol << " " << big;
}