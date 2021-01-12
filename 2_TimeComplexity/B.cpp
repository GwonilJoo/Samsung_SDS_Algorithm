// 2805 나무 자르기

/*
이분탐색 이용
톱의 위치를 정하는 기준은 톱으로 나무들을 잘랐을때의 길이 결과!
나무들을 자른 결과의 길이로 분기점을 정해야 한다! 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
long long M;
vector<long long> tree, len_list;

void show(){
  for(int i=0;i<N;i++){
    cout << tree[i] << ' ';
  }
  cout << endl; 
  
  for(int i=0;i<len_list.size();i++){
    cout << len_list[i] << ' ';
  }
  cout << endl; 
}

void init(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    long long tmp;
    cin >> tmp;
    tree.push_back(tmp);
  }
  
  sort(tree.begin(), tree.end(), greater<int>());
}

long long cut(int h){
  long long sum = 0;
  for(int i=0;i<tree.size();i++){
    if(tree[i] - h < 0)
      break;
      
    sum += (tree[i] - h);
  }
  
  return sum;
}

void solution(){
  long long left = 1, right = tree[0], mid, result;
  
  while(left <= right){
    mid = (left + right)/2;
    result = cut(mid);
    
    if(result == M){
      cout << mid << endl;
      return;
    }
    else if(result < M){
      right = mid-1;
    }
    else{
      left = mid+1;
    }
  }
  
  cout << right << endl;
}

int main(){
  init();
  solution();
}
