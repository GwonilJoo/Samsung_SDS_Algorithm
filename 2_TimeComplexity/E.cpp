// 1806 부분합

#include<iostream>
using namespace std;

int N;
long long S, A[100000];
int length;

void init(){
  cin >> N >> S;
  for(int i=0;i<N;i++)
    cin >> A[i];
    
  length = N+1;
}

void func(){
  int start = 0, end = 0;
  int sum = A[0];

  while(end <N){
    if(sum < S){
      sum += A[++end];
    }
    else{
      length = min(length, end-start+1);
      sum -= A[start++];
    }
  }
  
  if(length == N+1) length = 0;
}

int main(){
  init();
  func();
  cout << length << endl;
}
