#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll

using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


#define it(ITR,END) for (int ITR = 0; ITR < (END); ++ITR)
#define ite(ITR,START,END) for (int ITR = (START); ITR < (END); ++ITR)
#define rit(ITR,END) for (int ITR = (END-1); ITR >= 0; --ITR)
#define rite(ITR,START,END_INCLUSIVE) for (int ITR = (START); ITR >= (END_INCLUSIVE); --ITR)

#define each(ELEMENT,ITERABLE) for (auto &ELEMENT : ITERABLE)
#define pt(ITER) each(EL,ITER) cout << EL << " "; cout << '\n'
#define vin(VECTER,NUM) vi VECTER(NUM); each(LEE,VECTER) cin >> LEE

#define inp(NUMERO) int NUMERO; cin >> NUMERO
#define sip(SENTENC) string SENTENC; cin >> SENTENC
#define yn(CONDITION) cout << ((CONDITION) ? "YES\n" : "NO\n")
#define pr(THING) cout << THING << "\n"

#define pr2(THING_1,THING_2) cout << THING_1 << " " << THING_2 << "\n"
#define pr3(THING_1,THING_2,THING_3) cout << THING_1 << " "  << THING_2 << " "  << THING_3 << "\n"
#define pr4(THING_1,THING_2,THING_3,THING_4) cout << THING_1 << " "  << THING_2 << " "  << THING_3 << " "  << THING_4 << "\n"

#define len(ITERABLE) (int)(ITERABLE).size()
#define all(ITERABLE) (ITERABLE).begin(), (ITERABLE).end()
#define rall(ITERABLE) (ITERABLE).rbegin(), (ITERABLE).rend()
#define shot(ITERABLE) sort(all(ITERABLE))
#define tall(ITERABLE) sort(rall(ITERABLE))

#define bit_len(NUMERO) ((NUMERO) == 0 ? 0 : 64 - __builtin_clzll(NUMERO))

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
    inp(a);
    inp(b);
    inp(c);
    int n = abs(b-a);
    int ans = c+n;
    if(c > n) ans = c-n;
    if(a > 2*n or b > 2*n or c > 2*n) cout << "-1";
    else cout << ans;
}