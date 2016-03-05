#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
	: fovScale(0)
{
}

Camera::Camera(Vector3 pEye,Vector3 pFront, Vector3 pUp,double pFov)
{
	this->eye = pEye;
	this->front = pFront;
	this->refUp = pUp;
	this->fov = pFov;

	this->right = this->front.Cross(this->refUp);
	this->up = this->right.Cross(this->front);
	this->fovScale = tan(this->fov*0.5*M_PI / 180.0) * 2;
}

Camera::~Camera()
{
}


// ����ͼƬ��ĳ������(pX,pY)������߲����أ�(pX,pY)Ϊ[-1,1]�����꣬���������[0,1]��Ҫת��һ��
Ray3 Camera::GenerateRay(double pX, double pY)
{
	Vector3 r = this->right.Multiply((pX - 0.5)*this->fovScale);//rΪpX����Ұ��ˮƽ���������������pXС��0.5ʱrΪright�ķ�����
	Vector3 u = this->up.Multiply((pY - 0.5)*this->fovScale);//rΪpY����Ұ�ϴ�ֱ���������������pYС��0.5ʱuΪup�ķ�����
	//��ԴΪeye��һ�۲�㣬�����ǰ�ķ������ˮƽ�ʹ�ֱ������Ϊ��������������һ��
	return Ray3(this->eye, this->front.Add(r).Add(u).Normalize());
}
