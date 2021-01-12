// 1920 수 찾기
// 지금까지 sort 부분을 find_num 함수 안에 써서 시간 초과가 났던것;;
// 그리고 vecotr를 쓸 경우, 데이터 input이 너무 느리다
// printf, scanf를 쓰던지, cin.tie(0)를 사용할것.

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, M;
int A[100000];

void find_num(int n){
  int left = 0;
  int right = N-1;
  int mid;
  
  while(left<=right){
    mid = (left+right)/2;
    //cout << "left: " << left << ", mid: " << mid << ", right: " << right << endl;
    //cout << "n: " << n << ", A[mid]: " << A[mid] << endl;
    
    if(n == A[mid]){
      printf("1\n");
      return;
    }
    else if(n < A[mid]){
      right = mid-1;
    }
    else{
      left = mid+1;
    }
  }
  
  printf("0\n");
  return;
}

int main(){
  int n;
  scanf("%d", &N);
  for(int i=0;i<N;i++){
    scanf("%d", &A[i]);
  }
  
  sort(A, A+N);
  
  scanf("%d", &M);
  for(int i=0;i<M;i++){

    scanf("%d", &n);
    find_num(n);
  }
  
  return 0;
}
