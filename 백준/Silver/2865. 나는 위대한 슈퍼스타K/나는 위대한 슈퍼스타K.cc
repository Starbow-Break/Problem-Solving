#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

vector<double> skill[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    while(M--) {
        for(int i = 1; i <= N; i++) {
            int num; double score;
            cin >> num >> score;
            skill[num].push_back(score);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        sort(skill[i].begin(), skill[i].end());
    }
    
    vector<double> high;
    for(int i = 1; i <= N; i++) {
        high.push_back(skill[i].back());
    }
    
    sort(high.rbegin(), high.rend());
    
    double ans = 0;
    for(int i = 0; i < K; i++) ans += high[i];
    
    cout << fixed << setprecision(1) << ans;

    return 0;
}