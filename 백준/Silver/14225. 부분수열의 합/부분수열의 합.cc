#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool check[2000002] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> S;
    for(int i = 0; i < N; i++) { int v; cin >> v; S.push_back(v); }
    
    for(int state = 1; state < (1<<N); state++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            if(state & (1<<j)) {
                sum += S[j];
            }
        }
        
        check[sum] = true;
    }
    
    for(int i = 1; i <= 2000001; i++) {
        if(!check[i]) {
            cout << i;
            break;
        }
    }

    return 0;
}