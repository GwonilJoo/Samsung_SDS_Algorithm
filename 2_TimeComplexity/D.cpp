// 2517 달리기

/*
Inversion Count
merge sort의 merge 과정! 

근데 왜 시간초과 뜨냐;; -> endl 대신 '\n' 쓰기.....

*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Runner{
  int pos;
  long long value;
};

int N;
Runner nums[500000];
Runner temp[500000];
int Rank[500000];


void merge(int s, int m, int e){
  int p1 = s;
  int p2 = m+1;
  int k = s;
  
  while(p1<=m && p2<=e){
    if(nums[p1].value >= nums[p2].value){
      temp[k++] = nums[p1++];
    }
    else{
      Rank[nums[p2].pos] -= (m-p1+1);
      temp[k++] = nums[p2++];
    }
  }
  while(p1 <= m){
    temp[k++] = nums[p1++];
  }
  while(p2 <= e){
    temp[k++] = nums[p2++];
  }
  for(int i=s;i<=e;i++){
    nums[i] = temp[i];
  }
}

void mergeSort(int s, int e){
  if(s<e){
   int mid = (s+e)/2;
    mergeSort(s,mid);
    mergeSort(mid+1,e);
    merge(s,mid,e);
  } 
}

void init(){
  cin >> N;
  for(int i=0;i<N;i++){
    long long tmp;
    cin >> tmp;
    
    nums[i] = {i, tmp};
    Rank[i] = i+1;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  init();
  mergeSort(0,N-1);
  
  for(int i=0;i<N;i++)
    cout << Rank[i] << "\n";
}
