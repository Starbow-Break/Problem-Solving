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
    
    int N; cin >> N; int ans[2] = {0, };
    while(N--) {
        int score[2];
        cin >> score[0] >> score[1];
        
        if(score[0] > score[1]) ans[0]++;
        if(score[0] < score[1]) ans[1]++;
    }
    
    cout << ans[0] << " " << ans[1];
    
    return 0;
}