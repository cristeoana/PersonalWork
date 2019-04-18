#pragma once
#include "Song.h"

template <typename T>
class DynamicVector
{
public:
	DynamicVector() 
	{
		this->trailersArray = new T[16];
		this->size = 0;
		this->capacity = 16;
	};
	DynamicVector(int capacity)
	{
		this->size = 0;
		this->capacity = capacity;
		trailersArray = new T[capacity];
	}
	DynamicVector(const T &cpyVect)
	{
		//copy constructor
		this->capacity = cpyVect.capacity;
		this->size = cpyVect.size;
		this->trailersArray = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->trailersArray[i] = cpyVect.trailersArray[i];
		}
	}
	~DynamicVector()
	{
		//for (int i = 0; i < this->size; i++)
		//	delete this->trailersArray[i];
		//delete this->trailersArray;
	}
	void deletee(){ delete[] this->trailersArray; }
	void Resize()
	{
		this->capacity *= 2;
		T* newArray = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			newArray[i] = this->trailersArray[i];
		}
		delete[] this->trailersArray;
		this->trailersArray = newArray;
		newArray = NULL;
	}
	void AddTrailer(const T& trailerToAdd)
	{
		//used to add a trailer in the playlist
		//input: trailerToAdd
		if (this->size+1 >= this->capacity)
		{
			this->Resize();
		}
		this->size += 1;
		this->trailersArray[this->size - 1] = trailerToAdd;
	}
	void DeleteTrailer(T trailerToDelete)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->trailersArray[i].getTitle().compare(trailerToDelete.getTitle())==0 && this->trailersArray[i].getGenre().compare(trailerToDelete.getGenre()) == 0)
			{
				for (int j = i; j < this->size-1; j++)
				{
					this->trailersArray[j] = this->trailersArray[j + 1];
				}
				break;
			}
		}
		this->size -= 1;
	}
	void UpdateTrailer(const T oldtrailer , T newtrailer)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->trailersArray[i] == oldtrailer)
			{
				this->trailersArray[i] = newtrailer;
			}
		}
	}
	T& operator[](int index)
	{
		return trailersArray[index];
	}
	int GetSize()
	{
		return this->size;
	}
	int GetCapacity()
	{
		return this->capacity;
	}
	DynamicVector& operator =(const DynamicVector& vect)
	{
		this->capacity = vect.capacity;
		this->size = vect.size;
		delete[] this->trailersArray;
		this->trailersArray = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->trailersArray[i] = vect.trailersArray[i];
		}
		return *this;
	}
	T operator+(T elem)
	{
		if (this->size + 1 >= this->capacity)
		{
			this->Resize();
		}
		this->size += 1;
		this->trailersArray[this->size - 1] = elem;
		return *this;
	}
	T operator-(T trailerToDelete)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->trailersArray[i] == trailerToDelete)
			{
				for (int j = i; j < this->size - 1; j++)
				{
					this->trailersArray[j] = this->trailersArray[j + 1];
				}
				break;
			}
		}
		this->size -= 1;
		return *this;
	}
	T GetByTitle(std::string title)
	{
		for (int i = 0; i < this->size; i++)
		{
			//find partial string
			if (this->trailersArray[i].getTitle() == title)
			{
				return this->trailersArray[i];
				break;
			}
		}
		T trailer;
		return trailer;
	}
private:
	T *trailersArray;
	int capacity;
	int size;
};