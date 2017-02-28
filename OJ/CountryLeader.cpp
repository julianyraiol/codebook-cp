#include <bits/stdc++.h>
using namespace std;

int freq(string s){
	set<char> letras;

	for(int i = 0; i < s.size(); i++){
		if(isalpha(s[i]))
			letras.insert(s[i]);
	}
	return letras.size();
}

int main()
{
	vector<string> names;
	string name, resp;
	int t, n, maior, vfreq;
	cin >> t;

	for(int i = 1 ; i <= t; i++){
		cin >> n;
		cin.ignore();
		for(int i = 0; i < n; i++){
			getline(cin, name);
			names.push_back(name);
		}

		maior = 0;
		for(auto it: names){
			vfreq = freq(it);
			if(vfreq > maior){
				maior = vfreq;
				resp = it;
			}
			else if(vfreq == maior){
				if((string)it < (string)resp){
					resp = it;
			}}}
		cout << "Case #" << i << ": " << resp << endl;
		names.clear();
	}
	return 0;
}
