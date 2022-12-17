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

int N;
vector<int> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    if(N == 1) cout << -1;
    else {
        for(int i = 0; i < N; i++) { int v; cin >> v; vec.push_back(v); }
        
        int i; int maxV = 0;
        for(i = N-2; i >= 0; i--) {
            maxV = max(maxV, vec[i+1]);
            if(vec[i] < vec[i+1]) break;
        }
        
        if(i == -1) cout << -1;
        else {
            int t = N+1;
            for(int j = i+1; j < N; j++) {
                if(vec[i] < vec[j] && vec[j] < t) {
                    t = vec[j];
                }
            }
            
            vector<int> temp;
            for(int j = i; j < N; j++) {
                if(vec[j] != t) {
                    temp.push_back(vec[j]);
                }
            }
            sort(temp.begin(), temp.end());
            
            for(int j = 0; j < i; j++) {
                cout << vec[j] << " ";
            }
            cout << t << " ";
            for(auto &te: temp) {
                cout << te << " ";
            }
        }
    }

    return 0;
}