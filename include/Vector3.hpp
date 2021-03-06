#pragma once
#include <cassert>
#include <cmath>

namespace CommonUtilities
{
	template<class T>
	class Vector3
	{
	public:
		T x, y, z;

		//Creates a null-vector
		Vector3<T>();

		//Creates a vector (aX, aY, aZ)
		Vector3<T>(const T& aX, const T& aY, const T& aZ);

		//Copy constructor (compiler generated)
		Vector3<T>(const Vector3<T>& aVector) = default;

		//Assignment operator (compiler generated)
		Vector3<T>& operator=(const Vector3<T>& aVector3) = default;

		//Destructor (compiler generated)
		~Vector3<T>() = default;

		//Returns the squared length of the vector
		T LengthSqr() const;

		//Returns the length of the vector
		T Length() const;

		//Returns a normalized copy of this
		Vector3<T> GetNormalized() const;

		//Normalizes the vector
		void Normalize();

		//Returns the dot product of this and aVector
		T Dot(const Vector3<T>& aVector) const;

		//Returns the cross product of this and aVector
		Vector3<T> Cross(const Vector3<T>& aVector) const;
	};

	template<class T>
	CommonUtilities::Vector3<T>::Vector3()
	{
		x = T();
		y = T();
		z = T();
	}

	template<class T>
	CommonUtilities::Vector3<T>::Vector3(const T& aX, const T& aY, const T& aZ)
	{
		x = aX;
		y = aY;
		z = aZ;
	}

	template<class T>
	CommonUtilities::Vector3<T> CommonUtilities::Vector3<T>::Cross(const Vector3<T>& aVector) const
	{
		return { y * aVector.z - z * aVector.y,
				 z * aVector.x - x * aVector.z,
				 x * aVector.y - y * aVector.x};
	}

	template<class T>
	T CommonUtilities::Vector3<T>::Dot(const Vector3<T>& aVector) const
	{
		return x * aVector.x + y * aVector.y + z * aVector.z;
	}

	template<class T>
	void CommonUtilities::Vector3<T>::Normalize()
	{
		if (Length() == 0)
		{
			assert(L"Error! length is zero");
		}
		else
		{
			T temp = 1 / Length();
			x = x * temp;
			y = y * temp;
			z = z * temp;
		}
	}

	template<class T>
	CommonUtilities::Vector3<T> CommonUtilities::Vector3<T>::GetNormalized() const
	{
		Vector3 tempVector3 = { x, y, z};
		tempVector3.Normalize();

		return tempVector3;
	}

	template<class T>
	T CommonUtilities::Vector3<T>::Length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	template<class T>
	T CommonUtilities::Vector3<T>::LengthSqr() const
	{
		return x * x + y * y + z * z;
	}

	//Returns the vector sum of aVector0 and aVector1
	template <class T> Vector3<T> operator+(const Vector3<T>& aVector0, const Vector3<T>& aVector1) { return { aVector0.x + aVector1.x, aVector0.y + aVector1.y, aVector0.z + aVector1.z }; }

	//Returns the vector difference of aVector0 and aVector1
	template <class T> Vector3<T> operator-(const Vector3<T>& aVector0, const Vector3<T>& aVector1) { return { aVector0.x - aVector1.x, aVector0.y - aVector1.y, aVector0.z - aVector1.z }; }

	//Returns the vector aVector multiplied by the scalar aScalar
	template <class T> Vector3<T> operator*(const Vector3<T>& aVector, const T& aScalar) { return { aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar }; }

	//Returns the vector aVector multiplied by the scalar aScalar
	template <class T> Vector3<T> operator*(const T& aScalar, const Vector3<T>& aVector) { return { aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar }; }

	//Returns the vector aVector divided by the scalar aScalar (equivalent to aVector multiplied by 1 / aScalar)
	template <class T> Vector3<T> operator/(const Vector3<T>& aVector, const T& aScalar) 
	{ 
		if (aScalar == 0)
		{
			assert(L"Error! Scalar is zero");
		}
		return { aVector.x / aScalar, aVector.y / aScalar, aVector.z / aScalar }; 
	}

	//Equivalent to setting aVector0 to (aVector0 + aVector1)
	template <class T> void operator+=(Vector3<T>& aVector0, const Vector3<T>& aVector1) { aVector0 = { aVector0.x + aVector1.x, aVector0.y + aVector1.y, aVector0.z + aVector1.z }; }

	//Equivalent to setting aVector0 to (aVector0 - aVector1)
	template <class T> void operator-=(Vector3<T>& aVector0, const Vector3<T>& aVector1) { aVector0 = { aVector0.x - aVector1.x, aVector0.y - aVector1.y, aVector0.z - aVector1.z }; }

	//Equivalent to setting aVector to (aVector * aScalar)
	template <class T> void operator*=(Vector3<T>& aVector, const T& aScalar) { aVector = { aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar }; }

	//Equivalent to setting aVector to (aVector / aScalar)
	template <class T> void operator/=(Vector3<T>& aVector, const T& aScalar) { aVector = { aVector.x / aScalar, aVector.y / aScalar, aVector.z / aScalar }; }

	template <class T> bool operator==(Vector3<T>& aVector, Vector3<T>& aVector2) { return (aVector.x == aVector2.x) && (aVector.y == aVector2.y) && (aVector.z == aVector2.z); };
}