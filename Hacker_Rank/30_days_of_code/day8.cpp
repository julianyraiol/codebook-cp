#include <bits/stdc++.h>

using namespace std;

map<string, int> contacts;

int main(){
    int n, contact_number;
    string contact_name, name;

    cin >> n;
    cin.ignore(0);

    for(int i = 0; i < n; i++){
      cin >> contact_name >> contact_number;
      contacts[contact_name] = contact_number;
    }

    while(cin >> name){
        if(contacts[name])
          cout<< name << "=" << contacts[name] << endl;
        else
          cout << "Not found" << endl;
    }

    return 0;
}
