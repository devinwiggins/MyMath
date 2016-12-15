

#include "MyMath.h"


int main()
{
	
	std::ofstream  outputfile;
	outputfile.open("unitTest.txt");

	Vector2* A2d = new Vector2(0, 1);
	Vector2 B2d = Vector2(1, 0);
	/*assert(A2d->Add(B2d) == Vector2d(1, 1));
	assert(A2d->Subtract(B2d) == Vector2d(-1, 1));
	assert(A2d->ScalerMult(2) == Vector2d(0, 2));
	assert(A2d->Magnitude() == (0, 1));
	assert(A2d->Normalize() == Vector2d(0, 1));
	assert(A2d->DotProduct(B2d) == (0));*/

	Vector3* A3d = new Vector3(1, 0, 0);
	Vector3 B3d = Vector3(0, 1, 1);

	/*assert(A3d->Add(B3d) == Vector3d(1, 1, 1));
	assert(A3d->Subtract(B3d) == Vector3d(1, -1, -1));
	assert(A3d->ScalerMult(2) == Vector3d(2, 0, 0));
	assert(A3d->Magnitude() == (1));
	assert(A3d->Normalize() == Vector3d(1, 0, 0));
	assert(A3d->DotProduct(B3d) == (0));
	assert(A3d->CrossProduct(B3d) == Vector3d(0, -1, 1));*/
	
	
	Vector2 A2 = Vector2(0, 1);
	Vector2 B2 = Vector2(1, 3);
	Vector2 C2 = Vector2(1, 1);
	Vector2 D2 = Vector2(1, 3);

	Vector3 A3 = Vector3(1, 0, 0);
	Vector3 B3 = Vector3(0, 1, 0);
	Vector3 C3 = Vector3(0, 0, 1);

	Vector4 A4 = Vector4(1, 0, 0, 0);
	Vector4 B4 = Vector4(0, 1, 0, 0);
	Vector4 C4 = Vector4(0, 0, 1, 0);
	Vector4 D4 = Vector4(0, 0, 0, 1);

	Matrix2x2 mat2test = Matrix2x2(1, 3, 4, 10);

	Matrix2x2 mat = Matrix2x2(A2, B2);
	Matrix2x2 mat2 = Matrix2x2(C2, D2);
	Matrix3x3 mat3 = Matrix3x3(A3, B3, C3);
	Matrix4x4 mat4 = Matrix4x4(A4, B4, C4, D4);
	Matrix4x4 mat42 = Matrix4x4(A4, B4, C4, D4);
	Matrix4x4 mat43 = Matrix4x4(A4, B4, C4, D4);
	Matrix4x4 mat4x4_rot_x = Matrix4x4(1, 0, 0, 0,
		0, 0, 1, 0,
		0, 1, 0, 0,
		0, 0, 0, 1);
	mat.Mult(mat2);
	//assert(mat * mat2 == mat2test);

	//mat3.RotateX(90);
	//mat3.RotateY(90);
	//mat3.RotateZ(90);

	

	outputfile << "Matrix2x2 example: " << "\n";
	outputfile << mat << "\n";
	outputfile << "Matrix3x3 example: " << "\n";
	outputfile << mat3 << "\n";
	outputfile << "Matrix4x4 example: " << "\n";
	outputfile << mat4 << "\n";
	outputfile << "Matrix4x4 X rotation example: " << "\n";
	outputfile << "result:" << "\n";
	outputfile << mat4.RotateX(90) << "\n";
	outputfile << "expected result: " << "\n";
	outputfile << mat4x4_rot_x << "\n";
	outputfile << mat42.RotateY(90) << "\n";
	outputfile << mat43
	outputfile.close();
	mat4.RotateX(90);
	mat4.RotateY(90);
	mat4.RotateZ(90);
	system("pause");
}