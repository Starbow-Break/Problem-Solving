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

vector<pii> robot(11), shelter(11);
vector<vector<int>> permutation;

bool visited[11] = {false, }; vector<int> temp;
void getPermutation(int N, int step = 0) {
    if(step == N) permutation.push_back(temp);
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            temp.push_back(i); visited[i] = true;
            getPermutation(N, step+1);
            visited[i] = false; temp.erase(temp.end()-1);
        }
    }
}

int ccw(pii a, pii b) {
    return a.first*b.second-a.second*b.first;
}

bool check(pii a, pii b, pii c, pii d) {
    int c1 = ccw({c.first-a.first, c.second-a.second}, {d.first-a.first, d.second-a.second});
    int c2 = ccw({c.first-b.first, c.second-b.second}, {d.first-b.first, d.second-b.second});
    int c3 = ccw({a.first-c.first, a.second-c.second}, {b.first-c.first, b.second-c.second});
    int c4 = ccw({a.first-d.first, a.second-d.second}, {b.first-d.first, b.second-d.second});
    
    if(c1*c2 <= 0 && c3*c4 <= 0) {
        if(c1*c2 == 0 && c3*c4 == 0) {
            if(a.first == b.first) {
                bool ch1 = ((a.second-c.second)*(b.second-c.second) > 0 &&
                    (a.second-d.second)*(b.second-d.second) > 0);
                bool ch2 = ((c.second-a.second)*(d.second-a.second) > 0 &&
                    (c.second-b.second)*(d.second-b.second) > 0);
                        
                return ch1 && ch2;
            }
            else {
                bool ch1 = ((a.first-c.first)*(b.first-c.first) > 0 &&
                    (a.first-d.first)*(b.first-d.first) > 0);
                bool ch2 = ((c.first-a.first)*(d.first-a.first) > 0 &&
                    (c.first-b.first)*(d.first-b.first) > 0);
                        
                return ch1 && ch2;
            }
        }
        else return false;
    }
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        robot[i] = {x, y};
    }
    for(int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        shelter[i] = {x, y};
    }
    
    getPermutation(N);
    
    for(auto &p: permutation) {
        bool flag = true;
        for(int i = 1; i <= N && flag; i++) {
            for(int j = i+1; j <= N && flag; j++) {
                flag = check(robot[i], shelter[p[i-1]], robot[j], shelter[p[j-1]]);
            }
        }
        
        if(flag) {
            for(auto &i: p) cout << i << '\n';
            break;
        }
    }

    return 0;
}