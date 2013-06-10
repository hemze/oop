#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <typeinfo>
#include "lab2.cpp"

using namespace std;

class Matrix {

  friend ostream& operator << ( ostream&, const Matrix& );
  friend float operator * (Matrix&, Matrix&);

public:
  vector <Vector> items;

  Matrix(bool fillUp){
    int i,j,el,rsize,csize;
    cout << "Rows:";
    cin >> dec >> rsize;
    cout << "Cols:";
    cin >> dec >> csize;
    if(rsize > 0){
      for(i=0; i < rsize; i++){
        cout << "[" << (i+1) << "]:\n";
        //Vector vc(true,csize);
        Vector this->items[i](true,csize);

        //delete &vc;
      }
    }
  }

  int getRowSize() const {
    return this->items.size();
  }

  int getColSize() const {
    return this->items[0].getSize();
  }

  Vector operator [](unsigned id) {
    return this->items[id];
  }

  int operator ()(int row, int col) {
    return this->items[row].coords[col];
  }
  /*
  Matrix operator - (const Matrix &mx) {
    int i,j;
    for(i = 0; i < items.size(); i++){
      items[i] = items[i] - mx.items[i];
    }
    return *this;
  }

  Matrix operator + (const Matrix &mx) {
    int i;
    for(i = 0; i < items.size(); i++){
      items[i] += mx.items[i];
    }
    return *this;
  }

  Matrix operator += (const Matrix &mx) {
    int i;
    for(i = 0; i < items.size(); i++){
      items[i] += mx.items[i];
    }
    return *this;
  }

  Matrix operator -= (const Matrix &mx) {
    int i;
    for(i = 0; i < items.size(); i++){
      items[i] = items[i] - mx.items[i];
    }
    return *this;
  }

  Matrix operator = (Matrix &mx) {
    if(this == &mx) return this;
    int i;
    for(i = 0; i < items.size(); i++){
      items[i] = mx.items[i];
    }
    return *this;
  }
*/
  ~Matrix(){
    cout << "Destroying object " << *this;
  }
};
/*
Matrix operator * (Matrix & mx1, Matrix & mx2) {

}*/

Matrix operator ~ (Matrix & mx2) {

}

ostream& operator << ( ostream& os, const Matrix &mx ){
  for (int i = 0; i < mx.getRowSize(); i++){
    os << mx.items[i];
  }
  os << '\n';
  return os;
}
/*
Matrix operator - (Matrix & mx){
  int i;
  for(i = 0; i < mx.getRowSize(); i++){
    mx.items[i] = -mx.items[i];
  }
  return mx;
}
*/
int main(){
  Matrix mx1(true);
  cout << mx1;
  //*mx1(2) = 654;
  //cout << *mx1(2) << endl;
  //Matrix mx2(true);
  //cout << (mx1 - mx2) << endl;
  /*mx1 = mx2;
  cout << mx1 << endl;
  *mx2[0] = 555;
  cout << mx1 << endl;*/
  //cout << mx1*mx2 << endl;
  return 0;
}
