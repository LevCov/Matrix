#include "Matrix.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <string>


Matrix Matrix:: operator =(const Matrix& other)// перегрузка оператора = 
{

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			this->M[i][j] = other.M[i][j];
		}
	}

	return *this;
}
Matrix Matrix:: operator *(float a) {  //rows строки

	Matrix tmp(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			tmp.M[i][j] = a * this->M[i][j];
		}
	}
	return tmp;




}



Matrix Matrix:: operator *(const Matrix& other) {


	try {
		if (this->cols != other.rows) {
			throw 1;

		}
		else {

			Matrix tmp(this->rows, other.cols);

			for (int i = 0; i < this->rows; i++)
			{
				for (int j = 0; j < other.cols; j++)
				{
					tmp.M[i][j] = 0;
					for (int k = 0; k < this->cols; k++) {
						tmp.M[i][j] += this->M[i][k] * other.M[k][j];
					}
				}
			}
			this->change(this->rows, other.cols);
			return tmp;

		}
	}
	catch (int) {
		cout << "we cant mult matix" << endl;

	}

}
Matrix Matrix:: operator -(const Matrix& other)// перегрузка оператора + 
{

	try {
		if (this->rows != other.rows || this->cols != other.cols) {
			throw 1;
		}
		else {

			Matrix tmp(rows, cols);

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					tmp.M[i][j] = this->M[i][j] - other.M[i][j];
				}
			}
			return tmp;
		}
	}
	catch (int) {
		cout << "We cant minus matix";

	}
}
Matrix Matrix:: operator -(float a) {// перегрузка оператора + 
	Matrix tmp(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			tmp.M[i][j] = this->M[i][j] - a;
		}
	}
	return tmp;
}
Matrix Matrix:: operator +(float a) {// перегрузка оператора + 
	Matrix tmp(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			tmp.M[i][j] = this->M[i][j] + a;
		}
	}
	return tmp;
}
Matrix Matrix:: operator +(const Matrix& other)// перегрузка оператора + 
{
	try {
		if (this->rows != other.rows || this->cols != other.cols) {
			throw 1;
		}
		else {

			Matrix tmp(rows, cols);

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					tmp.M[i][j] = this->M[i][j] + other.M[i][j];
				}
			}
			return tmp;
		}
	}
	catch (int) {
		cout << "We cant plus matix";
	}
}
float& Matrix:: operator()(int m, int n)//перегрузка круглых скобок для матрицы.
{                             // Если m - матрица, то m(i,j) будет
	return (M[m][n]);  //означать i,j-тый элемент матрицы
}
Matrix::Matrix()
{
	cols = rows = 0;
	M = nullptr;
}
Matrix::Matrix(int _m, int _n)
{
	rows = _m;
	cols = _n;

	M = new float* [rows];  //конструктор создает двумерный динамический массив
	for (int i = 0; i < rows; i++) M[i] = new float[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			M[i][j] = 0;
	}

}



void Matrix::change(int n, int m) {
	rows = n;
	cols = m;

	delete[] M;
	M = new float* [rows];  //конструктор создает двумерный динамический массив
	for (int i = 0; i < rows; i++) M[i] = new float[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			M[i][j] = 0;
	}
}
float Matrix::GetElement(int i, int j)
{
	if ((rows > 0) && (cols > 0))
		return M[i][j];
	else
		return 0;
}
int Matrix::getRows() {
	return(rows);
}
int Matrix::getCols() {
	return(cols);
}
Matrix Matrix::adamarMult(const Matrix& a, const Matrix& b) {

	try {
		if (a.cols != b.cols || a.rows != b.cols) {
			throw 1;

		}
		else {

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					this->M[i][j] = a.M[i][j] * b.M[i][j];
				}
			}
			return *this;
		}
	}
	catch (...) {
		cout << "We cannot use proizvedenie adamara";


	}
}
void Matrix::Print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << M[i][j] << "  ";
		cout << endl;

	}

}
void Matrix::SetElement(int i, int j, float value)
{
	if ((i < 0) || (i >= rows))
		return;
	if ((j < 0) || (j >= cols))
		return;
	M[i][j] = value;
}
ostream& operator<<(ostream& out, Matrix& name) {


	for (int i = 0; i < name.getRows(); i++)
	{
		for (int j = 0; j < name.getCols(); j++)
			out << name(i, j) << "\t";
		out << endl;
	}
	return(out);
}
istream& operator>>(istream& in, Matrix& name) // перегрузка оператора ввода матрицы
{
	for (int i = 0; i < name.getRows(); i++)
		for (int j = 0; j < name.getRows(); j++)
			in >> name(i, j);
	return(in);
}





eMatrix::eMatrix() {
	cols = rows = 0;
	M = nullptr;

}
eMatrix::eMatrix(int _n) {
	rows = _n;
	cols = _n;
	M = new float* [rows];  //конструктор создает двумерный динамический массив
	for (int i = 0; i < rows; i++) M[i] = new float[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			M[i][j] = 0;
	}
	for (int i = 0; i < rows; i++)
	{
		M[i][i] = 1;
	}


}


dMatrix::dMatrix() {
	cols = rows = 0;
	M = nullptr;

}
dMatrix::dMatrix(int _n) {
	rows = _n;
	cols = _n;
	M = new float* [rows];  //конструктор создает двумерный динамический массив
	for (int i = 0; i < rows; i++) M[i] = new float[cols];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			M[i][j] = 0;
	}
	for (int i = 0; i < rows; i++) {
		SetElement(i, i, i + 1);

	}

}
void dMatrix::dSetElement() {
	float buf;
	for (int i = 0; i < rows; i++) {
		cin >> buf;
		SetElement(i, i, i + 1);

	}





}

tMatrix::tMatrix() {
	cols = rows = 0;
	M = nullptr;
	bool a = true;
}
tMatrix::tMatrix(int _n, bool _a) {
	rows = _n;
	cols = _n;
	bool a = _a;
	M = new float* [rows];  //конструктор создает двумерный динамический массив
	for (int i = 0; i < rows; i++) M[i] = new float[cols];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			M[i][j] = 0;
	}
	if (a == true) {

		int s = -1;
		for (int i = 0; i < rows; i++) {
			s++;
			for (int j = s; j < cols; j++) {
				SetElement(i, j, 1);
			}
		}
	}
	else {
		int s = 0;
		for (int i = 0; i < rows; i++) {
			s++;
			for (int j = 0; j < s; j++) {
				SetElement(i, j, 1);
			}
		}
	}
}
void tMatrix::tSetElement(bool _a) {
	int s = -1;
	float buf;
	for (int i = 0; i < rows; i++) {
		s++;
		for (int j = s; j < cols; j++) {
			cin >> buf;
			SetElement(i, j, buf);


		}


	}
}




sMatrix::sMatrix() {
	cols = rows = 0;
	M = nullptr;
}
sMatrix::sMatrix(int _n) {
	rows = _n;
	cols = _n;

	M = new float* [rows];  //конструктор создает двумерный динамический массив
	for (int i = 0; i < rows; i++) M[i] = new float[cols];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			SetElement(i, j, i + 1);
			SetElement(j, i, i + 1);
		}
	}


}


//Лабораторная работа 2
float Matrix::Trace() {
	try {
		if (rows != cols) {
			throw 1;
		}
		else {
			float buf = 0;
			for (int i = 0; i < rows; i++) {
				buf += GetElement(i, i);
			}
			return buf;
		}
	}
	catch (...) {
		cout << "we cant find trace" << endl;

	}
}
float Matrix::Det() {
	try {
		float** N;

		N = new float* [rows];  //конструктор создает двумерный динамический массив
		for (int i = 0; i < rows; i++) N[i] = new float[cols];

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				N[i][j] = M[i][j];
		}



		int n = rows;
		const double EPS = 1E-9;

		double det = 1;
		for (int i = 0; i < n; ++i) {
			int k = i;
			for (int j = i + 1; j < n; ++j)
				if (abs(N[j][i]) > abs(N[k][i]))
					k = j;
			if (abs(N[k][i]) < EPS) {
				det = 0;
				break;
				throw 1;
			}
			swap(N[i], N[k]);
			if (i != k)
				det = -det;
			det *= N[i][i];
			for (int j = i + 1; j < n; ++j)
				N[i][j] /= N[i][i];
			for (int j = 0; j < n; ++j)
				if (j != i && abs(N[j][i]) > EPS)
					for (int k = i + 1; k < n; ++k)
						N[j][k] -= N[i][k] * N[j][i];
		}

		return det;
	}
	catch (...) {
		cout << "opredelitely net";

	}
}
float Matrix::VNorm() {

	float s = 0;

	if (cols == 1) {
		for (int i = 0; i < rows; i++) {
			s += M[i][0] * M[i][0];

		}
		s = sqrt(s);
		return s;
	}
	else if (rows == 1) {
		for (int i = 0; i < cols; i++) {
			s += M[0][i] * M[0][i];

		}
		s = sqrt(s);
		return s;
	}


}
float Matrix::Norm() {

	float s = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			s += M[i][j] * M[i][j];
		}
	}
	s = sqrt(s);
	return s;

}
float Scalar(Matrix& a, Matrix& b) {

	float s = 0;

	if (((a.getCols() == 1 || a.getRows() == 1)) && ((b.getCols() == 1 || b.getRows() == 1))) {

		if (a.getRows() == 1 && b.getRows() == 1) {
			for (int i = 0; i < a.getCols(); i++) {

				s += a.GetElement(0, i) * b.GetElement(0, i);


			}


			return s;
		}
		else if (a.getCols() == 1 && b.getCols() == 1) {
			for (int i = 0; i < a.getRows(); i++) {

				s += a.GetElement(i, 0) * b.GetElement(i, 0);

			}


			return s;
		}
		else if (a.getCols() == 1 && b.getRows() == 1) {
			for (int i = 0; i < a.getRows(); i++) {

				s += a.GetElement(i, 0) * b.GetElement(0, i);

			}


			return s;
		}
		else if (a.getRows() == 1 && b.getCols() == 1) {
			for (int i = 0; i < a.getCols(); i++) {

				s += a.GetElement(0, i) * b.GetElement(i, 0);

			}


			return s;
		}
	}

}

//Лабораторная работа 3
float  angle(Matrix& a, Matrix& b) {

	float s = 0;

	s = (Scalar(a, b) / (a.Norm() * b.Norm()));
	s = acos(s);
	return s;
}
float Matrix::rank() {

	const double EPS = 1E-9;

	int rank = max(rows, cols);
	vector<char> line_used(rows);
	for (int i = 0; i < rows; ++i) {
		int j;
		for (j = 0; j < cols; ++j)
			if (!line_used[j] && abs(M[j][i]) > EPS)
				break;
		if (j == cols)
			--rank;
		else {
			line_used[j] = true;
			for (int p = i + 1; p < rows; ++p)
				M[j][p] /= M[j][i];
			for (int k = 0; k < cols; ++k)
				if (k != j && abs(M[k][i]) > EPS)
					for (int p = i + 1; p < rows; ++p)
						M[k][p] -= M[j][p] * M[k][i];
		}
	}


	return rank;
}
void Matrix::transpose() {

	int temp;
	for (int i = 0; i < rows; ++i) {
		for (int j = i; j < cols; ++j)
		{
			temp = M[i][j];
			M[i][j] = M[j][i];
			M[j][i] = temp;
		}
	}
}
void Matrix::inverse() {

	try {

		if (this->Det() == 0) {


			throw 1;
		}
		else {



			float temp;
			int N = rows;
			float** E = new float* [N];

			for (int i = 0; i < N; i++)
				E[i] = new float[N];

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
				{
					E[i][j] = 0.0;

					if (i == j)
						E[i][j] = 1.0;
				}

			for (int k = 0; k < N; k++)
			{
				temp = M[k][k];

				for (int j = 0; j < N; j++)
				{
					M[k][j] /= temp;
					E[k][j] /= temp;
				}

				for (int i = k + 1; i < N; i++)
				{
					temp = M[i][k];

					for (int j = 0; j < N; j++)
					{
						M[i][j] -= M[k][j] * temp;
						E[i][j] -= E[k][j] * temp;
					}
				}
			}

			for (int k = N - 1; k > 0; k--)
			{
				for (int i = k - 1; i >= 0; i--)
				{
					temp = M[i][k];

					for (int j = 0; j < N; j++)
					{
						M[i][j] -= M[k][j] * temp;
						E[i][j] -= E[k][j] * temp;
					}
				}
			}

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					M[i][j] = E[i][j];

		}
	}
	catch (...) {
		cout << "Obratniy matrici net" << endl;
	}

}

//Лабораторная работа 4
void Matrix::writeBin() {

	fstream f;
	f.open("matrix.bin", ios::out);
	int i = 0;
	int j = 0;
	for (i = 0; i < rows - 1; i++)
	{
		for (j = 0; j < cols - 1; j++) {
			f << M[i][j] << " ";
		}
		f << M[i][j] << "\n";

	}
	//i++;
	j = 0;
	for (j = 0; j < cols - 1; j++) {
		f << M[i][j] << " ";
	}
	f << M[i][j] << ";";

	f.close();
}
void Matrix::readBin() {
	fstream f;

	f.open("matrix.bin", ios::in);

	float buf;
	int n = 1;
	int m = 0;

	while (1) {
		if (f.peek() == '\n') {

			//cout << "\n";
			n++;
		}

		if (f.peek() == ';') {
			//cout << "break";
			break;
		}
		f >> buf;
		//cout << buf << " ";
		m++;
	}

	m = m / n;

	change(n, m);
	f.seekg(0, ios::beg);

	int i = 0; //n
	int j = 0; //m



	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			f >> M[i][j];
		}
	}






	//cout << "n = " << n << endl;
	//cout << "m = " << m << endl;
	f.close();
}
ostream& operator<<(fstream& f, Matrix& name) {

	try {
		if (f.tellg() == 0) {

			throw 1;
		}
		else {


			float buf;
			int n = 1;
			int m = 0;

			while (1) {

				if (f.peek() == '\n') {

					//cout << "\n";
					n++;
				}

				if (f.peek() == ';') {
					//cout << "break";
					break;
				}
				f >> buf;
				//cout << buf << " ";
				m++;
			}

			m = m / n;

			name.change(n, m);
			f.seekg(0, ios::beg);

			int i = 0; //n
			int j = 0; //m



			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					f >> name.M[i][j];
				}
			}





			return f;
		}
	}
	catch (...) {
		cout << "File is empty";

	}



}
istream& operator>>(fstream& f, Matrix& name) {


	int i = 0;
	int j = 0;
	for (i = 0; i < name.rows - 1; i++)
	{
		for (j = 0; j < name.cols - 1; j++) {
			f << name.M[i][j] << " ";
		}
		f << name.M[i][j] << "\n";

	}
	//i++;
	j = 0;
	for (j = 0; j < name.cols - 1; j++) {
		f << name.M[i][j] << " ";
	}
	f << name.M[i][j] << ";";
	return f;
}
#pragma once