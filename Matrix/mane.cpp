#include<iostream>
using namespace std;

class Matrix;
Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const Matrix& right);


class Matrix
{
	int rows;
	int cols;
	int** arr;

public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	//				Constructors:
	
	Matrix(int rows = 2, int cols = 2)
	{
		this->rows = rows;
		this->cols = cols;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols] {};
		}
		cout << "Constructor:\t" << this << endl;
	}
	
	Matrix(const Matrix& other)//:Matrix(other.rows, other.cols)
	{
	/*	for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->arr[i][j] = other.arr[i][j];
			}
		}*/
		*this = other;
		cout << "CopyConstructor:\t" << this << endl;
	}
	Matrix(Matrix&& other)
	{
		/*this->rows = other.rows;
		this->cols = other.cols;
		this->arr = other.arr;
		cout << "MoveConstructor:\t" << this << endl;
		other.arr = nullptr;
		other.rows = 0;
		other.cols = 0;*/

		*this = std::move(other);
	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]arr[i];
		}
		delete[]arr;
		arr = nullptr;
		rows = 0;
		cols = 0;
		cout << "Destructor:\t" << this << endl;
	}
	//                       Operators
	Matrix& operator=(const Matrix& other)
	{
		if (this == &other)return *this;
		this->~Matrix();
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			this->arr[i] = new int[cols] {};
			memcpy(this->arr[i], other.arr[i], cols * sizeof(int));
		}
		cout << "CopyAssigment:\t" <<this<< endl;
		return *this;
	}
	
	const int* operator[](int i)const
	{
		return arr[i];
	}
	int* operator[](int i)
	{
		return arr[i];
	}
	Matrix& operator=(Matrix&& other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = other.arr;
		other.arr= nullptr;
		other.cols = 0;
		other.rows = 0;
		return *this;
	}

	//Metods
	void print()const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;

		}
	}
	Matrix operator+(const Matrix& left, const Matrix right)
	{
		Matrix result(left.get.rows(), left.get_cols());
		for (int i = 0; i < left.get.rows(); i++)
		{
			for (int j = 0; j < left.get.cols(); j++)
			{
				result[i][j] = left[i][j] + right[i][j];
			}
		}
		return result;
	};
	Matrix operator-(const Matrix& left, const Matrix& right)
	{
		Matrix result(left.get.rows(), left.get_cols());

		for (int i = 0; i < left.get.rows(); i++)
		{
			for (int j = 0; j < left.get.cols(); j++)
			{
				result[i][j] = left[i][j] - right[i][j];
			}
		}
		return result;
	}
	Matrix operator*(const Matrix& left, const Matrix& right)
	{
		Matrix result(left.get.rows(), left.get_cols());
		
			for (int i = 0; i < left.get.rows(); i++)
			{
				for (int j = 0; j < left.get.cols(); j++)
				{
					result[i][j] = left[i][j] * right[i][j];
				}
			}
			return result;
	}
	
};

void main()
{
	setlocale(LC_ALL, "Russin");
	Matrix A(3, 4);
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			A[i][j] = rand() % 100;
		}
	}
	A = A;
	A.print();
	Matrix B;
	B = A;//Copy Constructor
	B.print();
	Matrix C;
	C = A + B;
	C.print();
	Matrix D;
	D = C - B;
	D.print();
	Matrix E;
	E = D * A;
	E.print();
}