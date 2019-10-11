#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> numbers;
    int n, x;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        numbers.push_back(x);
    }

    while(n--){
        cout << numbers[n] << " ";
    }

    return 0;
}
