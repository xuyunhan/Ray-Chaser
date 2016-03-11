
// RayTracerView.cpp : CRayTracerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CRayTracerView ����/����

CRayTracerView::CRayTracerView()
	: Image(NULL)
{
	// TODO:  �ڴ˴���ӹ������
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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
// 	cs.cx = 500;
// 	cs.cy = 500;
// 	cs.style &= ~WS_MAXIMIZEBOX;
// 	cs.style &= ~WS_THICKFRAME;
	return CView::PreCreateWindow(cs);
}

// CRayTracerView ����

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


// CRayTracerView ���

#ifdef _DEBUG
void CRayTracerView::AssertValid() const
{
	CView::AssertValid();
}

void CRayTracerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRayTracerDoc* CRayTracerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRayTracerDoc)));
	return (CRayTracerDoc*)m_pDocument;
}
#endif //_DEBUG


// CRayTracerView ��Ϣ�������

 
// //��Ⱦ���ͼ��
void CRayTracerView::RenderDepth(Sphere* scene, Camera* camera, double maxDepth)
{
	CDC* pDC = GetDC();

	if (scene == nullptr || camera == nullptr)
	{
		return;
	}
	int interectPointCount = 0;
	double i = 0;
	const int h = 512;//��߶���512�����ص�
	const int w = 512;
	for (int y = 0; y < h; y ++)
	{
		double sy = 1 - (double)y / (double)h;//���ɴ�ֱ�����[0,1]���꣬��Ϊ���½�Ϊ(0,0)������x,y=0,0ʱsyӦ����1��
		for (int x = 0; x < w; x ++)
		{
			double sx = (double)x / (double)w;//���ɴ�ֱ�����[0,1]����
			Ray3 ray = camera->GenerateRay(sx, sy);//���ɹ���
			IntersectResult result = scene->Intersect(ray);//�볡���ཻ��
			if (result.geometry != nullptr)//���н���
			{
				interectPointCount++;//����
				int depth = 255 - min((int)((result.distance / maxDepth) * 255.0), 255);//��¼������Ϊ���ֵ
// 				Image[x][y] = depth;
				pDC->SetPixel(x, y, RGB(depth, depth, depth));//��
			}
			else
			{
				pDC->SetPixel(x, y, RGB(0, 0, 0));//��
			}
		}
	}
	CString string;
	string.Format("��������%d", interectPointCount);
// 	MessageBox((string));
// 	CString::Format("������: %d", interectPointCount);
// 	MessageBox(("hello wolrd"), _T("�ʺ�"), MB_OK);
// 	string.Format("������: %d", interectPointCount); //��������װ���ַ�����
// 	MessageBox(string, "��Ϣ�����", MB_OK);
// 	MessageBox("ddd");
// 	MessageBox("��������%d", interectPointCount);
}


void CRayTracerView::RenderDepthButtonDown()
{
	// TODO:  �ڴ���������������
	RenderDepth(&Sphere(Vector3(0, 10, -10), 10), &Camera(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0),90), 20);
}


void CRayTracerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	RenderDepth(&Sphere(Vector3(0, 10, -10), 10), &Camera(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);

	CView::OnLButtonUp(nFlags, point);
}


// ��Ⱦ������
void CRayTracerView::RenderNormal(Sphere* scene, Camera* camera, double maxDepth)
{
	CDC* pDC = GetDC();

	if (scene == nullptr || camera == nullptr)
	{
		return;
	}
	int interectPointCount = 0;
	double i = 0;
	const int h = 512;//��߶���512�����ص�
	const int w = 512;
	for (int y = 0; y < h; y++)
	{
		double sy = 1 - (double)y / (double)h;//���ɴ�ֱ�����[0,1]���꣬��Ϊ���½�Ϊ(0,0)������x,y=0,0ʱsyӦ����1��
		for (int x = 0; x < w; x++)
		{
			double sx = (double)x / (double)w;//���ɴ�ֱ�����[0,1]����
			Ray3 ray = camera->GenerateRay(sx, sy);//���ɹ���
			IntersectResult result = scene->Intersect(ray);//�볡���ཻ��
			if (result.geometry != nullptr)//���н���
			{
				interectPointCount++;//����
// 				int depth = 255 - min((int)((result.distance / maxDepth) * 255.0), 255);//��¼������Ϊ���ֵ
// 				Image[x][y] = depth;

				pDC->SetPixel(x, y, RGB((result.normal.x + 1) * 128, (result.normal.y + 1) * 128, (result.normal.z + 1) * 128));
			}
			else
			{
				pDC->SetPixel(x, y, RGB(0, 0, 0));//��
			}
		}
	}
}

// ��Ⱦ����
void CRayTracerView::RenderMaterial(Geometry* scene, Camera* camera, double maxDepth)
{
	CDC* pDC = GetDC();

	if (scene == nullptr || camera == nullptr)
	{
		return;
	}
	int interectPointCount = 0;
	double i = 0;
	const int h = 512;//��߶���512�����ص�
	const int w = 512;
	for (int y = 0; y < h; y++)
	{
		double sy = 1 - (double)y / (double)h;//���ɴ�ֱ�����[0,1]���꣬��Ϊ���½�Ϊ(0,0)������x,y=0,0ʱsyӦ����1��
		for (int x = 0; x < w; x++)
		{
			double sx = (double)x / (double)w;//���ɴ�ֱ�����[0,1]����
			Ray3 ray = camera->GenerateRay(sx, sy);//���ɹ���
			IntersectResult result = scene->Intersect(ray);//�볡���ཻ��
			if (result.geometry != nullptr)//���н���
			{
				interectPointCount++;//����
// 				Geometry* g = result.geometry;
// 				Material *a = new CheckerMaterial();
// 				CheckerMaterial* m = g->material;
				Color color = result.geometry->material->Sample(ray, result.position, result.normal);
				color.Round();

				pDC->SetPixel(x, y, RGB(color.r * 255, color.g * 255, color.b * 255));
			}
			else
			{
				pDC->SetPixel(x, y, RGB(0, 0, 0));//����ɫ
			}
		}
	}
}


void CRayTracerView::RenderNormalButtonDown()
{
	// TODO:  �ڴ���������������
	RenderNormal(&Sphere(Vector3(0, 10, -10), 10), &Camera(Vector3(0, 10, 10), Vector3(0, 0, -1), Vector3(0, 1, 0), 90), 20);
}


void CRayTracerView::OnRenderMaterialButtonDown()
{
	// TODO:  �ڴ���������������
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
	// TODO:  �ڴ���������������
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
	const int h = 750;//��߶���512�����ص�
	const int w = 750;
// #pragma omp parallel num_threads(4)
// #pragma omp parallel for
	for (int y = 0; y < h; y++)
	{
		double sy = 1 - (double)y / (double)h;//���ɴ�ֱ�����[0,1]���꣬��Ϊ���½�Ϊ(0,0)������x,y=0,0ʱsyӦ����1��
// #pragma omp parallel for
		for (int x = 0; x < w; x++)
		{
// #pragma omp parallel for
			double sx = (double)x / (double)w;//���ɴ�ֱ�����[0,1]����
			Ray3 ray = camera->GenerateRay(sx, sy);//���ɹ���
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