// 1202 보석 도둑
/*
이중for문 사용시 O(n^2)

힙을 사용해서 O(nlgn) 으로 바꿔보자!
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
  int M, V;
};

vector<node> Jew;
vector<int> bag;

class Heap{
  vector<node> jew;
public:
  Heap(){
    jew.push_back({-1,-1});
  }
  
  int size(){
    return jew.size()-1;
  }
  
  void show(){
    cout << "----------------------\n";
    for(int i=1;i<jew.size();i++){
      cout << jew[i].M << " " << jew[i].V;
    }
    cout << "\n";
  }
  
  void push(node x){
    jew.push_back(x);
    int cur = jew.size()-1;
    
    while(cur/2){
      if(jew[cur/2].V < jew[cur].V){
        swap(jew[cur/2], jew[cur]);
        cur /= 2;
      }
      else break;
    } 
  }
  
  node pop(){    
    node root = jew[1];
    jew[1] = jew[jew.size()-1];
    jew.pop_back();
    int cur = 1;
    
    while(cur <= (jew.size()-1)/2){
      if(jew[cur*2].V >= jew[cur*2+1].V){
        if(jew[cur].V < jew[cur*2].V){
          swap(jew[cur], jew[cur*2]);
          cur = cur*2;
        }
        else break;
      }
      else{
        if(jew[cur].V < jew[cur*2+1].V){
          swap(jew[cur], jew[cur*2+1]);
          cur = cur*2+1;
        }
        else break;
      }
    }
    
    return root;
  }
};


long long solution();
int N, K, M, V, C;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  for(int i=0;i<N;i++){
    cin >> M >> V;
    Jew.push_back({M, V});
  }
  for(int i=0;i<K;i++){
    cin >> C;
    bag.push_back(C);
  }
  
  cout << solution() << "\n";
}

bool compare(node A, node B){
  return A.M < B.M;
}

long long solution(){
  long long sum = 0;
  Heap heap;
  
  sort(bag.begin(), bag.end()); // 가방 무게 순 정렬
  sort(Jew.begin(), Jew.end(), compare); // 보석 무게 순 정렬
  
  int jIndex = 0;
  for(int i=0;i<bag.size();i++){
    if(Jew.empty()) break;
    
    while(jIndex < N && Jew[jIndex].M <= bag[i]){
      heap.push(Jew[jIndex++]);
    }
    if(heap.size() > 0){
      sum += heap.pop().V;
    }
  }
  
  return sum;
}
