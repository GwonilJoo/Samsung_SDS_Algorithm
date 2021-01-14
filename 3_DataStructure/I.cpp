#include<iostream>
#include<cstring>
#include<set>
using namespace std;

int w, b;
bool visited[4][4];
string map[4];
set<string> Find;

int dy[] = {-1,-1,-1,0,0,1,1,1};
int dx[] = {-1,0,1,-1,1,-1,0,1};
int score[] = {0,0,0,1,1,2,3,5,11};

struct Trie{
  Trie* child[26];
  bool isEnd, isHit;
  
  Trie(){
    memset(this->child, 0, sizeof(this->child));
    this->isEnd = false;
    this->isHit = false;
  }
  
  ~Trie(){
    for(int i=0;i<26;i++){
      if(this->child[i])
        delete this->child[i];
    }
  }
  
  void insert(string word){
    Trie *current = this;
    for(int i=0;i<word.length();i++){
      int index = word[i] - 'A';
      if(!current->child[index]){
        current->child[index] = new Trie();
      }
      current = current->child[index];
    }
    current->isEnd = true;
  }
  
  void search(int y, int x, string word){
    if(word.length() > 8) return;
    
    // 1. 체크인
    visited[y][x] = true;
    word += map[y][x];
    
    // 2. 목적지 도달했는가?   
    Trie *node = this->child[map[y][x] - 'A'];
    if(!node){
      visited[y][x] = false;
      return;
    }
    
    if(node->isEnd){
      //cout << "word: " << word << " ";
      Find.insert(word);
      node->isHit = true;
    }
    
    // 3. 연결된 곳을 순회
    for(int i=0;i<8;i++){
      int next_y = y + dy[i];
      int next_x = x + dx[i];
      
      // 4. 갈 수 있는가
      if(next_y < 0 || next_y >= 4 || next_x < 0 || next_x >= 4 || visited[next_y][next_x])
        continue;
      
      // 5. 간다
      node->search(next_y, next_x, word);
    }
    
    // 6. 체크아웃
    visited[y][x] = false;
  }
  
  void hitClear(){
    this->isHit = false;
    
    for(int i=0;i<26;i++){
      if(this->child[i])
        this->child[i]->hitClear();
    } 
  }
};

int main(){
  Trie *root = new Trie();
  
  cin >> w;
  for(int i=0;i<w;i++){
    string word;
    cin >> word;
    root->insert(word);
  }
  
  cin >> b;
  for(int i=0;i<b;i++){
    // map 초기화
    for(int row=0;row<4;row++)
        cin >> map[row];
    
    // Find 초기화
    Find.clear();
    root->hitClear();
    
    // search
    for(int row=0;row<4;row++){
      for(int col=0;col<4;col++){
        root->search(row, col, "");
      }
    }
    
    string longest = "";
    int num = Find.size(), sum = 0, Max = 0;
    
    for(string str : Find){
      if(Max == str.length()){
        longest = longest < str ? longest : str;
      }
      else if(Max < str.length()){
        Max = str.length();
        longest = str;
      }
      sum += score[str.length()];
    }
    
    cout << sum << " " << longest << " " << num << "\n";
  }
}
