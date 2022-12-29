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

struct info {
    int s, f, num;
    
    bool operator<(info &i) {
        if(f != i.f) return f < i.f;
        else return s < i.s;
    }
};

int N, C;
vector<info> vec;
int arr[2001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> C;
    int M; cin >> M;
    for(int i = 0; i < M; i++) {
        int s, f, num; cin >> s >> f >> num;
        vec.push_back({s, f, num});
    }
    
    sort(vec.begin(), vec.end());
    
    int ans = 0;
    for(int i = 0; i < M; i++) {
        int c = 0;
        for(int j = vec[i].s; j < vec[i].f; j++) { c = max(c, arr[j]); }
        
        c = min(vec[i].num, C-c);
        
        ans += c;
        for(int j = vec[i].s; j < vec[i].f; j++) arr[j] += c;
    }
    
    cout << ans;

    return 0;
}