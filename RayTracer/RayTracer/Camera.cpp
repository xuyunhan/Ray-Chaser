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


// 根据图片上某个坐标(pX,pY)算出光线并返回，(pX,pY)为[-1,1]的坐标，所以如果从[0,1]还要转换一下
Ray3 Camera::GenerateRay(double pX, double pY)
{
	Vector3 r = this->right.Multiply((pX - 0.5)*this->fovScale);//r为pX在视野上水平方向的向量，例如pX小于0.5时r为right的反方向
	Vector3 u = this->up.Multiply((pY - 0.5)*this->fovScale);//r为pY在视野上垂直方向的向量，例如pY小于0.5时u为up的反方向
	//光源为eye这一观察点，相机向前的方向加上水平和垂直的向量为光线向量，最后归一化
	return Ray3(this->eye, this->front.Add(r).Add(u).Normalize());
}
