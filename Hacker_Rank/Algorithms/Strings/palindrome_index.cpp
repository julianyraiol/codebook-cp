#include <bits/stdc++.h>
#define MAX_N 10010

using namespace std;

int state[MAX_N];

void kmp_process(string text){
    int i = 1, j = 0, m = text.size();
    
    while(i < m){
        if(text[i] == text[j]){
            j++;
            state[i] = j;
            i++;
        }
        else{
            if(j > 0){
                j = state[j-1];
            }
            else{
                state[i] = 0;
                i++;
            }
        }
    }
}

bool kmp_pattern(string text, string pattern){
    int i = 0, j = 0, n = text.size(), m = pattern.size();

    while(i < n){
        while (j > 0 && text[i] != pattern[j]){
            j = state[j - 1];   
        }
        if(text[i] == pattern[j]){
            j++;
        }
        if(j == m){
            return true;
        }
        i++;
    }
    return false;
}

int main(){
    int n_tests;
    string text = "ababa", pattern = "ab";

    cin >> n_tests;
    cin.ignore();
    while (n_tests){
        cin >> text;
        cin >> pattern;

        kmp_process(text);
        cout << (kmp_pattern(text, pattern)? "YES" : "NO") << endl;

        n_tests--;
    }
    
    

    return 0;
}