#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const ll INF = 1e18;

struct cmp {
    bool operator()(pll &A, pll &B) {
        if(A.second != B.second) return A.second > B.second;
        else return A.first > B.first;
    }
};

int L, n;
vector<int> S;
priority_queue<pll, vector<pll>, cmp> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> L;
    for(int i = 0; i < L; i++) {
        int v; cin >> v;
        S.push_back(v);
        pq.push({v, 0});
    }
    
    sort(S.begin(), S.end());
    cin >> n;
    
    for(int i = 0; i <= L; i++) {
        if(i == 0) {
            int inc = S[i]-2; int dec = -1;
            ll val = 0; int cnt = 0;
            int l = 1; int r = S[i]-1;
            while(cnt < n && l <= r) {
                cnt++;
                val += inc;
                if(dec > 0) val -= dec;
                pq.push({l, val});
                if(l < r) pq.push({r, val});
                l++; r--; inc--; dec++;
            }
        }
        else if(i == L) {
            int cnt = 0;
            int l = S[i-1]+1;
            while(cnt < n) {
                cnt++;
                pq.push({l, INF});
                l++;
            }
        }
        else {
            int inc = S[i]-S[i-1]-2; int dec = -1;
            ll val = 0; int cnt = 0;
            int l = S[i-1]+1; int r = S[i]-1;
            while(cnt < n && l <= r) {
                cnt++;
                val += inc;
                if(dec > 0) val -= dec;
                pq.push({l, val});
                if(l < r) pq.push({r, val});
                l++; r--; inc--; dec++;
            }
        }
    }
    
    while(n--) {
        cout << pq.top().first << " ";
        pq.pop();
    }

    return 0;
}