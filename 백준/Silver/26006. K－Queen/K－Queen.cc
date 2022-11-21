#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, K, R, C;
vector<ii> queen;
bool check[3][3] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K >> R >> C;
    while(K--) {
        int r, c; cin >> r >> c;
        queen.push_back({r, c});
    }
    
    for(auto &q: queen) {
        int r = q.first; int c = q.second;
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int rr = R+i-1; int cc = C+j-1;
                
                if(1 <= rr && rr <= N && 1 <= cc && cc <= N) {
                    if(r == rr) check[i][j] = true;
                    if(c == cc) check[i][j] = true;
                    if(abs(rr-r) == abs(cc-c)) check[i][j] = true;
                }
                else check[i][j] = true;
            }
        }
    }
    
    bool ch = check[1][1], st = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == 1 && j == 1) continue;
            
            if(!check[i][j]) st = false;
        }
    }
    
    if(ch && st) cout << "CHECKMATE";
    else if(ch) cout << "CHECK";
    else if(st) cout << "STALEMATE";
    else cout << "NONE";

    return 0;
}