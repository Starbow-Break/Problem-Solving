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
    
    int s, v1, v2; cin >> s >> v1 >> v2;
    
    for(int i = s/v1; i >= -1; i--) {
        if(i == -1) {
            cout << "Impossible";
            break;
        }
        
        if((s-v1*i)%v2 == 0) {
            cout << i << ' ' << (s-v1*i)/v2;
            break;
        }
    }

    return 0;
}