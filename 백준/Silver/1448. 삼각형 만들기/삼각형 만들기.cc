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
    int straw[1000000];
    
    for(int i = 0; i < N; i++) {
        cin >> straw[i];
    }
    
    sort(straw, straw+N);
    
    for(int i = N-1; i >= 1; i--) {
        if(i == 1) cout << -1;
        else {
            if(straw[i] < straw[i-1]+straw[i-2]) {
                cout << straw[i]+straw[i-1]+straw[i-2];
                break;
            }
        }
    }

    return 0;
}