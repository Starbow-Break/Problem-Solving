#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
int A[100001];
vector<int> vec;

int find(int value) {
    int i = 0; int j = vec.size()-1;
    
    while(i <= j) {
        int mid = (i+j)>>1;
        if(vec[mid] < value) i = mid+1;
        else j = mid-1;
    }
    
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    
    vec.push_back(A[1]);
    for(int i = 2; i <= N; i++) {
        int t = find(A[i]);
        if(t < vec.size()) vec[t] = A[i];
        else vec.push_back(A[i]);
    }
    
    cout << N-vec.size();

    return 0;
}