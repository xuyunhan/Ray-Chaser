
// RayTracerView.h : CRayTracerView ��Ľӿ�
//

#pragma once
#include "Camera.h"
#include "Sphere.h"

class CRayTracerView : public CView
{
protected: // �������л�����
	CRayTracerView();
	DECLARE_DYNCREATE(CRayTracerView)

// ����
public:
	CRayTracerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CRayTracerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int** Image;// ������RGBֵ
	// //��Ⱦ���ͼ��
	void RenderDepth(Sphere* scene, Camera* camera, double maxDepth);
	afx_msg void RenderDepthButtonDown();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// ��Ⱦ������
	void RenderNormal(Sphere* scene, Camera* camera, double maxDepth);
	void RenderMaterial(Geometry* scene, Camera* camera, double maxDepth);
	afx_msg void RenderNormalButtonDown();
	afx_msg void OnRenderMaterialButtonDown();
	afx_msg void OnRenderRayTraceButtonDown();
	void RenderRayTrace(Geometry* scene, Camera* camera, int maxReflect);
	Color RayTraceRecursive(Geometry* scene, Ray3* ray, int maxReflect);
};

#ifndef _DEBUG  // RayTracerView.cpp �еĵ��԰汾
inline CRayTracerDoc* CRayTracerView::GetDocument() const
   { return reinterpret_cast<CRayTracerDoc*>(m_pDocument); }
#endif

