#pragma once
using namespace std;

class Matrix
{
protected:
	float** M;
	int rows; // ���������� �����
	int cols; // ���������� ��������

public:


	Matrix(); //����������� �� ���������
	Matrix(int _m, int _n); // ����������� � �����������

	//������������ ������ 1
	void change(int n, int m); // ��������� ���������� ����� � ��������
	int getRows(); // ��������� �������� �����
	int getCols(); // ��������� �������� ��������
	float GetElement(int i, int j); // ��������� �������� ��������
	void SetElement(int i, int j, float value); //��������� �������� ��������
	void Print();
	Matrix adamarMult(const Matrix& a, const Matrix& b);
	Matrix operator +(const Matrix& other);// ���������� ��������� + 
	Matrix operator +(float a);//
	Matrix operator -(const Matrix& other);// ���������� ��������� + 
	Matrix operator -(float a);//
	Matrix operator *(const Matrix& other);// ���������� ��������� *
	Matrix operator *(float a);//
	Matrix operator =(const Matrix& other);// ���������� ��������� = 
	friend ostream& operator<< (std::ostream& out, Matrix& name);
	friend istream& operator>>(istream& in, Matrix& name);
	float& operator()(int m, int n);//���������� ������� ������ ��� �������.



	//������������ ������ 2
	float Trace(); // ����
	float Det(); // ������������
	float VNorm(); // ����� �������, ������� ����� �������� ��
	float Norm();  // ����� �������
	friend float Scalar(Matrix& a, Matrix& b);
	//������������ ������ 3
	float rank(); // ����
	void inverse(); // �������� �������
	void transpose(); // ����������������� �������
	friend float angle(Matrix& a, Matrix& b); // ���� ����� ���������
	//������������ ������ 4
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
			cout << "������� �������� ->";
			cin >> buf;
			a.SetElement(i, j, buf);

		}

	}*/
#include "Matrix.cpp"
