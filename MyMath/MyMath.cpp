#include "MyMath.h"

Vector2d Vector2d::Add(Vector2d B)
{
	Vector2d newVec = Vector2d(m_x + B.m_x, m_y + B.m_y);
	return newVec;
}

Vector2d Vector2d::Subtract(Vector2d B)
{
	Vector2d newVec = Vector2d(m_x - B.m_x, m_y - B.m_y);
	return newVec;
}

Vector2d Vector2d::ScalerMult(float k)
{
	Vector2d newVec = Vector2d(m_x * k, m_y * k);
	return newVec;
}

float Vector2d::Magnitude()
{
	float result = sqrt((m_x * m_x) + (m_y * m_y));
	return result;
}

Vector2d Vector2d::Normalize()
{
	// alternate
	/*float x = sqrt(m_x + m_y);
	float A = x;
	float B = x;
	A = A * (m_x / A);
	B = B * (m_y / B);
	m_x = B;
	m_y = A;*/

	Vector2d newVec = Vector2d(m_x / Magnitude(), m_y / Magnitude());
	return newVec;
}

float Vector2d::DotProduct(Vector2d B)
{
	return (m_x*B.m_x) + (m_y * B.m_y);
}

bool Vector2d::operator==(Vector2d & result)
{
	return m_x == result.m_x && m_y == result.m_y;
}

float Vector2d::x()
{
	return m_x;
}

float Vector2d::y()
{
	return m_y;
}

Vector3d Vector3d::Add(Vector3d B)
{
	Vector3d newVec = Vector3d(m_x + B.m_x, m_y + B.m_y, m_z + B.m_z);
	return newVec;
}

Vector3d Vector3d::Subtract(Vector3d B)
{
	Vector3d newVec = Vector3d(m_x - B.m_x, m_y - B.m_y, m_z - B.m_z);
	return newVec;
}

Vector3d Vector3d::ScalerMult(float k)
{
	Vector3d newVec = Vector3d(m_x * k, m_y * k, m_z * k);
	return newVec;
}

float Vector3d::Magnitude()
{
	float result = sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
	return result;
}

Vector3d Vector3d::Normalize()
{
	Vector3d newVec = Vector3d(m_x / Magnitude(), m_y / Magnitude(), m_z / Magnitude());
	return newVec;
}

float Vector3d::DotProduct(Vector3d B)
{
	return (m_x*B.m_x) + (m_y * B.m_y) + (m_z * B.m_z);
}

Vector3d Vector3d::CrossProduct(Vector3d B)
{
	//x = (AyBz) - (AzBy); y = (AzBx) - (AxBz); z = (AxBy) - (AyBx)
	Vector3d newVec = Vector3d((m_y * B.m_z) - (m_z * B.m_y), (m_z * B.m_x) - (m_x * B.m_z), (m_x * B.m_y) - (m_y * B.m_x));
	return newVec;
}

bool Vector3d::operator==(Vector3d & result)
{
	return m_x == result.m_x && m_y == result.m_y && m_z == result.m_z;
}

float Vector3d::x()
{
	return m_x;
}

float Vector3d::y()
{
	return m_y;
}

float Vector3d::z()
{
	return m_z;
}

Vector4d Vector4d::Add(Vector4d B)
{
	Vector4d newVec = Vector4d(m_x + B.m_x, m_y + B.m_y, m_z + B.m_z, m_w + B.m_w);
	return newVec;
}

Vector4d Vector4d::Subtract(Vector4d B)
{
	Vector4d newVec = Vector4d(m_x - B.m_x, m_y - B.m_y, m_z - B.m_z, m_w - B.m_w);
	return newVec;
}

Vector4d Vector4d::ScalerMult(float k)
{
	Vector4d newVec = Vector4d(m_x * k, m_y * k, m_z * k, m_w * k);
	return newVec;
}

float Vector4d::Magnitude()
{
	float result = sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w));
	return result;
}

Vector4d Vector4d::Normalize()
{
	Vector4d newVec = Vector4d(m_x / Magnitude(), m_y / Magnitude(), m_z / Magnitude(), m_w / Magnitude());
	return newVec;
}

float Vector4d::DotProduct(Vector4d B)
{
	return (m_x*B.m_x) + (m_y * B.m_y) + (m_z * B.m_z);
}

bool Vector4d::operator==(Vector4d & result)
{
	return m_x == result.m_x && m_y == result.m_y;
}

float Vector4d::x()
{
	return m_x;
}

float Vector4d::y()
{
	return m_y;
}

float Vector4d::z()
{
	return m_z;
}

float Vector4d::w()
{
	return m_w;
}

Matrix2d::Matrix2d(float x1, float x2, float y1, float y2)
{		
		/*	 ___________________________________________
			|											|
			|	MatShape[0] = x1	MatShape[1] = x2	|
			|	MatShape[2] = y1 	MatShape[3] = y2	|
			|___________________________________________| */

	m_MatShape[0] = x1;
	m_MatShape[1] = x2;	
	m_MatShape[2] = y1;
	m_MatShape[3] = y2;
}

Matrix2d::Matrix2d(Vector2d columnA, Vector2d columnB)
{
	m_MatShape[0] = columnA.x();
	m_MatShape[1] = columnB.x();
	m_MatShape[2] = columnA.y();
	m_MatShape[3] = columnB.y();
}

Matrix2d Matrix2d::operator*(Matrix2d k)
{
	return Mult(k);
}

Matrix2d Matrix2d::Mult(Matrix2d k)
{
	Matrix2d newMat = Matrix2d((m_MatShape[0] * k.m_MatShape[0]) + (m_MatShape[1] * k.m_MatShape[2]),
		(m_MatShape[0] * k.m_MatShape[1]) + (m_MatShape[1] * k.m_MatShape[3]),
		(m_MatShape[2] * k.m_MatShape[0]) + (m_MatShape[3] * k.m_MatShape[2]),
		(m_MatShape[2] * k.m_MatShape[1]) + (m_MatShape[3] * k.m_MatShape[3]));
	return newMat;
}

Vector2d Matrix2d::operator*(Vector2d k)
{
	return Mult(k);
}

Vector2d Matrix2d::Mult(Vector2d k)
{
	Vector2d resultVec = Vector2d((k.x() * m_MatShape[0]) + (k.x() * m_MatShape[1]),
		(k.y() * m_MatShape[2]) + (k.y() * m_MatShape[3]));
	return resultVec;
}

void Matrix2d::print()
{
	std::cout << "{ " << m_MatShape[0] << "  "<< m_MatShape[1] << " }\n"
			  << "{ " << m_MatShape[2] << "  "<< m_MatShape[3] << " }\n";
}

Matrix3d::Matrix3d(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3)
{
	m_MatShape[0] = x1;	m_MatShape[1] = x2; m_MatShape[2] = x3;
	m_MatShape[3] = y1; m_MatShape[4] = y2; m_MatShape[5] = y3;
	m_MatShape[6] = z1; m_MatShape[7] = z2; m_MatShape[8] = z3;
}

Matrix3d::Matrix3d(Vector3d columnA, Vector3d columnB, Vector3d columnC)
{
	m_MatShape[0] = columnA.x(); m_MatShape[1] = columnB.x(); m_MatShape[2] = columnC.x();
	m_MatShape[3] = columnA.y(); m_MatShape[4] = columnB.y(); m_MatShape[5] = columnC.y();
	m_MatShape[6] = columnA.z(); m_MatShape[7] = columnB.y(); m_MatShape[8] = columnC.z();

}

Matrix3d Matrix3d::operator*(Matrix3d k)
{
	return Mult(k);
}

Matrix3d Matrix3d::Mult(Matrix3d k)
{
	Matrix3d newMat = Matrix3d(
		/*x1*/	(m_MatShape[0] * k.m_MatShape[0]) + (m_MatShape[1] * k.m_MatShape[3]) + (m_MatShape[2] * k.m_MatShape[6]),
		/*x2*/	(m_MatShape[0] * k.m_MatShape[1]) + (m_MatShape[1] * k.m_MatShape[4]) + (m_MatShape[2] * k.m_MatShape[7]),
		/*x3*/	(m_MatShape[0] * k.m_MatShape[2]) + (m_MatShape[1] * k.m_MatShape[5]) + (m_MatShape[2] * k.m_MatShape[8]),
		/*y1*/	(m_MatShape[3] * k.m_MatShape[0]) + (m_MatShape[4] * k.m_MatShape[3]) + (m_MatShape[5] * k.m_MatShape[6]),
		/*y2*/	(m_MatShape[3] * k.m_MatShape[1]) + (m_MatShape[4] * k.m_MatShape[4]) + (m_MatShape[5] * k.m_MatShape[7]),
		/*y3*/	(m_MatShape[3] * k.m_MatShape[2]) + (m_MatShape[4] * k.m_MatShape[5]) + (m_MatShape[5] * k.m_MatShape[8]),
		/*z1*/	(m_MatShape[6] * k.m_MatShape[0]) + (m_MatShape[7] * k.m_MatShape[3]) + (m_MatShape[8] * k.m_MatShape[6]),
		/*z2*/	(m_MatShape[6] * k.m_MatShape[1]) + (m_MatShape[7] * k.m_MatShape[4]) + (m_MatShape[8] * k.m_MatShape[7]),
		/*z3*/	(m_MatShape[6] * k.m_MatShape[2]) + (m_MatShape[7] * k.m_MatShape[5]) + (m_MatShape[8] * k.m_MatShape[8]));
	return newMat;
}

Vector3d Matrix3d::operator*(Vector3d k)
{
	return Mult(k);
}

Vector3d Matrix3d::Mult(Vector3d k)
{
	Vector3d newVec = Vector3d(
		/*x*/	(k.x() * m_MatShape[0]) + (k.x() * m_MatShape[1]) + (k.x() * m_MatShape[2]),
		/*y*/	(k.y() * m_MatShape[3]) + (k.y() * m_MatShape[4]) + (k.y() * m_MatShape[5]),
		/*z*/	(k.z() * m_MatShape[6]) + (k.z() * m_MatShape[7]) + (k.z() * m_MatShape[8]));
	return newVec;
}

Matrix3d Matrix3d::RotateX(float d)
{
	Matrix3d newMat = Matrix3d(
		m_MatShape[0], m_MatShape[1], m_MatShape[2],
		m_MatShape[3], cos(d), -sin(d),
		m_MatShape[6], sin(d), cos(d));
	return * this = newMat;

}

Matrix3d Matrix3d::RotateY(float d)
{
	Matrix3d newMat = Matrix3d(
		cos(d), m_MatShape[1], sin(d),
		m_MatShape[3], m_MatShape[4], m_MatShape[5],
		-sin(d), m_MatShape[7], cos(d));
	*this = newMat;
	return *this;
}

Matrix3d Matrix3d::RotateZ(float d)
{
	Matrix3d newMat = Matrix3d(
		cos(d), -sin(d), m_MatShape[2],
		sin(d), cos(d), m_MatShape[5],
		m_MatShape[6], m_MatShape[7], m_MatShape[8]);
	return *this = newMat;

}

void Matrix3d::print()
{

}

Matrix4d::Matrix4d(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4)
{
	m_MatShape[0] = x1; m_MatShape[1] = x2; m_MatShape[2] = x3; m_MatShape[3] = x4;
	m_MatShape[4] = y1; m_MatShape[5] = y2; m_MatShape[6] = y3; m_MatShape[7] = x4;
	m_MatShape[8] = z1; m_MatShape[9] = z2; m_MatShape[10] = z3; m_MatShape[11] = z4;
	m_MatShape[12] = w1; m_MatShape[13] = w2; m_MatShape[14] = w3; m_MatShape[15] = w4;
}

Matrix4d::Matrix4d(Vector4d columnA, Vector4d columnB, Vector4d columnC, Vector4d columnD)
{
	m_MatShape[0] = columnA.x(); m_MatShape[1] = columnB.x(); m_MatShape[2] = columnC.x(); m_MatShape[3] = columnD.x();
	m_MatShape[4] = columnA.y(); m_MatShape[5] = columnB.y(); m_MatShape[6] = columnC.y(); m_MatShape[7] = columnD.y();
	m_MatShape[8] = columnA.z(); m_MatShape[9] = columnB.y(); m_MatShape[10] = columnC.z(); m_MatShape[11] = columnD.z();
	m_MatShape[12] = columnA.w(); m_MatShape[13] = columnB.w(); m_MatShape[14] = columnC.w(); m_MatShape[15] = columnD.w();
}

Matrix4d Matrix4d::operator*(Matrix4d k)
{
	return Mult(k);
}

Matrix4d Matrix4d::Mult(Matrix4d k)
{
	Matrix4d newMat = Matrix4d(
		/*x1*/	(m_MatShape[0] * k.m_MatShape[0]) + (m_MatShape[1] * k.m_MatShape[4]) + (m_MatShape[2] * k.m_MatShape[8]) + (m_MatShape[3] * k.m_MatShape[12]),
		/*x2*/	(m_MatShape[0] * k.m_MatShape[1]) + (m_MatShape[1] * k.m_MatShape[5]) + (m_MatShape[2] * k.m_MatShape[9]) + (m_MatShape[3] * k.m_MatShape[13]),
		/*x3*/	(m_MatShape[0] * k.m_MatShape[2]) + (m_MatShape[1] * k.m_MatShape[6]) + (m_MatShape[2] * k.m_MatShape[10]) + (m_MatShape[3] * k.m_MatShape[14]),
		/*x4*/	(m_MatShape[0] * k.m_MatShape[3]) + (m_MatShape[1] * k.m_MatShape[7]) + (m_MatShape[2] * k.m_MatShape[11]) + (m_MatShape[3] * k.m_MatShape[15]),
		/*y1*/	(m_MatShape[4] * k.m_MatShape[0]) + (m_MatShape[5] * k.m_MatShape[4]) + (m_MatShape[6] * k.m_MatShape[8]) + (m_MatShape[7] * k.m_MatShape[12]),
		/*y2*/	(m_MatShape[4] * k.m_MatShape[1]) + (m_MatShape[5] * k.m_MatShape[5]) + (m_MatShape[6] * k.m_MatShape[9]) + (m_MatShape[7] * k.m_MatShape[13]),
		/*y3*/	(m_MatShape[4] * k.m_MatShape[2]) + (m_MatShape[5] * k.m_MatShape[6]) + (m_MatShape[6] * k.m_MatShape[10]) + (m_MatShape[7] * k.m_MatShape[14]),
		/*y4*/	(m_MatShape[4] * k.m_MatShape[3]) + (m_MatShape[5] * k.m_MatShape[7]) + (m_MatShape[6] * k.m_MatShape[11]) + (m_MatShape[7] * k.m_MatShape[15]),
		/*z1*/	(m_MatShape[8] * k.m_MatShape[0]) + (m_MatShape[9] * k.m_MatShape[4]) + (m_MatShape[10] * k.m_MatShape[8]) + (m_MatShape[11] * k.m_MatShape[12]),
		/*z2*/	(m_MatShape[8] * k.m_MatShape[1]) + (m_MatShape[9] * k.m_MatShape[5]) + (m_MatShape[10] * k.m_MatShape[9]) + (m_MatShape[11] * k.m_MatShape[13]),
		/*z3*/	(m_MatShape[8] * k.m_MatShape[2]) + (m_MatShape[9] * k.m_MatShape[6]) + (m_MatShape[10] * k.m_MatShape[10]) + (m_MatShape[11] * k.m_MatShape[14]),
		/*z4*/	(m_MatShape[8] * k.m_MatShape[3]) + (m_MatShape[9] * k.m_MatShape[7]) + (m_MatShape[10] * k.m_MatShape[11]) + (m_MatShape[11] * k.m_MatShape[15]),
		/*w1*/	(m_MatShape[12] * k.m_MatShape[0]) + (m_MatShape[13] * k.m_MatShape[4]) + (m_MatShape[14] * k.m_MatShape[8]) + (m_MatShape[15] * k.m_MatShape[12]),
		/*w2*/	(m_MatShape[12] * k.m_MatShape[1]) + (m_MatShape[13] * k.m_MatShape[5]) + (m_MatShape[14] * k.m_MatShape[9]) + (m_MatShape[15] * k.m_MatShape[13]),
		/*w3*/	(m_MatShape[12] * k.m_MatShape[2]) + (m_MatShape[13] * k.m_MatShape[6]) + (m_MatShape[14] * k.m_MatShape[10]) + (m_MatShape[15] * k.m_MatShape[14]),
		/*w4*/	(m_MatShape[12] * k.m_MatShape[3]) + (m_MatShape[13] * k.m_MatShape[7]) + (m_MatShape[14] * k.m_MatShape[11]) + (m_MatShape[15] * k.m_MatShape[15]));
	return newMat;
}

Vector4d Matrix4d::operator*(Vector4d k)
{
	return Mult(k);
}

Vector4d Matrix4d::Mult(Vector4d k)
{
	Vector4d newVec = Vector4d(
		/*x*/(k.x() * m_MatShape[0]) + (k.x() * m_MatShape[1]) + (k.x() * m_MatShape[2]) + (k.x() * m_MatShape[3]),
		/*y*/(k.y() * m_MatShape[4]) + (k.y() * m_MatShape[5]) + (k.y() * m_MatShape[6]) + (k.y() * m_MatShape[7]),
		/*z*/(k.z() * m_MatShape[8]) + (k.z() * m_MatShape[9]) + (k.z() * m_MatShape[10]) + (k.z() * m_MatShape[11]),
		/*w*/(k.w() * m_MatShape[12]) + (k.w() * m_MatShape[13]) + (k.w() * m_MatShape[14]) + (k.w() * m_MatShape[15]));
	return newVec;
}

Matrix4d Matrix4d::RotateX(float d)
{
	Matrix4d newMat = Matrix4d(
		m_MatShape[0], m_MatShape[1], m_MatShape[2], m_MatShape[3],
		m_MatShape[4], cos(d), -sin(d), m_MatShape[7],
		m_MatShape[8], sin(d), cos(d), m_MatShape[11],
		m_MatShape[12], m_MatShape[13], m_MatShape[14], m_MatShape[15]);
	
	return *this = newMat;
}

Matrix4d Matrix4d::RotateY(float d)
{
	Matrix4d newMat = Matrix4d(
		cos(d), m_MatShape[1], sin(d), m_MatShape[3],
		m_MatShape[4], m_MatShape[5], m_MatShape[6], m_MatShape[7],
		-sin(d), m_MatShape[9], cos(d), m_MatShape[11],
		m_MatShape[12], m_MatShape[13], m_MatShape[14], m_MatShape[15]);
	
	return *this = newMat;

}

Matrix4d Matrix4d::RotateZ(float d)
{
	Matrix4d newMat = Matrix4d(
		cos(d), -sin(d), m_MatShape[2], m_MatShape[3],
		sin(d), cos(d), m_MatShape[6], m_MatShape[7],
		m_MatShape[8], m_MatShape[9], m_MatShape[10], m_MatShape[11],
		m_MatShape[12], m_MatShape[13], m_MatShape[14], m_MatShape[15]);
	
	return *this = newMat;
}

void Matrix4d::print()
{
	
}
