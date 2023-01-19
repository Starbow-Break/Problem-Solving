#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int L, K, C;
vector<int> cut;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> L >> K >> C;
    for(int i = 0; i < K; i++) {
        int v; cin >> v;
        cut.push_back(v);
    }
    cut.push_back(L); cut.push_back(0);
    
    sort(cut.begin(), cut.end());
    cut.erase(unique(cut.begin(), cut.end()), cut.end());
    
    int i = 0; int j = L;
    for(int k = 1; k < cut.size(); k++) {
        i = max(i, cut[k]-cut[k-1]);
    }
    
    while(i <= j) {
        int mid = (i+j)>>1;
        
        int cnt = 0; int cur = 0;
        for(int k = 1; k < cut.size(); k++) {
            cur += cut[k]-cut[k-1];
            if(cur > mid) {
                cnt++; cur = cut[k]-cut[k-1];
            }
        }
        
        if(cnt <= C) j = mid-1;
        else i = mid+1;
    }
    
    int ans1 = i; int ans2;
    
    int cnt = 0; int cur = 0; int pos;
    for(int k = cut.size()-1; k > 0; k--) {
        cur += cut[k]-cut[k-1];
        if(cur > ans1) {
            cnt++; cur = cut[k]-cut[k-1];
            pos = cut[k];
        }
    }
    
    if(cnt < C) ans2 = cut[1];
    else ans2 = pos;
    
    cout << ans1 << " " << ans2;
    
    return 0;
}