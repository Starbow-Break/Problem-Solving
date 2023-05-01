#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<ii> pt;

ll ccw(int Ax, int Ay, int Bx, int By) {
    return 1LL*Ax*By-1LL*Ay*Bx;
}

bool compare1(ii &A, ii &B) {
    if(A.second != B.second)
        return A.second < B.second;
    else
        return A.first < B.first;
}

bool compare2(ii &A, ii &B) {
    ll c = ccw(A.first-pt[0].first, A.second-pt[0].second, 
                B.first-pt[0].first, B.second-pt[0].second);
                
    if(c != 0)
        return c > 0;
    else {
        if(A.second != B.second)
            return A.second < B.second;
        else 
            return abs(pt[0].first-A.first) < abs(pt[0].first-B.first);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        pt.push_back({x, y});
    }

    sort(pt.begin(), pt.end(), compare1);
    sort(pt.begin()+1, pt.end(), compare2);
    
    deque<ii> dq;
    dq.push_back(pt[0]); dq.push_back(pt[1]);
    for(int i = 2; i < N; i++) {
        ii cur = pt[i]; ii fir, sec;
        
        while(dq.size() >= 2) {
            fir = dq.back(); dq.pop_back();
            sec = dq.back();
            ll c = ccw(fir.first-sec.first, fir.second-sec.second,
                    cur.first-fir.first, cur.second-fir.second);
            
            if(c > 0) {
                dq.push_back(fir);
                dq.push_back(pt[i]);
                break;
            }
            if(c == 0) {
                dq.push_back(pt[i]);
                break;
            }
        }
    }
        
    cout << dq.size();
    
    return 0;
}
