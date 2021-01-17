// 6416 트리인가?

#include<iostream>
#include<vector>
using namespace std;

struct node{
  int parent, self;
};

vector<node> v;
int Max;
int *tree;
bool *visit;

void init(){
  int a, b;
  Max = 0;
  while(true){
    cin >> a >> b;
    
    if(a == -1 && b == -1) exit(0);
    if(a == 0 && b == 0) break;
    
    v.push_back({a,b});
    //cout << "v.push_back: " << a << ", " << b << endl;
    
    Max = max(Max, a);
    Max = max(Max, b);
  }
  
  tree = new int[Max+1];
  visit = new bool[Max+1];
  for(int i=1;i<=Max;i++){
    tree[i] = 0;
    visit[i] = false;
  }
}

bool make_tree(){
  if(Max == 0) return true;

  for(int i=0;i<v.size();i++){
    if(tree[v[i].self] != 0){
      return false;
    }
    else{
      tree[v[i].self] = v[i].parent;
      visit[v[i].self] = true;
      visit[v[i].parent] = true;
    }
  }
  
  int cnt = 0;
  for(int i=1;i<=Max;i++)
    if(visit[i] && tree[i] == 0) cnt++;
  
  if(cnt == 1) return true;
  else return false;
}

void free_mem(){
  delete [] tree;
  delete [] visit;
  v.clear();
}


int main(){
  int a, b, k=1;
  while(true){
    init();
    
    cout << "Case " << k << " is";
    if(!make_tree()){
      cout << " not";
    }
    cout << " a tree.\n";
    
    free_mem();
    k++;
  }
}
