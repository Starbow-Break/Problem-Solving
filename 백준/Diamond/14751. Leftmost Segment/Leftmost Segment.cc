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
#define MAX_M 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct horizental {
    double y; int num;
    
    bool operator<(horizental &h) {
        return y < h.y;
    }
};

struct line {
    int lowX, upperX, num;
    
    bool operator<(line &l) {
        return lowX < l.lowX;
    }
};

struct node {
    double y; line li;
};

int ans[MAX_M+1];
vector<horizental> horizentals;
vector<line> lines;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int maxY, minY; cin >> maxY >> minY;
    int Y = maxY-minY;
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int U, L; cin >> U >> L;
        lines.push_back({L, U, i});
    }
    
    int M; cin >> M;
    for(int i = 1; i <= M; i++) {
        double y; cin >> y;
        horizentals.push_back({y-minY, i});
    }
    
    sort(lines.begin(), lines.end());
    sort(horizentals.rbegin(), horizentals.rend());
    
    stack<node> s;
    for(auto &l: lines) {
        if(s.empty()) s.push({0, l});
        else {
            line t = s.top().li;
            if(t.upperX < l.upperX) continue;
            else {
                while(!s.empty()) {
                    t = s.top().li;
                    double y = (double)(Y*abs(l.lowX-t.lowX))/(abs(l.lowX-t.lowX)+abs(l.upperX-t.upperX));
                    if(s.top().y < y) { s.push({y, l}); break; }
                    s.pop();
                }
            }
        }
    }
    
    for(auto &h: horizentals) {
        while(s.top().y > h.y) s.pop();
        ans[h.num] = s.top().li.num;
    }
    
    for(int i = 1; i <= M; i++) cout << ans[i] << '\n';

    return 0;
}