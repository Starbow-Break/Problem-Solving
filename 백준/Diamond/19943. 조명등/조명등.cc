#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

const ll INF = 1'000'000'000'000'000'000;

//직선
struct line {
    ll a; ll b;
    ll get(ll x) { return a*x+b; }
};

struct node {
    int l, r;
    line li;
    ll get(ll x) { return li.get(x); }
};

struct sculp {
    int left, right;
};

vector<node> lichaoTree; //Li Chao Tree
vector<sculp> sculps, compSculps;
ll dp[1'000'001] = {0, };
ll l[1'000'001], r[1'000'001];

//트리 초기화
void init() {
    lichaoTree.clear();
    lichaoTree.push_back({-1, -1, {0, INF}});
}

//트리에 직선 추가
void add(int l, int r, int idx, const line &li) {
    //low, high 세팅
    line low = lichaoTree[idx].li, high = li;
    if(low.get(l) > high.get(l)) swap(low, high);
    
    //두 직선이 (l, r)에서 만나지 않을 때
    if(low.get(r) <= high.get(r)) { lichaoTree[idx].li = low; return; }
    
    int mid = l+r>>1;
    if(low.get(mid) <= high.get(mid)) { //직선이 m의 오른쪽에서 만날 때
        lichaoTree[idx].li = low;
        if(lichaoTree[idx].r < 0) {
            lichaoTree[idx].r = lichaoTree.size();
            lichaoTree.push_back({-1, -1, {0, INF}});
        }
        add(mid+1, r, lichaoTree[idx].r, high);
    }
    else { //왼쪽에서 만날 때
        lichaoTree[idx].li = high;
        if(lichaoTree[idx].l < 0) {
            lichaoTree[idx].l = lichaoTree.size();
            lichaoTree.push_back({-1, -1, {0, INF}});
        }
        add(l, mid, lichaoTree[idx].l, low);
    }
}

//최솟값 구하기
ll getMin(int l, int r, int idx, ll x) {
    if(idx == -1) return INF;
    
    int mid = l+r>>1;
    if(x <= mid) return min(lichaoTree[idx].get(x), getMin(l, mid, lichaoTree[idx].l, x));
    else return min(lichaoTree[idx].get(x), getMin(mid+1, r, lichaoTree[idx].r, x));
}

void compress() {
    stack<sculp> s;
    for(auto &sc: sculps) {
        if(!s.empty() && s.top().right >= sc.right) continue;
        while(!s.empty() && s.top().left >= sc.left) s.pop();
        s.push(sc);
    }
    
    while(!s.empty()) { compSculps.push_back(s.top()); s.pop(); }
    reverse(compSculps.begin(), compSculps.end());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        init();
        sculps.clear(); compSculps.clear();
        
        int N; cin >> N;
        while(N--) {
            int x, h; cin >> x >> h;
            sculps.push_back({x-h, x+h});
        }
        
        compress();
        
        int sz = compSculps.size();
        for(int i = 1; i <= sz; i++) {
            l[i] = compSculps[i-1].left; r[i] = compSculps[i-1].right; 
        }
        
        for(int i = 1; i <= sz; i++) {
            add(1, 200'000'000, 0, {-2*l[i], l[i]*l[i]+dp[i-1]});
            dp[i] = getMin(1, 200'000'000, 0, r[i])+r[i]*r[i];
        }
        
        cout << dp[sz]/4;
        switch(dp[sz]%4) {
            case 0: cout << ".00"; break;
            case 1: cout << ".25"; break;
            case 2: cout << ".50"; break;
            case 3: cout << ".75"; break;
        }
        cout << '\n';
    }

    return 0;
}