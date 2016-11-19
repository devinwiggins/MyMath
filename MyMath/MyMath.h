#pragma once

#include <iostream>
#include <math.h>
#include <cassert>
#include <fstream>
#include <iomanip>

using namespace std;

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

class Matrix2x2
{

	float m_Matrix[4]; // Container of Vector2's
public:
	Matrix2x2() {}
	Matrix2x2(float x1, float x2, float y1, float y2); // constructor of a matrix2x2 made up of 4 floats
	Matrix2x2(Vector2 columnA, Vector2 columnB); // constructor of a Matrix2x2 made up of Vector2s
	Matrix2x2 operator * (Matrix2x2 k); // overloaded multiplication for matrix times a matrix
	Matrix2x2 Mult(Matrix2x2 k); // returns the product of matrix 2x2s
	Vector2 operator * (Vector2 k); // overloaded multiplication for Matrix times a Vector
	Vector2 Mult(Vector2 k); // returns the product of a Matrix2x2 and a Vector2
	bool operator == (Matrix2x2 & result); // overloaded = operator to compare Vectors
	friend ofstream& operator << (ofstream & output, Matrix2x2 &n); // prints matrix to file
	
};

class Matrix3x3
{
	float m_Matrix[9]; // Container of Matrix3x3 values
public:
	Matrix3x3() {}
	Matrix3x3(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3); // constructor of a Matrix3x3 made up of 9 floats
	Matrix3x3(Vector3 columnA, Vector3 columnB, Vector3 columnC); // constructor of a Matrix3x3 made up of Vector3s
	Matrix3x3 operator * (Matrix3x3 k); // overloaded multiplication for matrix times a matrix
	Matrix3x3 Mult(Matrix3x3 k); // returns the product of matrix3x3s
	Vector3 operator * (Vector3 k); // overloaded multiplication for Matrix times a Vector
	Vector3 Mult(Vector3 k); // returns the product of a Matrix3x3 and a Vector3
	bool operator == (Matrix3x3 & result); // overloaded = operator to compare Vectors
	Matrix3x3 RotateX(float d); // rotates in respect to X axis
	Matrix3x3 RotateY(float d); // rotates in respect to Y axis
	Matrix3x3 RotateZ(float d); // rotates in respect to z axis
	friend ofstream& operator << (ofstream & output, Matrix3x3 &n); //prints matrix to file

};

class Matrix4x4
{
	float m_Matrix[16];
public:
	Matrix4x4(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4); // constructor of a matrix4x4 made up of 16 floats
	Matrix4x4(Vector4 columnA, Vector4 columnB, Vector4 columnC, Vector4 columnD); // constructor of a Matrix4x4 made up of Vector4s
	Matrix4x4 operator * (Matrix4x4 k); // overloaded multiplication for matrix times a matrix
	Matrix4x4 Mult(Matrix4x4 k); // returns the product of matrix 4x4s
	Vector4 operator * (Vector4 k); // overloaded multiplication for Matrix times a Vector
	Vector4 Mult(Vector4 k); // returns the product of a Matrix4x4 and a Vector4
	bool operator == (Matrix4x4 & result); // overloaded = operator to compare Vectors
	Matrix4x4 RotateX(float d); // rotates in respect to x axis
	Matrix4x4 RotateY(float d); // rotates in respect to y axis
	Matrix4x4 RotateZ(float d); // rotates in respect to z axis
	friend ofstream& operator << (ofstream & output, Matrix4x4 &n); // prints matrix to file
};

float setDecLimit(float value, unsigned int decimals);