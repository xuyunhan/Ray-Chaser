#pragma once
#include "Vector3.h"
#include "Ray3.h"
#define M_PI       3.14159265358979323846
class Camera
	//摄影机在光线追踪系统里，负责把图片里每一个像素的位置，生成一束光线。
	//由于图片的大小可变，所以坐标不用像素点，而用归一化的[0,1]double坐标。
	//左下角为(0,0)，右上角为(1,1)。
{
public:
	Camera();
	Camera::Camera(Vector3 pEye, Vector3 pFront, Vector3 pUp, double pFov);

	~Camera();
	// 观察点
	Vector3 eye;
	// 相机朝向
	Vector3 front;
	// 相机观察点的上方（法线），后面用它算出相机的up法线，以使相机up方向正确
	Vector3 refUp;
	// field of view
	double fov;//为了方便，只考虑正方形的图片，故fov同时代表水平和垂直方向的fov，角度制
	// 根据fov算出的视野宽度大小（假设观察点到图片的距离为1）
	double fovScale;
	// 相机向右的单位向量
	Vector3 right;
	// 相机向上法线
	Vector3 up;
	// 根据图片上某个坐标(pX,pY)算出光线并返回
	Ray3 GenerateRay(double pX, double pY);
};

