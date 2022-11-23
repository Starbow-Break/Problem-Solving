#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
int A[4000], B[4000], C[4000], D[4000];
vector<int> E, F;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            E.push_back(A[i]+B[j]);
            F.push_back(C[i]+D[j]);
        }
    }
    
    sort(E.begin(), E.end()); sort(F.begin(), F.end());
    
    int e = 0; int f = F.size()-1;
    ll ans = 0;
    while(e < E.size() && f >= 0) {
        if(E[e]+F[f] > 0) {
            f--;
        }
        else if(E[e]+F[f] < 0) {
            e++;
        }
        else {
            int cnt1 = 0, cnt2 = 0;
            int curE = E[e]; int curF = F[f];
            while(e < E.size() && E[e] == curE) { cnt1++; e++; }
            while(f >= 0 && F[f] == curF) { cnt2++; f--; }
            
            ans += 1LL*cnt1*cnt2;
        }
    }
    
    cout << ans;

    return 0;
}