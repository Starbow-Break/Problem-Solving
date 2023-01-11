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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll len[4];
vector<int> card[4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    cin >> len[0] >> len[1] >> len[2] >> len[3];
    
    for(int i = 0; i < N; i++) {
        char c; int u;
        cin >> c >> u;
        card[c-'A'].push_back(u);
    }
    
    for(int i = 0; i < 4; i++) sort(card[i].rbegin(), card[i].rend());
    
    int idx[4] = {0, 0, 0, 0};
    for(int i = 0; i < K; i++) {
        int t = -1;
        for(int j = 0; j < 4; j++) {
            if(idx[j] < card[j].size()) {
                if(t == -1) t = j;
                else {
                    double a = (double)card[t][idx[t]]/(double)len[t];
                    double b = (double)card[j][idx[j]]/(double)len[j];
                    if(a < b) t = j;
                }
            }
        }
        
        cout << (char)('A'+t) << " " << card[t][idx[t]] << '\n';
        
        len[t] += card[t][idx[t]]; idx[t]++;
    }

    return 0;
}