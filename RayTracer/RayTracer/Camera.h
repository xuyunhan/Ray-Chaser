#pragma once
#include "Vector3.h"
#include "Ray3.h"
#define M_PI       3.14159265358979323846
class Camera
	//��Ӱ���ڹ���׷��ϵͳ������ͼƬ��ÿһ�����ص�λ�ã�����һ�����ߡ�
	//����ͼƬ�Ĵ�С�ɱ䣬�������겻�����ص㣬���ù�һ����[0,1]double���ꡣ
	//���½�Ϊ(0,0)�����Ͻ�Ϊ(1,1)��
{
public:
	Camera();
	Camera::Camera(Vector3 pEye, Vector3 pFront, Vector3 pUp, double pFov);

	~Camera();
	// �۲��
	Vector3 eye;
	// �������
	Vector3 front;
	// ����۲����Ϸ������ߣ�������������������up���ߣ���ʹ���up������ȷ
	Vector3 refUp;
	// field of view
	double fov;//Ϊ�˷��㣬ֻ���������ε�ͼƬ����fovͬʱ����ˮƽ�ʹ�ֱ�����fov���Ƕ���
	// ����fov�������Ұ��ȴ�С������۲�㵽ͼƬ�ľ���Ϊ1��
	double fovScale;
	// ������ҵĵ�λ����
	Vector3 right;
	// ������Ϸ���
	Vector3 up;
	// ����ͼƬ��ĳ������(pX,pY)������߲�����
	Ray3 GenerateRay(double pX, double pY);
};

