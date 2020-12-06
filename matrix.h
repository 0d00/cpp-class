#pragma once
#include <iostream>
using namespace std;
class matrix
{
private:
  int memoryNumber;
   int rows;
    int columns;
    float *data;
public:
    matrix();
    matrix(int,int,float*);
     matrix(int,int);
     int getRow();
     int getCol();
     void setRow(int);
     void setCol(int);
     float* getData();
     void setData(float*);
    matrix& operator=(matrix) ;
    matrix operator*(const matrix) const;
    matrix operator+(matrix) const;
    matrix operator-(matrix) const;
    ~matrix();
    friend ostream& operator<<(ostream&,const matrix&);
    friend matrix operator*(float,const matrix) ;
};

