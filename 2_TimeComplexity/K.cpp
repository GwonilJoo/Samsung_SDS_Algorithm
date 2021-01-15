// 11003 최솟값 찾기
/*
 덱, 슬라이딩 윈도우를 써보자
 
 https://uk-coding.tistory.com/entry/%EB%B0%B1%EC%A4%80BOJ-11003%EB%B2%88-%EC%B5%9C%EC%86%9F%EA%B0%92-%EC%B0%BE%EA%B8%B0
 
 https://jaimemin.tistory.com/746
*/

#include<iostream>
#include<deque>
using namespace std;

#define MAX 5000000

struct node{
  int value;
  int order; 
};

int A[MAX];
deque<node> dq;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int N, L;
  cin >> N >> L;
  
  for(int i=0;i<N;i++)
    cin >> A[i];
    
  for(int i=0;i<N;i++){
    if(!dq.empty() && dq.front().order <= i-L)
      dq.pop_front();
    
    while(!dq.empty() && dq.back().value > A[i])
      dq.pop_back();
      
    dq.push_back({A[i], i});
    cout << dq.front().value << " ";
  }
  cout << "\n";
}
