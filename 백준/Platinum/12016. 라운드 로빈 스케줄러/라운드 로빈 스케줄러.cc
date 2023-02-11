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
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 2'000'000'000;

int arr[MAX_N+1]; ll ans[MAX_N+1];
vector<pii> vec;

int segTree1[1 << 18], segTree2[1 << 18];

//---------------------------------------
void buildTree1(int l, int r, int idx) {
    if(l == r) {
        segTree1[idx] = arr[l]; return;
    }
    
    int mid = (l+r)>>1;
    buildTree1(l, mid, idx<<1); buildTree1(mid+1, r, (idx<<1)|1);
    segTree1[idx] = min(segTree1[idx<<1], segTree1[(idx<<1)|1]);
}

void update1(int l, int r, int idx, int t, int val) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree1[idx] = val; return;
    }
    
    int mid = (l+r)>>1;
    update1(l, mid, idx<<1, t, val); update1(mid+1, r, (idx<<1)|1, t, val);
    segTree1[idx] = min(segTree1[idx<<1], segTree1[(idx<<1)|1]);
}
//---------------------------------------

//---------------------------------------
void buildTree2(int l, int r, int idx) {
    if(l == r) {
        segTree2[idx] = 1; return;
    }
    
    int mid = (l+r)>>1;
    buildTree2(l, mid, idx<<1); buildTree2(mid+1, r, (idx<<1)|1);
    segTree2[idx] = segTree2[idx<<1]+segTree2[(idx<<1)|1];
}

void update2(int l, int r, int idx, int t, int val) {
    if(r < t || t < l) return;
    
    if(l == r) {
        segTree2[idx] = val; return;
    }
    
    int mid = (l+r)>>1;
    update2(l, mid, idx<<1, t, val); update2(mid+1, r, (idx<<1)|1, t, val);
    segTree2[idx] = segTree2[idx<<1]+segTree2[(idx<<1)|1];
}

int query2(int l, int r, int idx, int i, int j) {
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree2[idx];
    
    int mid = (l+r)>>1;
    return query2(l, mid, idx<<1, i, j)+query2(mid+1, r, (idx<<1)|1, i, j);
}
//---------------------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        vec.push_back({arr[i], i});
    }
    
    sort(vec.begin(), vec.end());
    
    buildTree1(1, N, 1); buildTree2(1, N, 1);
    
    int idx = 0; stack<int> s; ll t = 0, cy = 0;
    while(idx < vec.size()) {
        while(idx < vec.size() && vec[idx].first == segTree1[1]) {
            ans[vec[idx].second] = 
                0LL+t+segTree2[1]*(segTree1[1]-1-cy)+query2(1, N, 1, 1, vec[idx].second);
            
            s.push(vec[idx].second);
            
            idx++;
        }
        
        t += segTree2[1]*(segTree1[1]-cy);
        cy = segTree1[1];
        
        while(!s.empty()) {
            update1(1, N, 1, s.top(), INF);
            update2(1, N, 1, s.top(), 0);
            s.pop();
        }
    }
    
    for(int i = 1; i <= N; i++) { cout << ans[i] << '\n'; }

    return 0;
}