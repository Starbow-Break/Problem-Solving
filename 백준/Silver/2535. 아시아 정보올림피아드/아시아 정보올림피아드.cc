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
    int contury, student, score;
    
    bool operator<(info &A) {
        return score < A.score;
    }
};

vector<info> vec;
int cnt[101] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int a, b, c; cin >> a >> b >> c;
        vec.push_back({a, b, c});
    }
    
    sort(vec.rbegin(), vec.rend());
    
    int _cnt = 0;
    for(auto &item: vec) {
        if(_cnt == 3) break;
        if(cnt[item.contury] >= 2) continue;
        
        cout << item.contury << " " << item.student << '\n';
        cnt[item.contury]++; _cnt++;
    }

    return 0;
}