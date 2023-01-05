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

double pos[200001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double d[200001], dd[200001];
    
    int N, Q; cin >> N >> Q;
    d[1] = 0; dd[N] = 0;
    for(int i = 1; i <= N; i++) { cin >> pos[i][0]; }
    for(int i = 1; i <= N; i++) { cin >> pos[i][1]; }
    
    for(int i = 2; i <= N; i++) {
        d[i] = sqrt((pos[i][0]-pos[i-1][0])*(pos[i][0]-pos[i-1][0])+
                    (pos[i][1]-pos[i-1][1])*(pos[i][1]-pos[i-1][1]));
        
        if(pos[i][1] > pos[i-1][1]) d[i] *= 3;
        else if(pos[i][1] == pos[i-1][1]) d[i] *= 2;
        
        d[i] += d[i-1];
    }
    
    for(int i = N-1; i >= 1; i--) {
        dd[i] = sqrt((pos[i][0]-pos[i+1][0])*(pos[i][0]-pos[i+1][0])+
                    (pos[i][1]-pos[i+1][1])*(pos[i][1]-pos[i+1][1]));
        
        if(pos[i][1] > pos[i+1][1]) dd[i] *= 3;
        else if(pos[i][1] == pos[i+1][1]) dd[i] *= 2;
        
        dd[i] += dd[i+1];
    }
    
    cout << fixed << setprecision(12);
    
    while(Q--) {
        int i, j; cin >> i >> j;
        if(i < j) cout << d[j]-d[i] << '\n';
        else cout << dd[j]-dd[i] << '\n';
    }

    return 0;
}