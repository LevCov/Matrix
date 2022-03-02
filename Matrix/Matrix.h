#pragma once
using namespace std;

class Matrix
{
protected:
	float** M;
	int rows; // количество строк
	int cols; // количество столбцов

public:


	Matrix(); //конструктор по умолчанию
	Matrix(int _m, int _n); // конструктор с параметрами

	//Лабораторная работа 1
	void change(int n, int m); // изменение количества строк и столбцов
	int getRows(); // получение значения строк
	int getCols(); // получение значения столбцов
	float GetElement(int i, int j); // получение значения элемента
	void SetElement(int i, int j, float value); //изменение значения элемента
	void Print();
	Matrix adamarMult(const Matrix& a, const Matrix& b);
	Matrix operator +(const Matrix& other);// перегрузка оператора + 
	Matrix operator +(float a);//
	Matrix operator -(const Matrix& other);// перегрузка оператора + 
	Matrix operator -(float a);//
	Matrix operator *(const Matrix& other);// перегрузка оператора *
	Matrix operator *(float a);//
	Matrix operator =(const Matrix& other);// перегрузка оператора = 
	friend ostream& operator<< (std::ostream& out, Matrix& name);
	friend istream& operator>>(istream& in, Matrix& name);
	float& operator()(int m, int n);//перегрузка круглых скобок для матрицы.



	//Лабораторная работа 2
	float Trace(); // след
	float Det(); // определитель
	float VNorm(); // норма вектора, обычная норма заменяет ее
	float Norm();  // норма матрицы
	friend float Scalar(Matrix& a, Matrix& b);
	//Лабораторная работа 3
	float rank(); // ранг
	void inverse(); // обратная матрица
	void transpose(); // транспонированная матрица
	friend float angle(Matrix& a, Matrix& b); // угол между векторами
	//Лабораторная работа 4
	void writeBin();
	void readBin();
	friend ostream& operator<< (fstream& f, Matrix& name);
	friend istream& operator>>(fstream& f, Matrix& name);



};





class eMatrix :public Matrix {
public:

	eMatrix();
	using Matrix :: operator =;
	eMatrix(int _n);

};




class dMatrix : public Matrix {
public:

	dMatrix();
	dMatrix(int _n);
	void dSetElement();
};



class tMatrix : public Matrix {
public:
	bool a = true;
	tMatrix();
	tMatrix(int _n, bool _a);
	void tSetElement(bool _a);
};

class sMatrix : public Matrix {
public:

	sMatrix();
	sMatrix(int _n);

};

















/*Matrix a(2, 2);
	int buf;
	for (int i = 0; i < m;i++){
		for (int j = 0; j < n; j++) {
			cout << "Введите значение ->";
			cin >> buf;
			a.SetElement(i, j, buf);

		}

	}*/
#include "Matrix.cpp"
