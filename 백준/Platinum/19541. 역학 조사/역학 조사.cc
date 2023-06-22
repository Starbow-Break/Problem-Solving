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

int N, M;
vector<int> meetings[100'000]; //모임
bool state[100'001]; //최종 감염 상태
int initState[100'001]; //초기 상태

//구한 초기상태에서 최종상태가 가능한지 확인
bool check() {
    bool temp[100'001];
    for(int i = 1; i <= N; i++) temp[i] = initState[i];
    
    for(auto &meeting: meetings) {
        bool flag = false;
        for(auto &i: meeting) {
            if(temp[i]) {
                flag = true;
                break;
            }
        }
        if(flag) {
            for(auto &i: meeting) temp[i] = 1;
        }
    }
    
    for(int i = 1; i <= N; i++) {
        if(temp[i] != state[i]) return false;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        while(n--) {
            int v; cin >> v;
            meetings[i].push_back(v);
        }
    }
    
    for(int i = 1; i <= N; i++) {
        cin >> state[i];
        initState[i] = state[i];
    }
    
    for(int m = M-1; m >= 0; m--) {
        bool check = true;
        for(auto &i: meetings[m]) {
            check = check & initState[i];
            if(!check) break;
        }
        
        if(!check) { //비감염자가 있는 경우
            //초기에 비감염자였다고 예측할 수 있음
            for(auto &i: meetings[m]) initState[i] = 0;
        }
    }

    if(check()) {
        cout << "YES" << '\n';
        for(int i = 1; i <= N; i++) cout << initState[i] << ' ';
    }
    else cout << "NO";

    return 0;
}