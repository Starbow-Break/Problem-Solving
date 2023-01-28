#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX 1000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> dd;

bool bus[500001];
int len[500001];

struct node {
    int num, pos; bool isStart;
    
    bool operator<(node &N) {
        if(pos != N.pos) return pos < N.pos;
        else {
            if(isStart == N.isStart) {
                if(isStart)
                    return len[num] > len[N.num];
                else
                    return len[num] < len[N.num];
            }
        }
    }
};

vector<node> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    fill(bus+1, bus+M+1, true);
    
    for(int i = 1; i <= M; i++) {
        int s, f; cin >> s >> f;
        
        if(s < f) {
            vec.push_back({i, s, true}); vec.push_back({i, f+1, false});
            vec.push_back({i, N+s, true}); vec.push_back({i, N+f+1, false});
            len[i] = f-s+1;
        }
        else {
            vec.push_back({i, s, true}); vec.push_back({i, N+f+1, false});
            len[i] = N+f-s+1;
        }
    }
    
    sort(vec.begin(), vec.end());
    
    queue<int> q;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i].isStart) q.push(vec[i].num);
        else {
            if(!q.empty() && q.front() == vec[i].num) {
                q.pop();
                while(!q.empty() && !bus[q.front()]) q.pop();
            }
            else {
                bus[vec[i].num] = false;
            }
        }
    }
    
    for(int i = 1; i <= M; i++) {
        if(bus[i]) cout << i << " ";
    }

    return 0;
}