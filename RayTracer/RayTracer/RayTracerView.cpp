
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
#include "Color.h"
#include "Plane.h"
#include "CheckerMaterial.h"
#include "PhongMaterial.h"
#include "Union.h"
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
//ON_COMMAND(ID_32775, &CRayTracerView::On32775)
ON_COMMAND(ID_32775, &CRayTracerView::RenderNormalButtonDown)
ON_COMMAND(ID_32776, &CRayTracerView::OnRenderMaterialButtonDown)
ON_COMMAND(ID_32777, &CRayTracerView::OnRenderRayTraceButtonDown)
END_MESSAGE_MAP()

// CRayTracerView 构造/析构

CRayTracerView::CRayTracerView()
	: Image(NULL)
{
	// TODO:  在此处添加构造代码
// 	Image = new int*[512];
// 	for (int i = 0; i < 512; i++)
// 		Image[i] = new int[512];
// 	for (int j = 0; j < 512;j++)
// 	{
// 		for (int k = 0; k < 512; k++)
// 		{
// 			Image[j][k] = 0;
// 		}
// 	}

}

CRayTracerView::~CRayTracerView()
{
}

BOOL CRayTracerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
// 	cs.cx = 500;
// 	cs.cy = 500;
// 	cs.style &= ~WS_MAXIMIZEBOX;
// 	cs.style &= ~WS_THICKFRAME;
	return CView::PreCreateWindow(cs);
}

// CRayTracerView 绘制

void CRayTracerView::OnDraw(CDC* /*pDC*/)
{
	CRayTracerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

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
// 				Image[x][y] = depth;
				pDC->SetPixel(x, y, RGB(depth, depth, depth));//画
			}
			else
			{
				pDC->SetPixel(x, y, RGB(0, 0, 0));//画
			}
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
}


void CRayTracerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	RenderDepth(&Sphere(Vector3(0, 10, -10), 10), &Camera(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);

	CView::OnLButtonUp(nFlags, point);
}


// 渲染法向量
void CRayTracerView::RenderNormal(Sphere* scene, Camera* camera, double maxDepth)
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
	for (int y = 0; y < h; y++)
	{
		double sy = 1 - (double)y / (double)h;//生成垂直方向的[0,1]坐标，因为左下角为(0,0)，所以x,y=0,0时sy应该是1。
		for (int x = 0; x < w; x++)
		{
			double sx = (double)x / (double)w;//生成垂直方向的[0,1]坐标
			Ray3 ray = camera->GenerateRay(sx, sy);//生成光线
			IntersectResult result = scene->Intersect(ray);//与场景相交。
			if (result.geometry != nullptr)//若有交点
			{
				interectPointCount++;//计数
// 				int depth = 255 - min((int)((result.distance / maxDepth) * 255.0), 255);//记录距离作为深度值
// 				Image[x][y] = depth;

				pDC->SetPixel(x, y, RGB((result.normal.x + 1) * 128, (result.normal.y + 1) * 128, (result.normal.z + 1) * 128));
			}
			else
			{
				pDC->SetPixel(x, y, RGB(0, 0, 0));//画
			}
		}
	}
}

// 渲染材质
void CRayTracerView::RenderMaterial(Geometry* scene, Camera* camera, double maxDepth)
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
	for (int y = 0; y < h; y++)
	{
		double sy = 1 - (double)y / (double)h;//生成垂直方向的[0,1]坐标，因为左下角为(0,0)，所以x,y=0,0时sy应该是1。
		for (int x = 0; x < w; x++)
		{
			double sx = (double)x / (double)w;//生成垂直方向的[0,1]坐标
			Ray3 ray = camera->GenerateRay(sx, sy);//生成光线
			IntersectResult result = scene->Intersect(ray);//与场景相交。
			if (result.geometry != nullptr)//若有交点
			{
				interectPointCount++;//计数
// 				Geometry* g = result.geometry;
// 				Material *a = new CheckerMaterial();
// 				CheckerMaterial* m = g->material;
				Color color = result.geometry->material->Sample(ray, result.position, result.normal);
				color.Round();

				pDC->SetPixel(x, y, RGB(color.r * 255, color.g * 255, color.b * 255));
			}
			else
			{
				pDC->SetPixel(x, y, RGB(0, 0, 0));//画黑色
			}
		}
	}
}


void CRayTracerView::RenderNormalButtonDown()
{
	// TODO:  在此添加命令处理程序代码
	RenderNormal(&Sphere(Vector3(0, 10, -10), 10), &Camera(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);
}


void CRayTracerView::OnRenderMaterialButtonDown()
{
	// TODO:  在此添加命令处理程序代码
	Plane plane = Plane(Vector3(0, 1, 0), 0);
	Sphere sphere1 = Sphere(Vector3(-10, 10, -10), 10);
	Sphere sphere2 = Sphere(Vector3(10, 10, -10), 10);
	plane.material = new CheckerMaterial(0.1, 0);
	sphere1.material = new PhongMaterial(Color::Red(), Color::White(), 16,0);
	sphere2.material = new PhongMaterial(Color::Blue(), Color::White(), 16, 0);

	Union u;
	u.AddGeometry(&plane);
	u.AddGeometry(&sphere1);
	u.AddGeometry(&sphere2);

	RenderMaterial(&u, &Camera(Vector3(0, 5, 15), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);

	delete plane.material;
	delete sphere1.material;
	delete sphere2.material;
}


void CRayTracerView::OnRenderRayTraceButtonDown()
{
	// TODO:  在此添加命令处理程序代码
	Plane plane = Plane(Vector3(0, 1, 0), 0);
	Sphere sphere1 = Sphere(Vector3(-10, 10, -10), 10);
	Sphere sphere2 = Sphere(Vector3(10, 10, -10), 10);
	Sphere sphere3 = Sphere(Vector3(0, 3, -5), 3);
	plane.material = new CheckerMaterial(0.1, 0.6);
	sphere1.material = new PhongMaterial(Color::Red(), Color::White(), 16, 0.25);
	sphere2.material = new PhongMaterial(Color::Blue(), Color::White(), 16, 0.25);
	sphere3.material = new PhongMaterial(Color::Green(), Color::White(), 16, 0.25);

	Union u;
	u.AddGeometry(&plane);
	u.AddGeometry(&sphere1);
	u.AddGeometry(&sphere2);
	u.AddGeometry(&sphere3);

	RenderRayTrace(&u, &Camera(Vector3(0, 5, 15), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);

	delete plane.material;
	delete sphere1.material;
	delete sphere2.material;
	delete sphere3.material;
}


void CRayTracerView::RenderRayTrace(Geometry* scene, Camera* camera, int maxReflect)
{
	CDC* pDC = GetDC();

	if (scene == nullptr || camera == nullptr)
	{
		return;
	}
	int interectPointCount = 0;
	double i = 0;
	const int h = 750;//宽高都是512个像素点
	const int w = 750;
// #pragma omp parallel num_threads(4)
// #pragma omp parallel for
	for (int y = 0; y < h; y++)
	{
		double sy = 1 - (double)y / (double)h;//生成垂直方向的[0,1]坐标，因为左下角为(0,0)，所以x,y=0,0时sy应该是1。
// #pragma omp parallel for
		for (int x = 0; x < w; x++)
		{
// #pragma omp parallel for
			double sx = (double)x / (double)w;//生成垂直方向的[0,1]坐标
			Ray3 ray = camera->GenerateRay(sx, sy);//生成光线
			Color color = RayTraceRecursive(scene, &ray, maxReflect);
			color.Round();
			pDC->SetPixel(x, y, RGB(color.r * 255, color.g * 255, color.b * 255));
		}
	}
}

Color CRayTracerView::RayTraceRecursive(Geometry* scene, Ray3* ray, int maxReflect)
{
	IntersectResult result = scene->Intersect(*ray);

	if (result.geometry != nullptr)
	{
		double reflectiveness = result.geometry->material->reflectiveness;
		Color color = result.geometry->material->Sample(*ray, result.position, result.normal);
		color = color.Multiply(1 - reflectiveness);
		if (reflectiveness > 0 && maxReflect > 0)
		{
			Vector3 r = result.normal.Multiply(-2 * result.normal.Dot(ray->direction)).Add(ray->direction);
			ray = new Ray3(result.position, r);
			Color reflectedColor = RayTraceRecursive(scene, ray, maxReflect - 1);
			color = color.Add(reflectedColor.Multiply(reflectiveness));
			if(ray != nullptr) delete ray;
		}
		return color;
	}
	else
	{
		return Color::Black();
	}
}