#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define MAX 200'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int N, H, S[MAX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> H;
    for(int i = 1; i <= N; i++) cin >> S[i];
    
    priority_queue<ll, vector<ll>, less<ll>> pq1; //최대힙
    priority_queue<ll, vector<ll>, greater<ll>> pq2; //최소힙
    
    ll w = H; ll ans = 0;
    pq1.push(S[1]); pq2.push(S[1]);
    
    for(int i = 2; i <= N; i++) {
        ll left = pq1.top()-w;
        ll right = pq2.top()+w;
        
        if(S[i] < left) {
            pq1.push(S[i]+w); pq1.push(S[i]+w);
            pq2.push(pq1.top()-2*w); pq1.pop();
            ans += (left-S[i]);
        }
        else if(S[i] > right) {
            pq2.push(S[i]-w); pq2.push(S[i]-w);
            pq1.push(pq2.top()+2*w); pq2.pop();
            ans += (S[i]-right);
        }
        else {
            pq1.push(S[i]+w); pq2.push(S[i]-w);
        }
        
        w += H;
    }
    
    cout << ans;
    
    return 0;
}