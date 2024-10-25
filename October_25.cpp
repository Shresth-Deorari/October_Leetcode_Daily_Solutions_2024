struct Node{
    Node * ch[27];
    bool flag;

    Node(){
        flag = false;
        for (int i = 0; i < 27; i++) {
        ch[i] = NULL; // Initialize to NULL
        }
    }

    public:

    bool exists(char character){
        if(character =='/')return ch[26]!=NULL;
        return ch[character-'a']!=NULL;
    }

    Node* getNext(char character){
        if(character =='/')return ch[26];
        return ch[character-'a'];
    }

    void addNode(char character){
        Node * newNode = new Node();
        if(character=='/')ch[26] = newNode;
        else ch[character-'a'] = newNode;
    }

    void setFlag(){
        flag = true;
    }

    bool getFlag(){
        return flag;
    }

};
class Trie{

    Node * root = new Node();

    public :

    void buildTrie(vector<string>&folder){

        for(auto str : folder){

            Node * temp = root;

            for(int i = 0;i<str.size();i++){

                char character = str[i];

                if(!temp->exists(character)){
                    temp->addNode(character);
                }

                temp = temp->getNext(character);

                if (character == '/' || i == str.size() - 1) {
                    temp->setFlag();
                }

            }
        }
    }

    bool isSubfolder(string &str){

        Node * temp = root;

        for(int i = 0;i<str.size()-1;i++){

            temp = temp->getNext(str[i]);
            if((i+1<str.size()-1 && str[i+1]=='/' )&& temp->getFlag())return false;
        }

        return true;
    }

};
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        vector<string>ans;
        trie.buildTrie(folder);
        for(auto str: folder){
            if(trie.isSubfolder(str))ans.push_back(str);
        }
        return ans;
    }
};