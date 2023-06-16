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

string name[100]; int cnt[100] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, tc = 0;
    while(cin >> N) {
        if(!N) break;
        tc++;
        
        fill(cnt, cnt+N, 0);
        
        cin.ignore(); 
        for(int i = 0; i < N; i++) getline(cin, name[i]);
        
        for(int i = 0; i < 2*N-1; i++) {
            int num; char c; cin >> num >> c;
            cnt[num-1]++;
        }
        
        for(int i = 0; i < N; i++) {
            if(cnt[i] == 1) {
                cout << tc << ' ' << name[i] << '\n';
                break;
            }
        }
    }

    return 0;
}