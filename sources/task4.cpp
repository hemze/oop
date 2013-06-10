#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class spiral{


public:
  spiral(int n){
    int matrix[n][n];
    int i,j,max,i1,j1;
    max = 0;
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        cout << "[" << i << "]" << "[" << j << "]:";
        cin >> dec >> matrix[i][j];
        if((i==j || (i +j + 1 == n)) && max<matrix[i][j]){
          max = matrix[i][j];
          i1=i;j1=j;
        }
      }
    }
    cout << "Is'hodnaya matrica:\n";
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        printf("%4d ", matrix[i][j]);
      }
      cout << "\n";
    }
    matrix[i1][j1] = matrix[(n-1)/2][(n-1)/2];
    matrix[(n-1)/2][(n-1)/2] = max;

    cout << "With max element in the center:\n";
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
        printf("%4d ", matrix[i][j]);
      }
      cout << "\n";
    }
  }
};

int main(){
  int n;
  cout << "Poryadok matricy: "; cin >> dec >> n;
  spiral new_spiral(n);
  return 0;
}
