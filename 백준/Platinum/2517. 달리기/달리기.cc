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
#define MAX_N 500'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
int skill[MAX_N+1];

int segTree[1 << 20] = {0, };

void update(int l, int r, int idx, int t, int del) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree[idx] += del; return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, t, del); update(mid+1, r, (idx<<1)|1, t, del);
    segTree[idx] = segTree[idx<<1] + segTree[(idx<<1)|1];
}

int query(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx];
    
    int mid = (l+r)>>1;
    return query(l, mid, idx<<1, i, j)+query(mid+1, r, (idx<<1)|1, i, j);
}

//좌표 압축
void compress() {
    vector<int> vec;
    for(int i = 1; i <= N; i++) { vec.push_back(skill[i]); }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for(int i = 1; i <= N; i++) {
        skill[i] = lower_bound(vec.begin(), vec.end(), skill[i])-vec.begin()+1; 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> skill[i];
    
    compress();
    
    for(int i = 1; i <= N; i++) {
        update(1, N, 1, skill[i], 1);
        cout << query(1, N, 1, skill[i], N) << '\n';
    }

    return 0;
}