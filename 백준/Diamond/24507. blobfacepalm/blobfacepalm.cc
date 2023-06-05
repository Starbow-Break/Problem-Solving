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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int ans[2'000'000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    if(N == 1) cout << "Yes" << '\n' << "0 0";
    else if(N == 4) cout << "Yes" << '\n' << "3 0 0 2 3 1 2 1";
    else if(N == 5) cout << "Yes" << '\n' << "4 1 3 1 2 4 3 2 0 0";
    else {
        if(N%4 == 2 || N%4  == 3) cout << "No";
        else {
            fill(ans, ans+2000000, -1);
            if(N%4 == 0) {
                int k = N/2; int idx = 0;
                for(int i = k; i >= 1; i--) {
                    ans[idx] = 2*i-1;
                    ans[idx+2*i] = 2*i-1;
                    while(ans[idx] != -1) idx++;
                }
                ans[idx] = 2*k-2;
                ans[idx+2*k-1] = 2*k-2;
                while(ans[idx] != -1) idx++;
                ans[idx] = k-2;
                ans[idx+k-1] = k-2;
                while(ans[idx] != -1) idx++;
                for(int i = k-2; i >= k/2; i--) {
                    ans[idx] = 2*i;
                    ans[idx+2*i+1] = 2*i;
                    while(ans[idx] != -1) idx++;
                }
                for(int i = k/2-2; i >= 1; i--) {
                    ans[idx] = 2*i;
                    ans[idx+2*i+1] = 2*i;
                    while(ans[idx] != -1) idx++;
                }
                ans[idx] = 0; ans[idx+1] = 0;
            }
            else {
                int k = N/2; int idx = 0;
                for(int i = k; i >= 1; i--) {
                    ans[idx] = 2*i;
                    ans[idx+2*i+1] = 2*i;
                    while(ans[idx] != -1) idx++;
                }
                ans[idx] = k+1;
                ans[idx+k+2] = k+1;
                while(ans[idx] != -1) idx++;
                ans[idx] = 2*k-1;
                ans[idx+2*k] = 2*k-1;
                while(ans[idx] != -1) idx++;
                for(int i = k-1; i >= k/2+2; i--) {
                    ans[idx] = 2*i-1;
                    ans[idx+2*i] = 2*i-1;
                    while(ans[idx] != -1) idx++;
                }
                for(int i = k/2; i >= 1; i--) {
                    ans[idx] = 2*i-1;
                    ans[idx+2*i] = 2*i-1;
                    while(ans[idx] != -1) idx++;
                }
                ans[idx] = 0; ans[idx+1] = 0;
            }
            
            cout << "Yes" << '\n';
            for(int i = 0; i < 2*N; i++) cout << ans[i] << ' ';
        }
    }

    return 0;
}