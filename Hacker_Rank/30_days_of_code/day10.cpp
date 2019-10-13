#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, count=0;
    cin >> n;

    while(n){
      n = n & (n << 1);
      count++;
    }
    
    cout << count << endl;
    return 0;
}
