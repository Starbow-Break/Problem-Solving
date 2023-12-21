#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll merge(pair<int, int> arr[], int start, int mid, int end) {
    int i = start; int j = mid+1;
    pair<int, int> temp[end-start+1]; int idx = 0;
    
    ll inv = 0; ll ans = 0;
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp[idx] = arr[i];
            idx++; i++;
            ans += inv;
        }
        else {
            temp[idx] = arr[j];
            idx++; j++;
            inv++;
        }
    }
    
    while(i <= mid) {
        temp[idx] = arr[i];
        idx++; i++;
        ans += inv;
    }
    
    while(j <= end) {
        temp[idx] = arr[j];
        idx++; j++;
        inv++;
    }
    
    for(int k = 0; k <= end-start; k++) {
        arr[start+k] = temp[k];
    }
    
    return ans;
}

ll mergeSort(pair<int, int> arr[], int start, int end) {
    if(start == end)
        return 0;
    
    int mid = (start+end)/2;
    ll A = mergeSort(arr, start, mid);
    ll B = mergeSort(arr, mid+1, end);
    ll C = merge(arr, start, mid, end);
    
    return A+B+C;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    pair<int, int> arr[M];
        
    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }
    
    sort(arr, arr+M);
    
    for(int i = 0; i < M; i++) {
        pair<int, int> p = arr[i];
        arr[i] = make_pair(p.second, p.first);
    }
        
    cout << mergeSort(arr, 0, M-1) << '\n';

    return 0;
}