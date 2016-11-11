
#include "MyMath.h"

int main()
{

	Vector2d* A2d = new Vector2d(0, 1);

	Vector2d B2d = Vector2d(1, 0);

	/*assert(A2d->Add(B2d) == Vector2d(1, 1));
	assert(A2d->Subtract(B2d) == Vector2d(-1, 1));
	assert(A2d->ScalerMult(2) == Vector2d(0, 2));
	assert(A2d->Magnitude() == (0, 1));
	assert(A2d->Normalize() == Vector2d(0, 1));
	assert(A2d->DotProduct(B2d) == (0));*/

	Vector3d* A3d = new Vector3d(1, 0, 0);

	Vector3d B3d = Vector3d(0, 1, 1);
	/*assert(A3d->Add(B3d) == Vector3d(1, 1, 1));
	assert(A3d->Subtract(B3d) == Vector3d(1, -1, -1));
	assert(A3d->ScalerMult(2) == Vector3d(2, 0, 0));
	assert(A3d->Magnitude() == (1));
	assert(A3d->Normalize() == Vector3d(1, 0, 0));
	assert(A3d->DotProduct(B3d) == (0));
	assert(A3d->CrossProduct(B3d) == Vector3d(0, -1, 1)); */
	
	Vector2d A2 = Vector2d(0, 1);
	Vector2d B2 = Vector2d(1, 3);
	Vector2d C2 = Vector2d(1, 1);
	Vector2d D2 = Vector2d(1, 3);
	Vector3d A3 = Vector3d(1, 0, 0);
	Vector3d B3 = Vector3d(0, 1, 0);
	Vector3d C3 = Vector3d(0, 0, 1);
	Vector4d A4 = Vector4d(1, 0, 0, 0);
	Vector4d B4 = Vector4d(0, 1, 0, 0);
	Vector4d C4 = Vector4d(0, 0, 1, 0);
	Vector4d D4 = Vector4d(0, 0, 0, 1);
	Matrix2d Mat = Matrix2d(A2, B2);
	Matrix2d Mat2 = Matrix2d(C2, D2);
	Matrix2d a2 = Mat * Mat2;
	Matrix3d a3 = Matrix3d(A3, B3, C3);
	a3.RotateY(90);
	a2.print();

	system("pause");
}
