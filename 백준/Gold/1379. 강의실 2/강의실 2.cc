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

struct _class {
    int num, s, f;
    
    bool operator<(_class &c) {
        return f > c.f;
    }
};

struct classroom {
    int num, bound;
};

struct cmp {
    bool operator()(classroom &A, classroom &B) {
        if(A.bound != B.bound) return A.bound < B.bound;
        else A.num > B.num;
    }
};

int N;
int ans[100001];
vector<_class> classes;
priority_queue<classroom, vector<classroom>, cmp> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num, s, f; cin >> num >> s >> f;
        classes.push_back({num, s, f});
    }
    
    sort(classes.begin(), classes.end());
    
    for(auto &c: classes) {
        int num = c.num; int s = c.s; int f = c.f;
        
        if(pq.empty() || pq.top().bound < f) {
            ans[num] = pq.size()+1;
            pq.push({ans[num], s});
        }
        else {
            ans[num] = pq.top().num; pq.pop();
            pq.push({ans[num], s});
        }
    }
    
    cout << pq.size() << '\n';
    for(int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}