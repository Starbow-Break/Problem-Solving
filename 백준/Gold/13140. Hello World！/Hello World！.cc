#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool isUsed[10] = {false, };
pii solve(unsigned int N) {
    for(int d = 0; d < 10; d++) {
        isUsed[d] = true;
        for(int e = 0; e < 10; e++) {
            if(isUsed[e]) continue;
            isUsed[e] = true;
            for(int l = 0; l < 10; l++) {
                if(isUsed[l]) continue;
                isUsed[l] = true;
                for(int o = 0; o < 10; o++) {
                    if(isUsed[o]) continue;
                    isUsed[o] = true;
                    for(int r = 0; r < 10; r++) {
                        if(isUsed[r]) continue;
                        isUsed[r] = true;
                        for(int h = 1; h < 10; h++) {
                            if(isUsed[h]) continue;
                            isUsed[h] = true;
                            for(int w = 1; w < 10; w++) {
                                if(isUsed[w]) continue;
                                isUsed[w] = true;
                                
                                int A = h*10000+e*1000+l*110+o;
                                int B = w*10000+o*1000+r*100+l*10+d;
                                
                                if(A+B == N) return {A, B};
                                
                                isUsed[w] = false;
                            }
                            isUsed[h] = false;
                        }
                        isUsed[r] = false;
                    }
                    isUsed[o] = false;
                }
                isUsed[l] = false;
            }
            isUsed[e] = false;
        }
        isUsed[d] = false;
    }
    
    return {-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    unsigned int N; cin >> N;
    pii ans = solve(N);
    
    if(ans.first == -1 && ans.second == -1) cout << "No Answer";
    else {
        cout << "  " << ans.first << '\n';
        cout << "+ " << ans.second << '\n';
        cout << "-------" << '\n';
        if(N < 100000) { cout << " "; }
        cout << " " << N << '\n';
    }

    return 0;
}
