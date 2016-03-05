
// RayTracerView.cpp : CRayTracerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "RayTracer.h"
#endif

#include "RayTracerDoc.h"
#include "RayTracerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRayTracerView

IMPLEMENT_DYNCREATE(CRayTracerView, CView)

BEGIN_MESSAGE_MAP(CRayTracerView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32774, &CRayTracerView::RenderDepthButtonDown)
//	ON_WM_LBUTTONDBLCLK()
//ON_WM_LBUTTONDBLCLK()
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CRayTracerView 构造/析构

CRayTracerView::CRayTracerView()
	: Image(NULL)
{
	// TODO:  在此处添加构造代码
	Image = new int*[512];
	for (int i = 0; i < 512; i++)
		Image[i] = new int[512];
	for (int j = 0; j < 512;j++)
	{
		for (int k = 0; k < 512; k++)
		{
			Image[j][k] = 0;
		}
	}

}

CRayTracerView::~CRayTracerView()
{
}

BOOL CRayTracerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CRayTracerView 绘制

void CRayTracerView::OnDraw(CDC* /*pDC*/)
{
	CRayTracerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	//CClientDC dc(this);
// 	CDC* pDC = GetDC();
// 	for (int i = 0; i < 512;i++)
// 	{
// 		for (int j = 0; j < 512;j++)
// 		{
// 			pDC->SetPixel(i, j, RGB(Image[i][j], Image[i][j], Image[i][j]));
// 		}
// 	}
}

void CRayTracerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);

}

void CRayTracerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRayTracerView 诊断

#ifdef _DEBUG
void CRayTracerView::AssertValid() const
{
	CView::AssertValid();
}

void CRayTracerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRayTracerDoc* CRayTracerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRayTracerDoc)));
	return (CRayTracerDoc*)m_pDocument;
}
#endif //_DEBUG


// CRayTracerView 消息处理程序

 
// //渲染深度图像
void CRayTracerView::RenderDepth(Sphere* scene, Camera* camera, double maxDepth)
{
	CDC* pDC = GetDC();

	if (scene == nullptr || camera == nullptr)
	{
		return;
	}
	int interectPointCount = 0;
	double i = 0;
	const int h = 512;//宽高都是512个像素点
	const int w = 512;
	for (int y = 0; y < h; y ++)
	{
		double sy = 1 - (double)y / (double)h;//生成垂直方向的[0,1]坐标，因为左下角为(0,0)，所以x,y=0,0时sy应该是1。
		for (int x = 0; x < w; x ++)
		{
			double sx = (double)x / (double)w;//生成垂直方向的[0,1]坐标
			Ray3 ray = camera->GenerateRay(sx, sy);//生成光线
			IntersectResult result = scene->Intersect(ray);//与场景相交。
			if (result.geometry != nullptr)//若有交点
			{
				interectPointCount++;//计数
				int depth = 255 - min((int)((result.distance / maxDepth) * 255.0), 255);//记录距离作为深度值
				Image[x][y] = depth;
			}
			pDC->SetPixel(x, y, RGB(Image[x][y], Image[x][y], Image[x][y]));//画
		}
	}
	CString string;
	string.Format("交点数：%d", interectPointCount);
// 	MessageBox((string));
// 	CString::Format("交点数: %d", interectPointCount);
// 	MessageBox(("hello wolrd"), _T("问好"), MB_OK);
// 	string.Format("交点数: %d", interectPointCount); //将变量组装到字符串中
// 	MessageBox(string, "消息框标题", MB_OK);
// 	MessageBox("ddd");
// 	MessageBox("交点数：%d", interectPointCount);
}


void CRayTracerView::RenderDepthButtonDown()
{
	// TODO:  在此添加命令处理程序代码
	RenderDepth(&Sphere(Vector3(0, 10, -10), 10), &Camera(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0),90), 20);
// 	CDC* pDC = GetDC();
// 	for (int i = 0; i < 512; i++)
// 	{
// 		for (int j = 0; j < 512; j++)
// 		{
// 			pDC->SetPixel(i, j, RGB(Image[i][j], Image[i][j], Image[i][j]));
// 		}
// 	}
}


void CRayTracerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	RenderDepth(&Sphere(Vector3(0, 10, -10), 10), &Camera(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);

	CView::OnLButtonUp(nFlags, point);
}
