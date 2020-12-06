#include "matrix.h"
#include <iostream>
#include <cstring>
using namespace std;

matrix::matrix()
{
  rows = 1;
  columns = 1;
  float *data = new float[1];
  data[0]=0;
  memoryNumber = 0;
}
matrix::matrix(int row, int col, float *data)
{
  rows = row;
  columns = col;
  memoryNumber = 0;

  this->data = data;
}
matrix::matrix(int r, int c)
{
  rows = r;
  columns = c;
  memoryNumber = 0;
  data = new float[rows * columns];
  memset(data, 0, columns * rows);
}
int matrix::getCol()
{
  return this->columns;
}
int matrix::getRow()
{
  return this->rows;
}
void matrix::setCol(int c)
{
  this->columns = c;
}
void matrix::setRow(int l)
{
  this->columns = l;
}
float *matrix::getData()
{
  return this->data;
}
void matrix::setData(float *other)
{
  this->data = other;
}
matrix matrix::operator*(const matrix other) const
{

  float *temp = new float[other.columns * this->rows];
  memset(temp,0,other.columns * this->rows);
  for (int i = 0; i < this->rows; i++)
  {
    for (int j = 0; j < other.columns; j++)
    {
      for (int k = 0; k < this->columns; k++)
      {
        temp[i * other.columns + j] += this->data[i * this->columns + k] * other.data[other.columns * k + j];
      }
    }
  }
  return matrix(this->rows, other.columns, temp);
}
matrix matrix::operator+(matrix other) const
{

  float *temp = new float[this->rows * this->columns];
  memset(temp,0,other.columns * this->rows);
  for (int i = 0; i < other.rows * other.columns; i++)
  {
    temp[i] = this->data[i] + other.data[i];
  }

  return matrix(other.rows, other.columns, temp);
}
matrix matrix::operator-(matrix other) const
{
  float *temp = new float[this->rows * this->columns];
  memset(temp,0,other.columns * this->rows);
  for (int i = 0; i < other.rows * other.columns; i++)
  {
    temp[i] = this->data[i] - other.data[i];
  }

  return matrix(other.rows, other.columns, temp);
}
matrix &matrix::operator=(matrix other) 
{

  this->columns = other.columns;
  this->rows = other.rows;

  this->data = other.data;
  other.memoryNumber++;

  return *this;
}
matrix::~matrix()
{
  if (this->memoryNumber != 0)
  {
    this->memoryNumber--;
  }
  else
  {

    delete[] this->data;
  }
}
ostream &operator<<(ostream &os, const matrix &other)
{
  for (int i = 0; i < other.rows * other.columns; i++)
  {
    cout << other.data[i] << " "<<endl;
  }
  return os;
}
matrix operator*(float c,matrix other){
  float *temp=new float[other.rows*other.columns];
  memset(temp,0,other.rows*other.columns);
  for (int i = 0; i <other.rows*other.columns; i++)
  {
    temp[i]=c*other.data[i];
  }
  return matrix(other.rows,other.columns,temp);
}
