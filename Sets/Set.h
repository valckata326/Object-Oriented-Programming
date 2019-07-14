#pragma once
template <class T>

class Set {
	T* array_ofThings = nullptr;
	int size_ofarray;
	int if_there(const T& thing);
	void setSize(int new_size);
public:
	Set();
	Set(const Set& other);
	~Set();
	Set<T>& operator=(const Set& other);

	T* getArray_ofThings() const;
	int getSize() const;

	void insert(const T& to_add);
	void erase(const T& to_delete);
	bool contains(const T& thing) const;
	int size() const;
	T& operator[](int index) const;
	Set<T>& union1(const Set& other);
	Set<T>& intersection(const Set& other); 
	Set<T>& clone() const;

	void print() const;

};

template<class T>
inline int Set<T>::if_there(const T & thing)
{
	for (int index = 0; index < getSize(); index++)
	{
		if (array_ofThings[index] = thing)
		{
			return index;
		}
	}
	return -1;
}

template<class T>
inline void Set<T>::setSize(int new_size)
{
	this->size_ofarray = new_size;
}

template<class T>
inline Set<T>::Set()  
{
	setSize(0);
	array_ofThings = new T[size()];
}

template<class T>
inline Set<T>::Set(const Set & other)
{
	setSize(other.getSize());
	this->array_ofThings = new T[getSize()];
	for (int index = 0; index < getSize(); index++)
	{
		array_ofThings[index] = other.array_ofThings[index];
	}
}

template<class T>
inline Set<T>::~Set()
{
	delete[] this->array_ofThings;
}

template<class T>
inline Set<T> & Set<T>::operator=(const Set<T> & other)
{
	if (this != &other)
	{
		delete[] this->array_ofThings;
		setSize(other.getSize());
		this->array_ofThings = new T[getSize()];
		for (int index = 0; index < getSize(); index++)
		{
			array_ofThings[index] = other.array_ofThings[index];
		}
	}
	return *this;
}

template<class T>
inline T * Set<T>::getArray_ofThings() const
{
	return this->array_ofThings;
}

template<class T>
inline int Set<T>::getSize() const
{
	return this->size_ofarray;
}

template<class T>
inline void Set<T>::insert(const T & to_add)
{
	if (contains(to_add) == false)
	{
		T* new_arr = new T[getSize() + 1];
		for (int index = 0; index < getSize(); index++)
		{
			new_arr[index] = array_ofThings[index];
		}
		new_arr[getSize()] = to_add;
		delete[] array_ofThings;
		setSize(getSize() + 1);
		array_ofThings = new_arr;
	}
}

template<class T>
inline void Set<T>::erase(const T & to_delete)
{
	if (contains(to_delete) == true)
	{
		for (int index = if_there(to_delete); index < getSize() - 1; index++)
		{
			array_ofThings[index] = array_ofThings[index + 1];
		}
		setSize(getSize() - 1);
	}
}

template<class T>
inline bool Set<T>::contains(const T & thing) const
{
	for (int index = 0; index < getSize(); index++) {
		if (array_ofThings[index] == thing)
		{
			return true;
		}
	}
	return 0;
}

template<class T>
inline int Set<T>::size() const
{
	return this->size_ofarray;
}

template<class T>
inline T & Set<T>::operator[](int index) const
{
	return array_ofThings[index];
}

template<class T>
inline Set<T>& Set<T>::union1(const Set & other)
{
	Set<T>* new_set = new Set;
	for (int index = 0; index < getSize(); index++)
	{
		new_set->insert(array_ofThings[index]);
	}
	for (int index = 0; index < other.getSize(); index++)
	{
		if (contains(other.array_ofThings[index]) == false)
		{
			new_set->insert(other.array_ofThings[index]);
		}
	}
	/*
	Set<T>* tmp = new Set<T>();
	tmp->setSize(new_size);
	for (int index = 0; index < new_size; index++)
	{
		tmp[index] = new_set[index];
	}
	delete[] tmp;
	new_set = tmp;
	new_set->setSize(new_size);*/
	return *new_set;
}

template<class T>
inline Set<T>& Set<T>::intersection(const Set & other)
{
	Set<T>* intersected = new Set;
	for (int index = 0; index < other.getSize(); index++)
	{
		if (contains(other.array_ofThings[index]) == true)
		{
			intersected->insert(other.array_ofThings[index]);
		}
	}
	return *intersected;
}

template<class T>
inline Set<T>& Set<T>::clone() const
{
	new Set<T>(*this);
}

template<class T>
inline void Set<T>::print() const
{
	std::cout << "{";
	for (int index = 0; index < getSize(); index++)
	{
		std::cout << array_ofThings[index] << ", ";
	}
	std::cout << "}" << std::endl;
}
