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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

vector<int> temp[16], dep[16];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    dep[1].push_back(1);
    
    for(int i = 2; i <= N; i++) {
        temp[1].push_back(1);
        for(int j = 1; j <= i-1; j++) {
            if(j < i-1) {
                for(auto &v: dep[j]) temp[j+1].push_back(2*v);
                for(auto &v: dep[j]) temp[j+1].push_back(2*v+1);
            }
            else {
                for(auto &v: dep[j]) temp[j+1].push_back(2*v+1);
                for(auto &v: dep[j]) temp[j+1].push_back(2*v);
            }
        }
        
        for(int j = 1; j <= N; j++) {
            dep[j].clear();
            for(auto &v: temp[j]) dep[j].push_back(v);
            temp[j].clear();
        }
    }
    
    int idx[16] = {0, }, k = 1;
    while(1) {
        while(k > 1 && 2*idx[k-1] <= idx[k]) k--;
        if(k == 1 && idx[k] > 0) break;
        
        cout << dep[k][idx[k]] << ' ';
        idx[k]++;
        if(k < N) k++;
    }
    cout << '\n';

    return 0;
}