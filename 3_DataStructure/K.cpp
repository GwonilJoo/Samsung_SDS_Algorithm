// 11279 최대 힙
/*
pop 부분 형제노드 고려하자....
*/

#include<iostream>
using namespace std;

class Heap{
  long long Tree[100001];
  int node_num;
public:
  Heap(){
    node_num = 0;
  }
  
  void push(long long x){
    int cur = node_num+1;
    Tree[node_num+1] = x;
    node_num++;
    
    while(cur/2){
      if(Tree[cur/2] < Tree[cur]){
        swap(Tree[cur/2], Tree[cur]);
        cur /= 2;
      }
      else break;
    } 
  }
  
  long long pop(){
    if(node_num == 0) return 0;
    
    long long root = Tree[1];
    Tree[1] = Tree[node_num];
    node_num--;
    int cur = 1;
    
    while(cur <= node_num/2){
      if(Tree[cur*2] >= Tree[cur*2+1]){
        if(Tree[cur] < Tree[cur*2]){
          swap(Tree[cur], Tree[cur*2]);
          cur = cur*2;
        }
        else break;
      }
      else{
        if(Tree[cur] < Tree[cur*2+1]){
          swap(Tree[cur], Tree[cur*2+1]);
          cur = cur*2+1;
        }
        else break;
      }
    }
    
    return root;
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  Heap heap;
  int N;
  long long x;
  
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> x;
    if(x == 0)
      cout << heap.pop() << "\n";
    else
      heap.push(x);
  }
}
