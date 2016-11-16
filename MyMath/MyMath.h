#pragma once

#include <iostream>
#include <math.h>
#include <cassert>

class Vector2
{
private:
	float m_x = 0.0f; // x coordinate of a Vector2 
	float m_y = 0.0f; // y coordinate of a Vector2
public:

	
	Vector2() {};
	Vector2(float x1, float y1) // constructor of a Vector2 
		: m_x(x1), m_y(y1) {}

	Vector2 Add(Vector2 B); // Adds a Vector4 instance to a Vector2 and returns a Vector2 of the sum
	Vector2 Subtract(Vector2 B); // Subtract a Vector2 instance from a Vector4 and returns a Vector2 of the difference
	Vector2 ScalerMult(float k); // returns a scaled Vector2
	float Magnitude(); // returns the Magnitude of a Vector2
	Vector2 Normalize(); // returns the Vector2, Normalized
	float DotProduct(Vector2 B); // returns dot product
	bool operator == (Vector2 &result); // overloaded == operator to compare Vectors
	float X(); // returns x coordinate value
	float Y(); // returns y coordinate value
};


class Vector3
{
	float m_x = 0.0f; // x coordinate of a Vector3
	float m_y = 0.0f; // y coordinate of a Vector3
	float m_z = 0.0f; // z coordinate of a Vector3
public:
	Vector3() {};
	Vector3(float x1, float y1, float z1)
		: m_x(x1), m_y(y1), m_z(z1) {}

	Vector3 Add(Vector3 B); // Adds a Vector4 instance to a Vector3 and returns a Vecto3 of the sum
	Vector3 Subtract(Vector3 B); // Subtract a Vector3 instance from a Vector3 and returns a Vector3 of the difference
	Vector3 ScalerMult(float k); // returns a scaled Vector4
	float Magnitude(); // returns the Magnitude of a Vector4
	Vector3 Normalize(); // returns the Vector4, Normalized
	float DotProduct(Vector3 B); // returns a Vector4
	Vector3 CrossProduct(Vector3 B); // returns the Cross Product of a vector3 instance and a Vector3
	bool operator == (Vector3 &result);  // overloaded == operator to compare Vectors
	float X(); // returns x coordinate value
	float Y(); // returns y coordinate value
	float Z(); // returns z coordinate value
};

class Vector4
{
	float m_x = 0.0f; // x coordinate of a Vector4
	float m_y = 0.0f; // y coordinate of a Vector4
	float m_z = 0.0f; // z coordinate of a Vector4
	float m_w = 0.0f; // w coordinate of a Vector4
public:
	Vector4() {};
	Vector4(float x1, float y1, float z1, float w1) 
		: m_x(x1), m_y(y1), m_z(z1), m_w(w1) {}

	Vector4 Add(Vector4 B);	// Adds a Vector4 instance to a Vector4 and returns a Vector of the sum
	Vector4 Subtract(Vector4 B); // Subtract a Vector4 instance from a Vector4 and returns a Vector4 of the difference
	Vector4 ScalerMult(float k); // returns a scaled Vector4
	float Magnitude(); // returns the Magnitude of a Vector4
	Vector4 Normalize(); // returns the Vector4, Normalized
	float DotProduct(Vector4 B); // returns a Vector4
	bool operator == (Vector4 &result); // overloaded == operator to compare Vectors
	float X(); // returns x coordinate value
	float Y(); // returns y coordinate value
	float Z(); // returns z coordinate value
	float W(); // returns w coordinate value
};

class Matrix22
{
	float m_MatShape[4]; // Container of Vector2's

public:
	Matrix22() {}
	Matrix22(float x1, float x2, float y1, float y2); 

	Matrix22(Vector2 columnA, Vector2 columnB); // constructor of a Matrix made up of
	Matrix22 operator * (Matrix22 k); // overloaded multiplication for matrix times a matrix
	Matrix22 Mult(Matrix22 k); // returns the product of matrix 2x2s
	Vector2 operator * (Vector2 k); // overloaded multiplication for Matrix times a Vector
	Vector2 Mult(Vector2 k); // returns the product of a Matrix2x2 and a Vector2
	void print(); // prints Matrix2x2 shape and values
};

class Matrix33
{
	float m_MatShape[9]; // Container of Matrix3x3 values
public:
	Matrix33() {}
	Matrix33(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3);
	Matrix33(Vector3 columnA, Vector3 columnB, Vector3 columnC); // 
	Matrix33 operator * (Matrix33 k);
	Matrix33 Mult(Matrix33 k);
	Vector3 operator * (Vector3 k);
	Vector3 Mult(Vector3 k);
	Matrix33 RotateX(float d);
	Matrix33 RotateY(float d);
	Matrix33 RotateZ(float d);
	void print();
};

class Matrix44
{
	float m_MatShape[16];
public:
	Matrix44(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4);

	Matrix44(Vector4 columnA, Vector4 columnB, Vector4 columnC, Vector4 columnD);
	Matrix44 operator * (Matrix44 k);
	Matrix44 Mult(Matrix44 k);
	Vector4 operator * (Vector4 k);
	Vector4 Mult(Vector4 k);
	Matrix44 RotateX(float d);
	Matrix44 RotateY(float d);
	Matrix44 RotateZ(float d);
	void print();

};