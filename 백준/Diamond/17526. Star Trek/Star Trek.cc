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
    int a; ll b;
    ll get(int x) { return 1LL*a*x+b; }
};

struct node {
    int l, r;
    line li;
    ll get(int x) { return li.get(x); }
};

//Li Chao Tree
vector<node> lichaoTree;

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
ll getMin(int l, int r, int idx, int x) {
    if(idx == -1) return INF;
    
    int mid = l+r>>1;
    if(x <= mid) return min(lichaoTree[idx].get(x), getMin(l, mid, lichaoTree[idx].l, x));
    else return min(lichaoTree[idx].get(x), getMin(mid+1, r, lichaoTree[idx].r, x));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();
    ll dp[100'001], sum[100'001]; dp[1] = 0; sum[1] = 0;
    int p[100'001], s[100'001];
    
    int n; cin >> n;
    for(int i = 2; i <= n; i++) { cin >> sum[i]; sum[i] += sum[i-1]; }
    for(int i = 1; i < n; i++) cin >> p[i] >> s[i];
    
    for(int i = 2; i <= n; i++) {
        add(1, 200'000'000, 0, {s[i-1], dp[i-1]+p[i-1]-s[i-1]*sum[i-1]});
        dp[i] = getMin(1, 200'000'000, 0, sum[i]);
    }
    
    cout << dp[n];

    return 0;
}