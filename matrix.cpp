#include "matrix.h"
#include <iostream>
#include <cstring>
using namespace std;

matrix::matrix()
{
  rows = 1;
  columns = 1;
  float *data = new float[1];
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
  matrix result;
  result.rows = this->rows;
  result.columns = other.columns;
  result.data = new float[columns * rows];
  for (int i = 0; i < this->rows; i++)
  {
    for (int j = 0; j < other.columns; j++)
    {
      for (int k = 0; k < this->columns; k++)
      {
        result.data[i * result.columns + j] += this->data[i * this->columns + k] * other.data[other.columns * k + j];
      }
    }
  }
  return result;
}
matrix matrix::operator+(matrix other) const
{
  matrix result;
  result.rows = this->rows;
  result.columns = other.columns;
  result.data = new float[result.rows * result.columns];
  for (int i = 0; i < result.rows * result.columns; i++)
  {
    result.data[i] = this->data[i] + other.data[i];
  }

  return result;
}
matrix matrix::operator-(matrix other) const
{
  matrix result;
  result.rows = this->rows;
  result.columns = other.columns;
  result.data = new float[result.rows * result.columns];
  for (int i = 0; i < result.rows * result.columns; i++)
  {
    result.data[i] = this->data[i] - other.data[i];
  }
  return result;
}
matrix &matrix::operator=(matrix other)
{
  this->~matrix();
  this->columns = other.columns;
  this->rows = other.rows;

  this->data = other.data;
  other.memoryNumber++;
  cout << "=" << memoryNumber << endl;
  return *this;
}
matrix::~matrix()
{
  if (this->memoryNumber != 0)
  {
    this->memoryNumber--;
    cout << "-" << memoryNumber << endl;
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
    cout << other.data[i] << " ";
  }
  return os;
}
