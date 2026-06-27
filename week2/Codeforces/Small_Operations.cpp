#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define int ll

using pii = pair<int,int>;
using vpii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;

#define it(ITR,TOTAL) for (int ITR = 0; ITR < (TOTAL); ++ITR)
#define ite(ITR,START,END) for (int ITR = (START); ITR < (END); ++ITR)
#define rit(ITR,TOTAL) for (int ITR = (TOTAL-1); ITR >= 0; --ITR)
#define rite(ITR,START,END_INCLUSIVE) for (int ITR = START; ITR >= END_INCLUSIVE; --ITR)
#define each(ELEMENT,ITERABLE) for (auto &ELEMENT : ITERABLE)

#define vin(VECTER,NUM) vi VECTER(NUM); each(LEE,VECTER) cin >> LEE
#define inp(NUMERO) int NUMERO; cin >> NUMERO
#define sip(SENTENC) string SENTENC; cin >> SENTENC

#define yn(CONDITION) cout << ((CONDITION) ? "YES\n" : "NO\n")
#define pr(THING) cout << (THING) << " "
#define nl cout << "\n"
#define pt(ITER) each(EL,ITER) cout << EL << " "; nl

#define len(ITERABLE) (int)(ITERABLE).size()
#define all(ITERABLE) (ITERABLE).begin(), (ITERABLE).end()
#define rall(ITERABLE) (ITERABLE).rbegin(), (ITERABLE).rend()
#define shot(ITERABLE) sort(all(ITERABLE))
#define tall(ITERABLE) sort(rall(ITERABLE))

#define bit_len(NUMERO) ((NUMERO) == 0 ? 0 : 64 - __builtin_clzll(NUMERO))
#define pb push_back
#define mp make_pair
#define F first
#define S second

int N=1e6;
vector<bool> is_prime(N+1, true);
void initSieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && (long long)i * i <= N) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

void solve(int tc);
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); nl;//comment when interactive
    int TOTAL=1;
    cin >> TOTAL; //comment when singular
    initSieve();
    ite(TESTCASE,1,TOTAL+1){
        solve(TESTCASE);
        nl;
    }
}

vi factors(int num){
    int s = sqrt(num);
    vi ans;
    for(int i=2;i<=s;i++){
        if(is_prime[i]){
            while(num%i == 0){
                num /= i;
                ans.pb(i);
            }
        }
    }
    if(num != 1) ans.pb(num);
    return ans;
}

int ReduceToOne(int num, int max_allowed){
    vi v = factors(num);
    multiset f(all(v));
    if(f.empty()) return 0;
    if(*f.rbegin() > max_allowed) return -1;

    int add_turns=0;
    int cur=1;
    while(!f.empty()){
        cur = *f.rbegin();
        auto last = prev(f.end());
        f.erase(last);
        while(true){
            int find = max_allowed/cur;
            auto it = f.upper_bound(find);
            if(it == f.begin()) break;
            cur *= *(--it);
            f.erase(it);
        }
        add_turns++;
    }
    return add_turns;
}


void solve(int tc){ //use tc for debugging
    inp(x); inp(y); inp(k);
    if(tc == 8075 and !(x == 17 and y == 3)){
        cout << tc << ":" << x << "-" << y << "-" << k << "\n";
    }
    int g = gcd(x,y);
    int down = x/g;
    int up = y/g;
    int ans = -1;

    int initial = ReduceToOne(down,k);
    if(initial != -1){
        int final = ReduceToOne(up,k);
        if(final != -1){
            ans = initial + final;
        }
    }
    pr(ans);
}