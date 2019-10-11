#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
		string word, odd, even;

    cin >> n;
    while(n--){
      cin.ignore(0);
      odd = even = "";

      cin >> word;

      for(int i=0; i < word.length(); i++){
          if(i&1)
            odd+=word[i];
          else
            even+=word[i];
      }
      cout << even << " " << odd << endl;
    }
    
		return 0;
}
