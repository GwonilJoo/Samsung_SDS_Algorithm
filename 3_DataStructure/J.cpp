// 1927 최소 힙
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
    // 트리 끝에 삽입
    int cur = node_num+1;
    Tree[node_num+1] = x;
    node_num++;
    
    while(cur/2){ // root에 도달하면 종료
      if(Tree[cur/2] > Tree[cur]){
        swap(Tree[cur/2], Tree[cur]);
        cur /= 2;
      }
      else break;
    } 
  }
  
  long long pop(){
    if(node_num == 0) return 0;
    
    // 마지막 노드를 루트에 삽입
    long long root = Tree[1];
    Tree[1] = Tree[node_num];
    node_num--;
    int cur = 1;
    
    while(cur <= node_num/2){ // 리프에 도달하면 종료
      if(Tree[cur*2] <= Tree[cur*2+1]){ // 형제 노드 비교해서 더 작은 것과 비교
        if(Tree[cur] > Tree[cur*2]){
          swap(Tree[cur], Tree[cur*2]);
          cur = cur*2;
        }
        else break;
      }
      else{
        if(Tree[cur] > Tree[cur*2+1]){
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
