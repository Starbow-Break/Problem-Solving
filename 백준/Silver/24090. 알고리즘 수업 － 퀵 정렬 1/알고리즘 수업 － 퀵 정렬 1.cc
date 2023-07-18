#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int N, K; 
int cnt = 0; pii ans = {-1, -1};
int partition(vector<int> &vec, int s, int e) {
    int i = s-1;
    for(int j = s; j < e; j++) {
        if(vec[j] < vec[e]) {
            cnt++; i++;
            if(cnt == K) {
                ans = {vec[i], vec[j]};
            }
            swap(vec[i], vec[j]);
        }
    }
    if(i+1 != e) {
        cnt++;
        if(cnt == K) {
            ans = {vec[i+1], vec[e]};
        }
        swap(vec[i+1], vec[e]);
    }
    
    return i+1;
}

void quickSort(vector<int> &vec, int s, int e) {
    if(s < e) {
        int q = partition(vec, s, e);
        quickSort(vec, s, q-1);
        quickSort(vec, q+1, e);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    vector<int> vec;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    quickSort(vec, 0, N-1);
    
    if(ans.first == -1) cout << -1;
    else cout << min(ans.first, ans.second) << ' ' << max(ans.first, ans.second);

    return 0;
}