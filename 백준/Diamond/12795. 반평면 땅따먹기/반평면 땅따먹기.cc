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

const ll INF = 4'000'000'000'000'000'000;
const ll MAX = 1'000'000'000'000;

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

//Li Chao Tree
vector<node> lichaoTree;

//트리 초기화
void init() {
    lichaoTree.clear();
    lichaoTree.push_back({-1, -1, {0, -INF}});
}

//트리에 직선 추가
void add(ll l, ll r, int idx, const line &li) {
    //low, high 세팅
    line low = lichaoTree[idx].li, high = li;
    if(low.get(l) > high.get(l)) swap(low, high);
    
    //두 직선이 (l, r)에서 만나지 않을 때
    if(low.get(r) <= high.get(r)) { lichaoTree[idx].li = high; return; }
    
    ll mid = (l+r)/2;
    if(low.get(mid) <= high.get(mid)) { //직선이 m의 오른쪽에서 만날 때
        lichaoTree[idx].li = high;
        if(lichaoTree[idx].r < 0) {
            lichaoTree[idx].r = lichaoTree.size();
            lichaoTree.push_back({-1, -1, {0, -INF}});
        }
        add(mid+1, r, lichaoTree[idx].r, low);
    }
    else { //왼쪽에서 만날 때
        lichaoTree[idx].li = low;
        if(lichaoTree[idx].l < 0) {
            lichaoTree[idx].l = lichaoTree.size();
            lichaoTree.push_back({-1, -1, {0, -INF}});
        }
        add(l, mid, lichaoTree[idx].l, high);
    }
}

//최댓값 구하기
ll getMax(ll l, ll r, int idx, ll x) {
    if(idx == -1) return -INF;
    
    ll mid = (l+r)/2;
    if(x <= mid) return max(lichaoTree[idx].get(x), getMax(l, mid, lichaoTree[idx].l, x));
    else return max(lichaoTree[idx].get(x), getMax(mid+1, r, lichaoTree[idx].r, x));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    int q; cin >> q;
    while(q--) {
        int a; cin >> a;
        if(a == 1) {
            ll x, y; cin >> x >> y;
            add(-MAX, MAX, 0, {x, y});
        }
        else {
            ll x; cin >> x;
            cout << getMax(-MAX, MAX, 0, x) << '\n';
        }
    }

    return 0;
}