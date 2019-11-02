#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

struct Node{
    struct Node* children[ALPHABET_SIZE];
    bool finalized;
};

Node* init(){
    Node* root = new Node();
    for(int i = 0; i < ALPHABET_SIZE; i++)
        root->children[i] = NULL;
    root->finalized = false;
    return root;
}

void insert(Node *root, string word){
    
    char letter;
   
    for(int i = 0; i < word.size(); i++){
        letter = word[i];

        if(root->children[letter-'a'] == NULL){
            root->children[letter-'a'] = init();
        }
        root = root->children[letter-'a'];
    }
    root->finalized = true;
    
}

void print(Node *root, string str){

    if(root->finalized){
        cout << str << endl;
    }

    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(root->children[i]){
            str.push_back(97 + i);
        
            print(root->children[i], str);
        }
    }
}

int main(){
    Node* root = init();
    char str[ALPHABET_SIZE];
    insert(root, "accc");
    insert(root, "ac");
    insert(root, "abb");
    insert(root, "abbccc");
    print(root, str);
}