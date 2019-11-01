#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

struct Node{
    Node* children[ALPHABET_SIZE];
    bool finalized;
    Node(){
        for(int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
        finalized = false;
    }
};

void insert(Node* root, string word){
    
    char letter;
    for(int i = 0; i < word.size(); i++){
        letter = word[i];

        if(root->children[letter-'a'] == NULL){
            root->children[letter-'a'] = new Node();
        }
        root = root->children[letter-'a'];
    }
    root->finalized = true;
}

void print(Node* root, char str[ALPHABET_SIZE], int level){
    if(root->finalized == true)
        cout << str << endl;
    else{
        for(int i = 0; i < ALPHABET_SIZE; i++){
            if(root->children[i] != NULL){
                str[level] = char('a'+i) ;
                print(root->children[i], str, level+1);
            }
        }
    }
}

int main(){
    Node* root = new Node();
    char str[ALPHABET_SIZE];
    insert(root, "c");
    insert(root, "abb");
    insert(root, "abbccc");
    print(root, str, 0);
}