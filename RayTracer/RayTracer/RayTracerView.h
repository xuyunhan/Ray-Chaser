
// RayTracerView.h : CRayTracerView 类的接口
//

#pragma once
#include "Camera.h"
#include "Sphere.h"

class CRayTracerView : public CView
{
protected: // 仅从序列化创建
	CRayTracerView();
	DECLARE_DYNCREATE(CRayTracerView)

// 特性
public:
	CRayTracerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CRayTracerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int** Image;// 存结果的RGB值
	// //渲染深度图像
	void RenderDepth(Sphere* scene, Camera* camera, double maxDepth);
	afx_msg void RenderDepthButtonDown();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// 渲染法向量
	void RenderNormal(Sphere* scene, Camera* camera, double maxDepth);
	void RenderMaterial(Geometry* scene, Camera* camera, double maxDepth);
	afx_msg void RenderNormalButtonDown();
	afx_msg void OnRenderMaterialButtonDown();
	afx_msg void OnRenderRayTraceButtonDown();
	void RenderRayTrace(Geometry* scene, Camera* camera, int maxReflect);
	Color RayTraceRecursive(Geometry* scene, Ray3* ray, int maxReflect);
};

#ifndef _DEBUG  // RayTracerView.cpp 中的调试版本
inline CRayTracerDoc* CRayTracerView::GetDocument() const
   { return reinterpret_cast<CRayTracerDoc*>(m_pDocument); }
#endif

