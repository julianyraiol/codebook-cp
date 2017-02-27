#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 1000000

using namespace std;

string numbers[MAXN];

void init(){
	stringstream ss;
	string s;
	int j = 0;
	for(int i = 1; i < 1001; i++){
		ss << i; 
		ss >> s;
		for(int k = 0; k < s.size(); k++){
			numbers[++j] = s[k];
		} 
		ss.clear();
	}
		
}

int main(){_
	int n;
	cin >> n;
	init();
	cout << numbers[n] << endl;	
	return 0;
}
