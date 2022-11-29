#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
int s[10001];
int sw[10001];
int A[10001];
int lis[10001]; int len = 0;
int D[10001];

int find(int value) {
    int i = 0; int j = len-1;
    while(i <= j) {
        int mid = (i+j)/2;
        if(lis[mid] < value) {
            i = mid+1;
        }
        else if(lis[mid] > value) {
            j = mid-1;
        }
        else return mid;
    }
    
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        s[i] = v; sw[v] = i;
    }
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        A[i] = sw[v];
    }
    
    for(int i = 1; i <= N; i++) {
        if(len == 0) {
            lis[len] = A[i]; len++;
            D[i] = len;
        }
        else {
            int t = find(A[i]);
            lis[t] = A[i];
            if(t == len) { len++; }
            D[i] = t+1;
        }
    }
    
    cout << len << '\n';
    vector<int> ans;
    for(int i = N; i >= 1; i--) {
        if(D[i] == len) {
            ans.push_back(s[A[i]]);
            len--;
        }
    }
    
    sort(ans.begin(), ans.end());
    for(auto &a: ans) {
        cout << a << " ";
    }

    return 0;
}
