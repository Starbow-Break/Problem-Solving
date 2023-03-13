#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt[81] = {0, };
    int S1, S2, S3; cin >> S1 >> S2 >> S3;
    for(int i = 1; i <= S1; i++) {
        for(int j = 1; j <= S2; j++) {
            for(int k = 1; k <= S3; k++) cnt[i+j+k]++;
        }
    }
    
    int ans = 0;
    for(int i = 3; i <= 80; i++) {
        if(cnt[ans] < cnt[i]) ans = i;
    }
    
    cout << ans;
    
    return 0;
}