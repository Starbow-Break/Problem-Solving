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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, L; cin >> N >> L;
    vector<int> alc(N);
    
    for(int i = 0; i < N; i++) cin >> alc[i]; 
    
    queue<int> q; int sum = 0; int ans = 0;
    
    for(int i = 0; i < N; i++) {
        q.push(alc[i]); sum += alc[i];
        if(q.size() > L) {
            sum -= q.front(); q.pop();
        }
        
        if(129 <= sum && sum <= 138) ans++;
    }
    
    cout << ans;

    return 0;
}