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
    
    int N; cin >> N;
    vector<int> vec;
    
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    sort(vec.begin(), vec.end());
    
    if(N == 1) { cout << 1; }
    else {
        ll S = 0;
        for(int i = 0; i < N-1; i++) { S += vec[i]; }
        
        cout << S+min(S+1, (ll)vec[N-1]);
    }

    return 0;
}