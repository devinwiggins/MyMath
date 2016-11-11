#pragma once

#include <iostream>
#include <math.h>
#include <cassert>

class Vector2d
{
private:
	float m_x = 0.0f;
	float m_y = 0.0f;
public:

	
	Vector2d() {};
	Vector2d(float x1, float y1)
		: m_x(x1), m_y(y1) {}

	Vector2d Add(Vector2d B);
	Vector2d Subtract(Vector2d B);
	Vector2d ScalerMult(float k);
	float Magnitude();
	Vector2d Normalize();
	float DotProduct(Vector2d B);
	bool operator == (Vector2d &result);
	float x();
	float y();
};


class Vector3d
{
	float m_x = 0.0f;
	float m_y = 0.0f;
	float m_z = 0.0f;
public:
	Vector3d() {};
	Vector3d(float x1, float y1, float z1)
		: m_x(x1), m_y(y1), m_z(z1) {}

	Vector3d Add(Vector3d B);
	Vector3d Subtract(Vector3d B);
	Vector3d ScalerMult(float k);
	float Magnitude();
	Vector3d Normalize();
	float DotProduct(Vector3d B);
	Vector3d CrossProduct(Vector3d B);
	bool operator == (Vector3d &result);
	float x();
	float y();
	float z();
};

class Vector4d
{
	float m_x = 0.0f;
	float m_y = 0.0f;
	float m_z = 0.0f;
	float m_w = 0.0f;
public:
	Vector4d() {};
	Vector4d(float x1, float y1, float z1, float w1)
		: m_x(x1), m_y(y1), m_z(z1), m_w(w1) {}

	Vector4d Add(Vector4d B);
	Vector4d Subtract(Vector4d B);
	Vector4d ScalerMult(float k);
	float Magnitude();
	Vector4d Normalize();
	float DotProduct(Vector4d B);
	bool operator == (Vector4d &result);
	float x();
	float y();
	float z();
	float w();
};

class Matrix2d : Vector2d
{
	float m_MatShape[4];
public:
	Matrix2d() {}
	Matrix2d(float x1, float x2, float y1, float y2);
	Matrix2d(Vector2d columnA, Vector2d columnB);
	Matrix2d operator * (Matrix2d k);
	Matrix2d Mult(Matrix2d k);
	Vector2d operator * (Vector2d k);
	Vector2d Mult(Vector2d k);
	void print();
};

class Matrix3d : Vector3d
{
	float m_MatShape[9];
public:
	Matrix3d() {}
	Matrix3d(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3);
	Matrix3d(Vector3d columnA, Vector3d columnB, Vector3d columnC);
	Matrix3d operator * (Matrix3d k);
	Matrix3d Mult(Matrix3d k);
	Vector3d operator * (Vector3d k);
	Vector3d Mult(Vector3d k);
	Matrix3d RotateX(float d);
	Matrix3d RotateY(float d);
	Matrix3d RotateZ(float d);
	void print();
};

class Matrix4d : Vector4d
{
	float m_MatShape[16];
public:
	Matrix4d(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4);
	Matrix4d(Vector4d columnA, Vector4d columnB, Vector4d columnC, Vector4d columnD);
	Matrix4d operator * (Matrix4d k);
	Matrix4d Mult(Matrix4d k);
	Vector4d operator * (Vector4d k);
	Vector4d Mult(Vector4d k);
	Matrix4d RotateX(float d);
	Matrix4d RotateY(float d);
	Matrix4d RotateZ(float d);
	void print();

};