

#include "MyMath.h"

Vector2 Vector2::Add(Vector2 B)
{
	// a vector2 instance's coordinate values are  added to another vector2's coordinate values 
	Vector2 newVec = Vector2(m_x + B.m_x, m_y + B.m_y);
	// a new vector is created that is the sum of the two vectors
	return newVec;
}

Vector2 Vector2::Subtract(Vector2 B)
{
	// a vector2 instance's coordinate values are subtracted from another vector2's coordinate values
	Vector2 newVec = Vector2(m_x - B.m_x, m_y - B.m_y);
	// a new vector is created that is the difference of the two vectors
	return newVec;
}

Vector2 Vector2::ScalerMult(float k)
{
	// a scaling value is multiplied by a vector2 instance to upscale or downscale it
	Vector2 newVec = Vector2(m_x * k, m_y * k);
	// a new vector is created to represent the new scaled vector
	return newVec;
}

float Vector2::Magnitude()
{
	// presents the magnitude of a vector2 instance
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

Matrix2x2::Matrix2x2(float x1, float x2, float y1, float y2)
{
	/*	 ___________________________________________
		|											|
		|	MatShape[0] = x1	MatShape[1] = x2	|
		|	MatShape[2] = y1 	MatShape[3] = y2	|
		|___________________________________________| */

	m_Matrix[0] = x1;
	m_Matrix[1] = x2;
	m_Matrix[2] = y1;
	m_Matrix[3] = y2;
}

Matrix2x2::Matrix2x2(Vector2 columnA, Vector2 columnB)
{
	m_Matrix[0] = columnA.X();
	m_Matrix[1] = columnB.X();
	m_Matrix[2] = columnA.Y();
	m_Matrix[3] = columnB.Y();
}

Matrix2x2 Matrix2x2::operator*(Matrix2x2 k)
{
	return Mult(k);
}

Matrix2x2 Matrix2x2::Mult(Matrix2x2 k)
{
	Matrix2x2 newMat = Matrix2x2((m_Matrix[0] * k.m_Matrix[0]) + (m_Matrix[1] * k.m_Matrix[2]),
		(m_Matrix[0] * k.m_Matrix[1]) + (m_Matrix[1] * k.m_Matrix[3]),
		(m_Matrix[2] * k.m_Matrix[0]) + (m_Matrix[3] * k.m_Matrix[2]),
		(m_Matrix[2] * k.m_Matrix[1]) + (m_Matrix[3] * k.m_Matrix[3]));
	return newMat;
}

Vector2 Matrix2x2::operator*(Vector2 k)
{
	return Mult(k);
}

Vector2 Matrix2x2::Mult(Vector2 k)
{
	Vector2 resultVec = Vector2(
		(k.X() * m_Matrix[0]) + (k.X() * m_Matrix[1]),
		(k.Y() * m_Matrix[2]) + (k.Y() * m_Matrix[3]));
	return resultVec;
}

bool Matrix2x2::operator==(Matrix2x2 & result)
{
	return m_Matrix[0] == result.m_Matrix[0] && m_Matrix[1] == result.m_Matrix[1] && m_Matrix[2] == result.m_Matrix[2] && m_Matrix[3] == result.m_Matrix[3];
}


ofstream & operator<<(ofstream & output, Matrix2x2 & n)
{
	output 
		<< "{ " << Round(n.m_Matrix[0], 5u) << "  " << Round(n.m_Matrix[1], 5u) << "  }\n"
		<< "{ " << Round(n.m_Matrix[2], 5u) << "  " << Round(n.m_Matrix[3], 5u) << " }\n";

}

ofstream & operator<<(ofstream & output, Matrix3x3 & n)
{
	output << "{ " << n.m_Matrix[0] << "  " << n.m_Matrix[1] << "  " << n.m_Matrix[2] << "  }\n"
		<< "{ " << n.m_Matrix[3] << "     " << n.m_Matrix[4] << "  " << n.m_Matrix[5] << "    }\n"
		<< "{ " << n.m_Matrix[6] << "  " << n.m_Matrix[7] << "  " << n.m_Matrix[8] << " }\n";

}

ofstream & operator<<(ofstream & output, Matrix4x4 & n)
{
	
	output 
		<< "{  " << n.m_Matrix[0] << "  " << n.m_Matrix[1] << "  " << n.m_Matrix[2] << "   " << n.m_Matrix[3] << "       }\n"
		<< "{  " << n.m_Matrix[4] << "  " << n.m_Matrix[5] << "  " << n.m_Matrix[6] << "   " << n.m_Matrix[7] << "       }\n"
		<< "{  " << n.m_Matrix[8] << "  " << n.m_Matrix[9] << "  " << n.m_Matrix[10] << "   " << n.m_Matrix[11] << "       }\n"
		<< "{  " << n.m_Matrix[12] << "   " << n.m_Matrix[13] << "   " << n.m_Matrix[14] << "   " << n.m_Matrix[15] << "       }\n";
}

Matrix3x3::Matrix3x3(float x1, float x2, float x3, float y1, float y2, float y3, float z1, float z2, float z3)
{
	m_Matrix[0] = x1;	m_Matrix[1] = x2; m_Matrix[2] = x3;
	m_Matrix[3] = y1; m_Matrix[4] = y2; m_Matrix[5] = y3;
	m_Matrix[6] = z1; m_Matrix[7] = z2; m_Matrix[8] = z3;
}

Matrix3x3::Matrix3x3(Vector3 columnA, Vector3 columnB, Vector3 columnC)
{
	m_Matrix[0] = columnA.X(); m_Matrix[1] = columnB.X(); m_Matrix[2] = columnC.X();
	m_Matrix[3] = columnA.Y(); m_Matrix[4] = columnB.Y(); m_Matrix[5] = columnC.Y();
	m_Matrix[6] = columnA.Z(); m_Matrix[7] = columnB.Z(); m_Matrix[8] = columnC.Z();

}

Matrix3x3 Matrix3x3::operator*(Matrix3x3 k)
{
	return Mult(k);
}

Matrix3x3 Matrix3x3::Mult(Matrix3x3 k)
{
	Matrix3x3 newMat = Matrix3x3(
		/*x1*/	(m_Matrix[0] * k.m_Matrix[0]) + (m_Matrix[1] * k.m_Matrix[3]) + (m_Matrix[2] * k.m_Matrix[6]),
		/*x2*/	(m_Matrix[0] * k.m_Matrix[1]) + (m_Matrix[1] * k.m_Matrix[4]) + (m_Matrix[2] * k.m_Matrix[7]),
		/*x3*/	(m_Matrix[0] * k.m_Matrix[2]) + (m_Matrix[1] * k.m_Matrix[5]) + (m_Matrix[2] * k.m_Matrix[8]),
		/*y1*/	(m_Matrix[3] * k.m_Matrix[0]) + (m_Matrix[4] * k.m_Matrix[3]) + (m_Matrix[5] * k.m_Matrix[6]),
		/*y2*/	(m_Matrix[3] * k.m_Matrix[1]) + (m_Matrix[4] * k.m_Matrix[4]) + (m_Matrix[5] * k.m_Matrix[7]),
		/*y3*/	(m_Matrix[3] * k.m_Matrix[2]) + (m_Matrix[4] * k.m_Matrix[5]) + (m_Matrix[5] * k.m_Matrix[8]),
		/*z1*/	(m_Matrix[6] * k.m_Matrix[0]) + (m_Matrix[7] * k.m_Matrix[3]) + (m_Matrix[8] * k.m_Matrix[6]),
		/*z2*/	(m_Matrix[6] * k.m_Matrix[1]) + (m_Matrix[7] * k.m_Matrix[4]) + (m_Matrix[8] * k.m_Matrix[7]),
		/*z3*/	(m_Matrix[6] * k.m_Matrix[2]) + (m_Matrix[7] * k.m_Matrix[5]) + (m_Matrix[8] * k.m_Matrix[8]));
	return newMat;
}

Vector3 Matrix3x3::operator*(Vector3 k)
{
	return Mult(k);
}

Vector3 Matrix3x3::Mult(Vector3 k)
{
	Vector3 newVec = Vector3(
		/*x*/	(k.X() * m_Matrix[0]) + (k.X() * m_Matrix[1]) + (k.X() * m_Matrix[2]),
		/*y*/	(k.Y() * m_Matrix[3]) + (k.Y() * m_Matrix[4]) + (k.Y() * m_Matrix[5]),
		/*z*/	(k.Z() * m_Matrix[6]) + (k.Z() * m_Matrix[7]) + (k.Z() * m_Matrix[8]));
	return newVec;
}

bool Matrix3x3::operator==(Matrix3x3 & result)
{
	return m_Matrix[0] == result.m_Matrix[0] && m_Matrix[1] == result.m_Matrix[1] && m_Matrix[2] == result.m_Matrix[2] && m_Matrix[3] == result.m_Matrix[3];
}

Matrix3x3 Matrix3x3::RotateX(float d)
{
	Matrix3x3 newMat = Matrix3x3(
		m_Matrix[0], m_Matrix[1], m_Matrix[2],
		m_Matrix[3], cos(d), -sin(d),
		m_Matrix[6], sin(d), cos(d));
	*this = *this * newMat;
	return *this;

}

Matrix3x3 Matrix3x3::RotateY(float d)
{
	Matrix3x3 newMat = Matrix3x3(
		cos(d), m_Matrix[1], sin(d),
		m_Matrix[3], m_Matrix[4], m_Matrix[5],
		-sin(d), m_Matrix[7], cos(d));
	*this = *this * newMat;
	return *this;
}

Matrix3x3 Matrix3x3::RotateZ(float d)
{
	Matrix3x3 newMat = Matrix3x3(
		cos(d), -sin(d), m_Matrix[2],
		sin(d), cos(d), m_Matrix[5],
		m_Matrix[6], m_Matrix[7], m_Matrix[8]);
	*this = *this * newMat;
	return *this;

}

Matrix4x4::Matrix4x4(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4, float z1, float z2, float z3, float z4, float w1, float w2, float w3, float w4)
{
	m_Matrix[0] = x1; m_Matrix[1] = x2; m_Matrix[2] = x3; m_Matrix[3] = x4;
	m_Matrix[4] = y1; m_Matrix[5] = y2; m_Matrix[6] = y3; m_Matrix[7] = x4;
	m_Matrix[8] = z1; m_Matrix[9] = z2; m_Matrix[10] = z3; m_Matrix[11] = z4;
	m_Matrix[12] = w1; m_Matrix[13] = w2; m_Matrix[14] = w3; m_Matrix[15] = w4;
}

Matrix4x4::Matrix4x4(Vector4 columnA, Vector4 columnB, Vector4 columnC, Vector4 columnD)
{
	m_Matrix[0] = columnA.X(); m_Matrix[1] = columnB.X(); m_Matrix[2] = columnC.X(); m_Matrix[3] = columnD.X();
	m_Matrix[4] = columnA.Y(); m_Matrix[5] = columnB.Y(); m_Matrix[6] = columnC.Y(); m_Matrix[7] = columnD.Y();
	m_Matrix[8] = columnA.Z(); m_Matrix[9] = columnB.Z(); m_Matrix[10] = columnC.Z(); m_Matrix[11] = columnD.Z();
	m_Matrix[12] = columnA.W(); m_Matrix[13] = columnB.W(); m_Matrix[14] = columnC.W(); m_Matrix[15] = columnD.W();
}

Matrix4x4 Matrix4x4::operator*(Matrix4x4 k)
{
	return Mult(k);
}

Matrix4x4 Matrix4x4::Mult(Matrix4x4 k)
{
	Matrix4x4 newMat = Matrix4x4(
		/*x1*/	(m_Matrix[0] * k.m_Matrix[0]) + (m_Matrix[1] * k.m_Matrix[4]) + (m_Matrix[2] * k.m_Matrix[8]) + (m_Matrix[3] * k.m_Matrix[12]),
		/*x2*/	(m_Matrix[0] * k.m_Matrix[1]) + (m_Matrix[1] * k.m_Matrix[5]) + (m_Matrix[2] * k.m_Matrix[9]) + (m_Matrix[3] * k.m_Matrix[13]),
		/*x3*/	(m_Matrix[0] * k.m_Matrix[2]) + (m_Matrix[1] * k.m_Matrix[6]) + (m_Matrix[2] * k.m_Matrix[10]) + (m_Matrix[3] * k.m_Matrix[14]),
		/*x4*/	(m_Matrix[0] * k.m_Matrix[3]) + (m_Matrix[1] * k.m_Matrix[7]) + (m_Matrix[2] * k.m_Matrix[11]) + (m_Matrix[3] * k.m_Matrix[15]),
		/*y1*/	(m_Matrix[4] * k.m_Matrix[0]) + (m_Matrix[5] * k.m_Matrix[4]) + (m_Matrix[6] * k.m_Matrix[8]) + (m_Matrix[7] * k.m_Matrix[12]),
		/*y2*/	(m_Matrix[4] * k.m_Matrix[1]) + (m_Matrix[5] * k.m_Matrix[5]) + (m_Matrix[6] * k.m_Matrix[9]) + (m_Matrix[7] * k.m_Matrix[13]),
		/*y3*/	(m_Matrix[4] * k.m_Matrix[2]) + (m_Matrix[5] * k.m_Matrix[6]) + (m_Matrix[6] * k.m_Matrix[10]) + (m_Matrix[7] * k.m_Matrix[14]),
		/*y4*/	(m_Matrix[4] * k.m_Matrix[3]) + (m_Matrix[5] * k.m_Matrix[7]) + (m_Matrix[6] * k.m_Matrix[11]) + (m_Matrix[7] * k.m_Matrix[15]),
		/*z1*/	(m_Matrix[8] * k.m_Matrix[0]) + (m_Matrix[9] * k.m_Matrix[4]) + (m_Matrix[10] * k.m_Matrix[8]) + (m_Matrix[11] * k.m_Matrix[12]),
		/*z2*/	(m_Matrix[8] * k.m_Matrix[1]) + (m_Matrix[9] * k.m_Matrix[5]) + (m_Matrix[10] * k.m_Matrix[9]) + (m_Matrix[11] * k.m_Matrix[13]),
		/*z3*/	(m_Matrix[8] * k.m_Matrix[2]) + (m_Matrix[9] * k.m_Matrix[6]) + (m_Matrix[10] * k.m_Matrix[10]) + (m_Matrix[11] * k.m_Matrix[14]),
		/*z4*/	(m_Matrix[8] * k.m_Matrix[3]) + (m_Matrix[9] * k.m_Matrix[7]) + (m_Matrix[10] * k.m_Matrix[11]) + (m_Matrix[11] * k.m_Matrix[15]),
		/*w1*/	(m_Matrix[12] * k.m_Matrix[0]) + (m_Matrix[13] * k.m_Matrix[4]) + (m_Matrix[14] * k.m_Matrix[8]) + (m_Matrix[15] * k.m_Matrix[12]),
		/*w2*/	(m_Matrix[12] * k.m_Matrix[1]) + (m_Matrix[13] * k.m_Matrix[5]) + (m_Matrix[14] * k.m_Matrix[9]) + (m_Matrix[15] * k.m_Matrix[13]),
		/*w3*/	(m_Matrix[12] * k.m_Matrix[2]) + (m_Matrix[13] * k.m_Matrix[6]) + (m_Matrix[14] * k.m_Matrix[10]) + (m_Matrix[15] * k.m_Matrix[14]),
		/*w4*/	(m_Matrix[12] * k.m_Matrix[3]) + (m_Matrix[13] * k.m_Matrix[7]) + (m_Matrix[14] * k.m_Matrix[11]) + (m_Matrix[15] * k.m_Matrix[15]));
	return newMat;
}

Vector4 Matrix4x4::operator*(Vector4 k)
{
	return Mult(k);

}

Vector4 Matrix4x4::Mult(Vector4 k)
{
	Vector4 newVec = Vector4(
		/*x*/(k.X() * m_Matrix[0]) + (k.X() * m_Matrix[1]) + (k.X() * m_Matrix[2]) + (k.X() * m_Matrix[3]),
		/*y*/(k.Y() * m_Matrix[4]) + (k.Y() * m_Matrix[5]) + (k.Y() * m_Matrix[6]) + (k.Y() * m_Matrix[7]),
		/*z*/(k.Z() * m_Matrix[8]) + (k.Z() * m_Matrix[9]) + (k.Z() * m_Matrix[10]) + (k.Z() * m_Matrix[11]),
		/*w*/(k.W() * m_Matrix[12]) + (k.W() * m_Matrix[13]) + (k.W() * m_Matrix[14]) + (k.W() * m_Matrix[15]));
	return newVec;
}

bool Matrix4x4::operator==(Matrix4x4 & result)
{
	return  m_Matrix[0] == result.m_Matrix[0] && m_Matrix[1] == result.m_Matrix[1] && m_Matrix[2] == result.m_Matrix[2] && m_Matrix[3] == result.m_Matrix[3];
}

Matrix4x4 Matrix4x4::RotateX(float d)
{
	Matrix4x4 newMat = Matrix4x4(
		m_Matrix[0], m_Matrix[1], m_Matrix[2], m_Matrix[3],
		m_Matrix[4], cos(d), -sin(d), m_Matrix[7],
		m_Matrix[8], sin(d), cos(d), m_Matrix[11],
		m_Matrix[12], m_Matrix[13], m_Matrix[14], m_Matrix[15]);
	*this = *this * newMat;
	return *this;
}

Matrix4x4 Matrix4x4::RotateY(float d)
{
	Matrix4x4 newMat = Matrix4x4(
		cos(d), m_Matrix[1], sin(d), m_Matrix[3],
		m_Matrix[4], m_Matrix[5], m_Matrix[6], m_Matrix[7],
		-sin(d), m_Matrix[9], cos(d), m_Matrix[11],
		m_Matrix[12], m_Matrix[13], m_Matrix[14], m_Matrix[15]);
	*this = *this * newMat;
	return *this;

}

Matrix4x4 Matrix4x4::RotateZ(float d)
{
	Matrix4x4 newMat = Matrix4x4(
		cos(d), -sin(d), m_Matrix[2], m_Matrix[3],
		sin(d), cos(d), m_Matrix[6], m_Matrix[7],
		m_Matrix[8], m_Matrix[9], m_Matrix[10], m_Matrix[11],
		m_Matrix[12], m_Matrix[13], m_Matrix[14], m_Matrix[15]);
	*this = *this * newMat;
	return *this;
}


float Round(float value, unsigned int decimals)
{
	return truncf(value * decimals) / (float)decimals;
} 