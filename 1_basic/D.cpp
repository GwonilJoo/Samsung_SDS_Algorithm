// 1713 후보 추천하기

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct person{
  int num;
  int count;
  int timeStamp;
};

// struct operator overloading
bool operator<(person a, person b){
  if(a.count == b.count) return a.timeStamp < b.timeStamp;
  else return a.count < b.count;
}

int N, R_N;
vector<person> candidate;

void show(){
  for(int i=0;i<N;i++)
   cout << "num=" << candidate[i].num << ", count=" << candidate[i].count << ", timeStamp=" << candidate[i].timeStamp << endl;;
  cout << endl;
}

// for sort compare
bool compare(person A, person B){
  return A < B;
}

void replace(person new_candidate){
  sort(candidate.begin(), candidate.end(), compare); // sort using vector
  candidate[0] = new_candidate;
}

bool compare_ans(person A, person B){
  return A.num < B.num;
}

void result(){
  sort(candidate.begin(), candidate.end(), compare_ans);
  for(int i=0;i<N;i++)
    cout << candidate[i].num << ' ';
  cout << endl; 
}

int main(){
  cin >> N >> R_N;
  for(int i=0;i<R_N;i++){
    bool flag = false;
    int tmp;
    cin >>tmp;
    
    for(int j=0;j<candidate.size();j++){
      if(candidate[j].num == tmp){
        candidate[j].count++;
        flag = true;
        break;
      }
    }
    if(flag) continue;
    
    if(candidate.size() < N)
      candidate.push_back({tmp, 1, i});
    else
      replace({tmp, 1, i});
    
    //show();
  }
  
  result();
}
