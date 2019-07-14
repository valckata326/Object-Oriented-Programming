#pragma once

template <class T>
class Matrix {
	T** matrix = nullptr;
	unsigned int rows;
	unsigned int cols;
	void setRows(unsigned int new_rows);
	void setCols(unsigned int new_cols);

	
public:
	Matrix();
	Matrix(unsigned int new_rows, unsigned int new_cols);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);

	void setAt(unsigned int x, unsigned int y, T element);
	T getAt(unsigned int x, unsigned int y) const;

	void transpose();
	void print() const;
	unsigned int getRows();
	unsigned int getCols();
};

template<class T>
inline void Matrix<T>::setRows(unsigned int rows)
{
	this->rows = rows;
}

template<class T>
inline void Matrix<T>::setCols(unsigned int cols)
{
	this->cols = cols;
}

template<class T>
inline unsigned int Matrix<T>::getRows()
{
	return this->rows;
}

template<class T>
inline unsigned int Matrix<T>::getCols()
{
	return this->cols;
}

template<class T>
inline Matrix<T>::Matrix()
{
	setRows(2);
	setCols(2);
	matrix = new T*[getRows()];
	for (size_t i = 0; i < getRows(); i++)
	{
		matrix[i] = new T[getCols()];
	}
	for (size_t i = 0; i < getRows(); i++)
	{
		for (size_t j = 0; j < getCols(); j++)
		{
			matrix[i][j] = T();
		}
	}
}

template<class T>
inline Matrix<T>::Matrix(unsigned int new_rows, unsigned int new_cols)
{
	setRows(new_rows);
	setCols(new_cols);
	matrix = new T*[getRows()];
	for (size_t i = 0; i < getRows(); i++)
	{
		matrix[i] = new T[getCols()];
	}
	for (size_t i = 0; i < getRows(); i++)
	{
		for (size_t j = 0; j < getCols(); j++)
		{
			matrix[i][j] = T();
		}
	}
}

template<class T>
inline Matrix<T>::Matrix(const Matrix & other)
{
	*this = other;
}

template<class T>
inline Matrix<T>::~Matrix()
{
	if (matrix != nullptr)
	{
		for (size_t i = 0; i < getRows(); i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	
}

template<class T>
inline Matrix<T> & Matrix<T>::operator=(const Matrix & other)
{
	if (this != other)
	{
		if (matrix != nullptr)
		{
			for (size_t i = 0; i < getRows(); i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		setRows(other.getRows());
		setCols(other.getCols());
		matrix = new T*[getRows()];
		for (size_t i = 0; i < getRows(); i++)
		{
			matrix[i] = new T[getCols()];
		}
		for (size_t i = 0; i < getRows(); i++)
		{
			for (size_t j = 0; j < getCols(); j++)
			{
				matrix[i][j] = other.matrix[i][j];
			}
		}
	}
	return *this;
}

template<class T>
inline void Matrix<T>::setAt(unsigned int x, unsigned int y, T element)
{
	if (x > 0 && x <= getRows() && y > 0 && y <= getCols())
	{
		matrix[x - 1][y - 1] = element;
	}
}

template<class T>
inline T Matrix<T>::getAt(unsigned int x, unsigned int y) const
{
	if(x > 0 && x <= getRows() && y > 0 && y < getCols())
	return matrix[x - 1][y - 1];
}

template<class T>
inline void Matrix<T>::transpose()
{
	T** copy_matrix = new T*[rows];
	for (size_t i = 0; i < rows; i++)
	{
		copy_matrix[i] = new T[cols];
	}
	for (size_t i = 0; i < getRows(); i++)
	{
		for (size_t j = 0; j < getCols(); j++)
		{
			copy_matrix[i][j] = matrix[i][j];
		}
	}
	if (matrix != nullptr)
	{
		for (size_t i = 0; i < getRows(); i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
	}
	matrix = new T*[cols];
	for (size_t i = 0; i < cols; i++)
	{
		matrix[i] = new T[rows];
	}
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[j][i] = copy_matrix[i][j];
		}
	}
	unsigned int temp = rows;
	rows = cols;
	cols = temp;
}

template<class T>
inline void Matrix<T>::print() const
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
