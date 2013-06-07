#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Vector{

  friend ostream& operator << ( ostream&, const Vector& );
  friend float operator * (Vector&, Vector&);
  //friend Vector& operator - ( Vector& );

public:
  vector <int> contents;

  Vector(bool fillUp){
    int i,el,size;
    cout << "Size:";
    cin >> dec >> size;
    if(size > 0){
      if(fillUp){
        for(i=0; i < size; i++){
          cin >> dec >> el;
          this->contents.push_back(el);
        }
        cout << this->contents.size() << "\n";
      }
      else {
        this->contents.resize(size);
      }
    }
  }

  int getSize() const {
    return this->contents.size();
  }

  int * operator [](unsigned id) {
    int * position;
    position = this->contents.data();
    position += id;
    return position;
  }

  Vector operator - (const Vector &vc) {
    int i;
    for(i = 0; i < contents.size(); i++){
      contents[i] = contents[i] - vc.contents[i];
    }
    return *this;
  }

  Vector operator + (const Vector &vc) {
    int i;
    for(i = 0; i < contents.size(); i++){
      contents[i] += vc.contents[i];
    }
    return *this;
  }

  Vector operator += (const Vector &vc) {
    int i;
    for(i = 0; i < contents.size(); i++){
      contents[i] += vc.contents[i];
    }
    return *this;
  }

  Vector operator -= (const Vector &vc) {
    int i;
    for(i = 0; i < contents.size(); i++){
      contents[i] = contents[i] - vc.contents[i];
    }
    return *this;
  }

  Vector operator = (Vector &vc) {
    if(this == &vc) return this;
    int i;
    for(i = 0; i < contents.size(); i++){
      contents[i] = vc.contents[i];
    }
    return *this;
  }

  float operator () () {
    int i,sum = 0;
    float result;
    for(i = 0; i < contents.size(); i++){
      sum += pow(contents[i],2);
    }
    return sqrt(sum);
  }

  /*


  int operator + (const DateTime &dt) {
    return seconds + dt.seconds;
  }*/

  ~Vector(){
    cout << "Destroying object " << *this;
  }
};

float operator * (Vector & v1, Vector & v2) {
  return v1()*v2();
}

ostream& operator << ( ostream& os, const Vector &vc ){
  os << "{";
  for (int i = 0; i < vc.getSize(); i++)
    os << vc.contents[i] << "}";
  os << '}\n';
  return os;
}

Vector operator - (Vector & vc){
  int i;
  for(i = 0; i < vc.contents.size(); i++){
    vc.contents[i] = -vc.contents[i];
  }
  return vc;
}

int main(){
  Vector newVector1(true);
  cout << -newVector1;
  //*newVector1[2] = 654;
  //cout << *newVector1[2] << endl;
  Vector newVector2(true);
  //cout << (newVector1 - newVector2) << endl;
  /*newVector1 = newVector2;
  cout << newVector1 << endl;
  *newVector2[0] = 555;
  cout << newVector1 << endl;*/
  //cout << newVector1() << endl;
  cout << newVector1*newVector2 << endl;
  return 0;
}
