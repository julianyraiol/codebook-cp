#include <bits/stdc++.h>

using namespace std;

map <string, string> dictionary;
map <string, string> kids;

int main(){

    int n, m;
    string language, word, name;

    cin >> n;
    while(n--){
        cin >> language;
	      cin.ignore();
        
	      getline(cin, word);
	      dictionary[language] = word;
    }

    cin >> m;
    while(m--){
      cin.ignore();

      getline(cin, name);
      cin >> language;

      kids[name] = language;

      cout << name << endl << dictionary[kids[name]] << endl << endl;
    }
    return 0;
}
