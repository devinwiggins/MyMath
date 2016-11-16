#include "MyMath.h"

Vector2 Vector2::Add(Vector2 B)
{
	Vector2 newVec = Vector2(m_x + B.m_x, m_y + B.m_y);
	return newVec;
}

Vector2 Vector2::Subtract(Vector2 B)
{
	Vector2 newVec = Vector2(m_x - B.m_x, m_y - B.m_y);
	return newVec;
}

Vector2 Vector2::ScalerMult(float k)
{
	Vector2 newVec = Vector2(m_x * k, m_y * k);
	return newVec;
}

float Vector2::Magnitude()
{
	float result = sqrt((m_x * m_x) + (m_y * m_y));
	return result;
}

Vector2 Vector2::Normalize()
{
	// alternate
	/*float x = sqrt(m_x + m_y);
	float A = x;
	float B = x;
	A = A * (m_x / A);
	B = B * (m_y / B);
	m_x = B;
	m_y = A;*/

	Vector2 newVec = Vector2(m_x / Magnitude(), m_y / Magnitude());
	return newVec;
}

float Vector2::DotProduct(Vector2 B)
{
	return (m_x*B.m_x) + (m_y * B.m_y);
}

bool Vector2::operator==(Vector2 & result)
{
	return m_x == result.m_x && m_y == result.m_y;
}

float Vector2::X()
{
	return m_x;
}

float Vector2::Y()
{
	return m_y;
}

Vector3 Vector3::Add(Vector3 B)
{
	Vector3 newVec = Vector3(m_x + B.m_x, m_y + B.m_y, m_z + B.m_z);
	return newVec;
}

Vector3 Vector3::Subtract(Vector3 B)
{
	Vector3 newVec = Vector3(m_x - B.m_x, m_y - B.m_y, m_z - B.m_z);
	return newVec;
}

Vector3 Vector3::ScalerMult(float k)
{
	Vector3 newVec = Vector3(m_x * k, m_y * k, m_z * k);
	return newVec;
}

float Vector3::Magnitude()
{
	float result = sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
	return result;
}

Vector3 Vector3::Normalize()
{
	Vector3 newVec = Vector3(m_x / Magnitude(), m_y / Magnitude(), m_z / Magnitude());
	return newVec;
}

float Vector3::DotProduct(Vector3 B)
{
	return (m_x*B.m_x) + (m_y * B.m_y) + (m_z * B.m_z);
}

Vector3 Vector3::CrossProduct(Vector3 B)
{
	//x = (AyBz) - (AzBy); y = (AzBx) - (AxBz); z = (AxBy) - (AyBx)
	Vector3 newVec = Vector3((m_y * B.m_z) - (m_z * B.m_y), (m_z * B.m_x) - (m_x * B.m_z), (m_x * B.m_y) - (m_y * B.m_x));
	return newVec;
}

bool Vector3::operator==(Vector3 & result)
{
	return m_x == result.m_x && m_y == result.m_y && m_z == result.m_z;
}

float Vector3::X()
{
	return m_x; 
}

float Vector3::Y()
{
	return m_y;
}

float Vector3::Z()
{
	return m_z;
}

Vector4 Vector4::Add(Vector4 B)
{
	Vector4 newVec = Vector4(m_x + B.m_x, m_y + B.m_y, m_z + B.m_z, m_w + B.m_w);
	return newVec;
}

Vector4 Vector4::Subtract(Vector4 B)
{
	Vector4 newVec = Vector4(m_x - B.m_x, m_y - B.m_y, m_z - B.m_z, m_w - B.m_w);
	return newVec;
}

Vector4 Vector4::ScalerMult(float k)
{
	Vector4 newVec = Vector4(m_x * k, m_y * k, m_z * k, m_w * k);
	return newVec;
}

float Vector4::Magnitude()
{
	float result = sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w));
	return result;
}

Vector4 Vector4::Normalize()
{
	Vector4 newVec = Vector4(m_x / Magnitude(), m_y / Magnitude(), m_z / Magnitude(), m_w / Magnitude());
	return newVec;
}

float Vector4::DotProduct(Vector4 B)
{
	return (m_x*B.m_x) + (m_y * B.m_y) + (m_z * B.m_z);
}

bool Vector4::operator==(Vector4 & result)
{
	return m_x == result.m_x && m_y == result.m_y;
}

float Vector4::X()
{
	return m_x;
}

float Vector4::Y()
{
	return m_y;
}

float Vector4::Z()
{
	return m_z;
}

float Vector4::W()
{
	return m_w;
}

Matrix22::Matrix22(float x1, float x2, float y1, float y2)
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

Matrix22::Matrix22(Vector2 columnA, Vector2 columnB)
{
	m_MatShape[0] = columnA.X();
	m_MatShape[1] = columnB.X();
	m_MatShape[2] = columnA.Y();
	m_MatShape[3] = columnB.Y();
}

Matrix22 Matrix22::operator*(Matrix22 k)
{
	return Mult(k);
}

Matrix22 Matrix22::Mult(Matrix22 k)
{
	Matrix22 newMat = Matrix22((m_MatShape[0] * k.m_MatShape[0]) + (m_MatShape[1] * k.m_MatShape[2]),
		(m_MatShape[0] * k.m_MatShape[1]) + (m_MatShape[1] * k.m_MatShape[3]),
		(m_MatShape[2] * k.m_MatShape[0]) + (m_MatShape[3] * k.m_MatShape[2]),
		(m_MatShape[2] * k.m_MatShape[1]) + (m_MatShape[3] * k.m_MatShape[3]));
	return newMat;
}

Vector2 Matrix22::operator*(Vector2 k)
{
	return Mult(k);
}

Vector2 Matrix22::Mult(Vector2 k)
{
	Vector2 resultVec = Vector2(
		(k.X() * m_MatShape[0]) + (k.X() * m_MatShape[1]),
		(k.Y() * m_MatShape[2]) + (k.Y() * m_MatShape[3]));
	return resultVec;
}

void Matrix22::print()
{
	float* tmp = &m_MatShape[0];
	for (int i = 0; i < 16; i++)
	{
		float a = truncf(tmp[i] * 10.0) / 10.0;
		tmp[i] = a;
	}
	std::cout << "{ " << m_MatShape[0] << "  " << m_MatShape[1] << "  }\n"
		<< "{ " << m_MatShape[2] << "  " << m_MatShape[3] << " }\n";
}

Matrix33::Matrix33(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3)
{
	m_MatShape[0] = x1;	m_MatShape[1] = x2; m_MatShape[2] = x3;
	m_MatShape[3] = y1; m_MatShape[4] = y2; m_MatShape[5] = y3;
	m_MatShape[6] = z1; m_MatShape[7] = z2; m_MatShape[8] = z3;
}

Matrix33::Matrix33(Vector3 columnA, Vector3 columnB, Vector3 columnC)
{
	m_MatShape[0] = columnA.X(); m_MatShape[1] = columnB.X(); m_MatShape[2] = columnC.X();
	m_MatShape[3] = columnA.Y(); m_MatShape[4] = columnB.Y(); m_MatShape[5] = columnC.Y();
	m_MatShape[6] = columnA.Z(); m_MatShape[7] = columnB.Z(); m_MatShape[8] = columnC.Z();

}

Matrix33 Matrix33::operator*(Matrix33 k)
{
	return Mult(k);
}

Matrix33 Matrix33::Mult(Matrix33 k)
{
	Matrix33 newMat = Matrix33(
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

Vector3 Matrix33::operator*(Vector3 k)
{
	return Mult(k);
}

Vector3 Matrix33::Mult(Vector3 k)
{
	Vector3 newVec = Vector3(
		/*x*/	(k.X() * m_MatShape[0]) + (k.X() * m_MatShape[1]) + (k.X() * m_MatShape[2]),
		/*y*/	(k.Y() * m_MatShape[3]) + (k.Y() * m_MatShape[4]) + (k.Y() * m_MatShape[5]),
		/*z*/	(k.Z() * m_MatShape[6]) + (k.Z() * m_MatShape[7]) + (k.Z() * m_MatShape[8]));
	return newVec;
}

Matrix33 Matrix33::RotateX(float d)
{
	Matrix33 newMat = Matrix33(
		m_MatShape[0], m_MatShape[1], m_MatShape[2],
		m_MatShape[3], cos(d), -sin(d),
		m_MatShape[6], sin(d), cos(d));
	*this = *this * newMat;
	return *this;

}

Matrix33 Matrix33::RotateY(float d)
{
	Matrix33 newMat = Matrix33(
		cos(d), m_MatShape[1], sin(d),
		m_MatShape[3], m_MatShape[4], m_MatShape[5],
		-sin(d), m_MatShape[7], cos(d));
	*this = *this * newMat;
	return *this;
}

Matrix33 Matrix33::RotateZ(float d)
{
	Matrix33 newMat = Matrix33(
		cos(d), -sin(d), m_MatShape[2],
		sin(d), cos(d), m_MatShape[5],
		m_MatShape[6], m_MatShape[7], m_MatShape[8]);
	*this = *this * newMat;
	return *this;

}

void Matrix33::print()
{
	float* tmp = &m_MatShape[0];
	for (int i = 0; i < 16; i++)
	{
		float a = truncf(tmp[i] * 10.0) / 10.0;
		tmp[i] = a;
	}
	std::cout << "{ " << m_MatShape[0] << "  " << m_MatShape[1] << "  " << m_MatShape[2] << "  }\n"
		<< "{ " << m_MatShape[3] << "     " << m_MatShape[4] << "  " << m_MatShape[5] << "    }\n"
		<< "{ " << m_MatShape[6] << "  " << m_MatShape[7] << "  " << m_MatShape[8] << " }\n";
}

Matrix44::Matrix44(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4)
{
	m_MatShape[0] = x1; m_MatShape[1] = x2; m_MatShape[2] = x3; m_MatShape[3] = x4;
	m_MatShape[4] = y1; m_MatShape[5] = y2; m_MatShape[6] = y3; m_MatShape[7] = x4;
	m_MatShape[8] = z1; m_MatShape[9] = z2; m_MatShape[10] = z3; m_MatShape[11] = z4;
	m_MatShape[12] = w1; m_MatShape[13] = w2; m_MatShape[14] = w3; m_MatShape[15] = w4;
}

Matrix44::Matrix44(Vector4 columnA, Vector4 columnB, Vector4 columnC, Vector4 columnD)
{
	m_MatShape[0] = columnA.X(); m_MatShape[1] = columnB.X(); m_MatShape[2] = columnC.X(); m_MatShape[3] = columnD.X();
	m_MatShape[4] = columnA.Y(); m_MatShape[5] = columnB.Y(); m_MatShape[6] = columnC.Y(); m_MatShape[7] = columnD.Y();
	m_MatShape[8] = columnA.Z(); m_MatShape[9] = columnB.Z(); m_MatShape[10] = columnC.Z(); m_MatShape[11] = columnD.Z();
	m_MatShape[12] = columnA.W(); m_MatShape[13] = columnB.W(); m_MatShape[14] = columnC.W(); m_MatShape[15] = columnD.W();
}

Matrix44 Matrix44::operator*(Matrix44 k)
{
	return Mult(k);
}

Matrix44 Matrix44::Mult(Matrix44 k)
{
	Matrix44 newMat = Matrix44(
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

Vector4 Matrix44::operator*(Vector4 k)
{
	return Mult(k);
	
}

Vector4 Matrix44::Mult(Vector4 k)
{
	Vector4 newVec = Vector4(
		/*x*/(k.X() * m_MatShape[0]) + (k.X() * m_MatShape[1]) + (k.X() * m_MatShape[2]) + (k.X() * m_MatShape[3]),
		/*y*/(k.Y() * m_MatShape[4]) + (k.Y() * m_MatShape[5]) + (k.Y() * m_MatShape[6]) + (k.Y() * m_MatShape[7]),
		/*z*/(k.Z() * m_MatShape[8]) + (k.Z() * m_MatShape[9]) + (k.Z() * m_MatShape[10]) + (k.Z() * m_MatShape[11]),
		/*w*/(k.W() * m_MatShape[12]) + (k.W() * m_MatShape[13]) + (k.W() * m_MatShape[14]) + (k.W() * m_MatShape[15]));
	return newVec;
}

Matrix44 Matrix44::RotateX(float d)
{
	Matrix44 newMat = Matrix44(
		m_MatShape[0], m_MatShape[1], m_MatShape[2], m_MatShape[3],
		m_MatShape[4], cos(d), -sin(d), m_MatShape[7],
		m_MatShape[8], sin(d), cos(d), m_MatShape[11],
		m_MatShape[12], m_MatShape[13], m_MatShape[14], m_MatShape[15]);
	*this = *this * newMat;
	return *this;
}

Matrix44 Matrix44::RotateY(float d)
{
	Matrix44 newMat = Matrix44(
		cos(d), m_MatShape[1], sin(d), m_MatShape[3],
		m_MatShape[4], m_MatShape[5], m_MatShape[6], m_MatShape[7],
		-sin(d), m_MatShape[9], cos(d), m_MatShape[11],
		m_MatShape[12], m_MatShape[13], m_MatShape[14], m_MatShape[15]);
	*this = *this * newMat;
	return *this;

}

Matrix44 Matrix44::RotateZ(float d)
{
	Matrix44 newMat = Matrix44(
		cos(d), -sin(d), m_MatShape[2], m_MatShape[3],
		sin(d), cos(d), m_MatShape[6], m_MatShape[7],
		m_MatShape[8], m_MatShape[9], m_MatShape[10], m_MatShape[11],
		m_MatShape[12], m_MatShape[13], m_MatShape[14], m_MatShape[15]);
	*this = *this * newMat;
	return *this;
}

void Matrix44::print()
{
	float* tmp= &m_MatShape[0];
	for (int i = 0; i < 16; i++)
	{		
		float a = truncf(tmp[i] * 10.0) / 10.0;
		tmp[i] = a;
	}

	std::cout << "{  " << tmp[0] << "  " << tmp[1] << "  " << tmp[2] << "   " << tmp[3] << "       }\n"
		<< "{  " << tmp[4] << "     " << tmp[5] << "  " << tmp[6] << "     " << tmp[7] << "       }\n"
		<< "{  " << tmp[8] << "  " << tmp[9] << "  " << tmp[10] << "  " << tmp[11] << "       }\n"
		<< "{  " << tmp[12] << "     " << tmp[13] << "  " << tmp[14] << "     " << tmp[15] << "       }\n";
}
