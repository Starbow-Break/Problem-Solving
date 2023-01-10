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

vector<int> people;
int N, K;
bool burger[20000] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    string s; cin >> s;
    for(int i = 0; i < N; i++) {
        if(s[i] == 'H') {
            burger[i] = true;
        }
        else {
            people.push_back(i);
        }
    }
    
    int ans = 0;
    for(auto &idx: people) {
        for(int j = max(0, idx-K); j <= min(N-1, idx+K); j++) {
            if(burger[j]) {
                ans++; burger[j] = false;
                break;
            }
        }
    }
    
    cout << ans;

    return 0;
}