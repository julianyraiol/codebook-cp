#include <bits/stdc++.h>

using namespace std;

map<string, int> contacts;
map<string, int>::iterator it;

int main(){
    int n, contact_number;
    string contact_name, contact, space;
    stringstream ss;

    cin >> n;
    cin.ignore(0);

    for(int i = 0; i < n; i++){
      cin >> contact_name >> contact_number;
      contacts[contact_name] = contact_number;
    }

    while(n--){
        cin >> contact;
        if(contacts[contact])
          cout<< contact << "=" << contacts[contact] << endl;
        else
          cout << "Not found" << endl;
    }

    return 0;
}
