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
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct node {
    int num, pos; bool isInsert;
    
    bool operator<(node &n) {
        return pos < n.pos;
    }
};

int F[1000001];
int arr[1000001] = {0, };
vector<node> vec;

void getFibonacci(int N) {
    F[0] = 1; F[1] = 1;
    for(int i = 2; i <= N; i++) { F[i] = (F[i-1]+F[i-2])%MOD; }
}

void printAnswer(int N) {
    priority_queue<int, vector<int>, less<int>> pq;
    
    int idx = 0;
    for(int i = 1; i <= N; i++) {
        while(idx < vec.size() && vec[idx].pos == i) {
            if(vec[idx].isInsert) {
                pq.push(vec[idx].num); arr[vec[idx].num] = i;
            }
            else {
                arr[vec[idx].num] = 0;
            }
            
            idx++;
        }
        
        while(!pq.empty() && arr[pq.top()] == 0) { pq.pop(); }
        
        if(pq.empty()) cout << 0 << " ";
        else cout << F[i-arr[pq.top()]+1] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    getFibonacci(N);
    
    int Q; cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int l, r; cin >> l >> r;
        vec.push_back({i, l, true});
        vec.push_back({i, r+1, false});
    }
    sort(vec.begin(), vec.end());
    
    printAnswer(N);

    return 0;
}