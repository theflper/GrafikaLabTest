
// GrafikaLabTestView.cpp : implementation of the CGrafikaLabTestView class
//include "pch.h" uvek prva linija inace puca kod
#include "pch.h"
#include "framework.h"
#include <vector>
using namespace std;
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GrafikaLabTest.h"
#endif

#include "GrafikaLabTestDoc.h"
#include "GrafikaLabTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGrafikaLabTestView

IMPLEMENT_DYNCREATE(CGrafikaLabTestView, CView)

BEGIN_MESSAGE_MAP(CGrafikaLabTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGrafikaLabTestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CGrafikaLabTestView construction/destruction

CGrafikaLabTestView::CGrafikaLabTestView() noexcept
{
	// TODO: add construction code here

}

CGrafikaLabTestView::~CGrafikaLabTestView()
{
}

BOOL CGrafikaLabTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGrafikaLabTestView drawing ova funkcija crta sve!!!

void CGrafikaLabTestView::OnDraw(CDC* pDC)
{
	CGrafikaLabTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//siva pozadina za 500*500 piksela
	pDC->FillSolidRect(0, 0, 500, 500, RGB(210, 210, 210));
	/*Primer crtanja jednog objekta
	1. Kreiramo roze olovku sa okruglim spojevima
	CPen pinkPen;
	pinkPen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_JOIN_ROUND, 2, RGB(255, 0, 255));

	2. Kreiramo obiènu èetku (ili stavimo NULL_BRUSH ako je providno)
	CBrush brush(RGB(255, 192, 203)); // Primer: svetlo roze ispun
	Postavljanje providne (šuplje) èetke jer je ona defaultno ugraðena
	CBrush* pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);

	3. Selektujemo ih u pDC i hvatamo stare objekte
	CPen* pOldPen = pDC->SelectObject(&pinkPen);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	4. Pozivamo našu funkciju za crtanje (npr. pravougaonik ili poligon)
	DrawRegularPolygon(pDC, cx, cy, r, n, rotAngle);

	5. Vraæamo stare objekte na stek (obavezno!)
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	*/
	CPen pinkPen;
	// PS_GEOMETRIC | PS_SOLID znaèi geometrijska puna linija
	// PS_JOIN_ROUND definiše zaobljene spojeve izmeðu linija
	pinkPen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_JOIN_ROUND, 4, RGB(255, 0, 255));
	//ljubièasta èetka
	CBrush purpleBrush(RGB(130, 0, 160));
	//sad selektovanje i pamæenje starih vrednosti
	CPen* pOldPen = pDC->SelectObject(&pinkPen);
	CBrush* pOldBrush = pDC->SelectObject(&purpleBrush);
	//ono što crtamo
	std::vector<CPoint> points = { CPoint(100, 175) , CPoint(100, 100), CPoint(175, 175),CPoint(175, 250) };
	DrawPolygon(pDC, points.data(), points.size());
	//crtaj
	//vrati stare vredonsti
	//olovka je ista svuda pa ne mora još
	//pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
	//sledeci je roze trougao
	CBrush lightPinkBrush(RGB(255, 182, 203));
	pOldBrush = pDC->SelectObject(&lightPinkBrush);
	points = { CPoint(175, 175) , CPoint(175, 325), CPoint(325, 325) };
	DrawPolygon(pDC, points.data(), points.size());
	pDC->SelectObject(pOldBrush);
	//kvadrat moram preko tačaka da ispadne lepo
	CBrush redBrush(RGB(255, 0, 0));
	pOldBrush = pDC->SelectObject(&redBrush);
	/*
	points = { CPoint(175, 325) , CPoint(175, 400), CPoint(250, 400),CPoint(250, 325) };
	DrawPolygon(pDC, points.data(), points.size());
	*/
	DrawRegularPolygon(pDC,212,362,53,4,0);	
	pDC->SelectObject(pOldBrush);
	//zeleni trougao
	CBrush greenBrush(RGB(50, 255, 100));
	pOldBrush = pDC->SelectObject(&greenBrush);
	points = { CPoint(325, 325) , CPoint(325, 400), CPoint(400, 400) };
	DrawPolygon(pDC, points.data(), points.size());
	pDC->SelectObject(pOldBrush);
	//narandžast trougao
	CBrush orangeBrush(RGB(255, 165, 0));
	pOldBrush = pDC->SelectObject(&orangeBrush);
	points = { CPoint(250, 250) , CPoint(400, 250), CPoint(400, 400) };
	DrawPolygon(pDC, points.data(), points.size());
	pDC->SelectObject(pOldBrush);
	//žut trougao
	CBrush yellowBrush(RGB(255, 255, 0));
	pOldBrush = pDC->SelectObject(&yellowBrush);
	points = { CPoint(400, 175) , CPoint(400, 250), CPoint(475, 175) };
	DrawPolygon(pDC, points.data(), points.size());
	pDC->SelectObject(pOldBrush);
	//čudan trougao
	int oldBkMode = pDC->SetBkMode(OPAQUE);
	COLORREF oldBkColor = pDC->SetBkColor(RGB(255, 255, 255)); // Bela pozadina unutar šablona
	CBrush hatchBrush;
	// Kreiramo četku sa linijama pod 45 stepeni i definisanom bojom linija šablona
	hatchBrush.CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 255)); // Plave linije šablona kao na slici ili roze/crne po potrebi
	pOldBrush = pDC->SelectObject(&hatchBrush);
	points = { CPoint(100, 175) , CPoint(175, 250), CPoint(25, 250) };
	DrawPolygon(pDC, points.data(), points.size());
	pDC->SelectObject(pOldBrush);
	//na kraju menjam olovku jer je duže koristim
	pDC->SelectObject(pOldPen);
	//sad tanja roze olovka
	CPen pinkPenThin;
	// PS_GEOMETRIC | PS_SOLID znaèi geometrijska puna linija
	// PS_JOIN_ROUND definiše zaobljene spojeve izmeðu linija
	pinkPenThin.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_JOIN_ROUND, 3, RGB(255, 0, 255));
	pOldPen = pDC->SelectObject(&pinkPenThin);
	pOldBrush = (CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	DrawRegularPolygon(pDC,100,220,20,4,45);
	DrawRegularPolygon(pDC,218,280,23,5,54);
	DrawRegularPolygon(pDC,355,295,23,6,0);
	DrawRegularPolygon(pDC,345,377,13,7,64.286f);
	DrawRegularPolygon(pDC,420,197,13,8,67.5f);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	pDC->SetBkColor(oldBkColor);
	pDC->SetBkMode(oldBkMode);
	
	//grid se crta na kraju posle ostatka jer ide preko slike
	if (m_showGrid)
	{
		// Petlje koje crtaju linije mreže na svakih 50 piksela do 500x500
		// PS_SOLID znaèi puna linija, debljina 1, bela boja RGB(255, 255, 255)
		CPen gridPen(PS_SOLID, 1, RGB(255, 255, 255));
		//pravilo uvke selektuj prethodnu olovku
		CPen* pOldPen = pDC->SelectObject(&gridPen);
		for (int x = 0; x <= 500; x += 25)
		{
			pDC->MoveTo(x, 0);
			pDC->LineTo(x, 500);
		}
		for (int y = 0; y <= 500; y += 25)
		{
			pDC->MoveTo(0, y);
			pDC->LineTo(500, y);
		}

		pDC->SelectObject(pOldPen); // Vraæanje stare olovke
	}
}


// CGrafikaLabTestView printing


void CGrafikaLabTestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGrafikaLabTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGrafikaLabTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGrafikaLabTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGrafikaLabTestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGrafikaLabTestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGrafikaLabTestView diagnostics

#ifdef _DEBUG
void CGrafikaLabTestView::AssertValid() const
{
	CView::AssertValid();
}

void CGrafikaLabTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGrafikaLabTestDoc* CGrafikaLabTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGrafikaLabTestDoc)));
	return (CGrafikaLabTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CGrafikaLabTestView message handlers

#define _USE_MATH_DEFINES
#include <cmath>

void CGrafikaLabTestView::DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle)
{
	if (n < 3) return;

	// Pretvaramo unete stepene u radijane
	float rotAngleRad = rotAngle * (PI / 180.0f);

	CPoint* points = new CPoint[n];
	float angleStep = 2.0f * PI / n;

	// Precizan opšti pomak: -90 stepeni (-PI/2) i još pola koraka (-PI/n)
	float baseOffset = (-PI / 2.0f) - (PI / n);

	for (int i = 0; i < n; ++i)
	{
		float alfa = rotAngleRad + baseOffset + (i * angleStep);

		int x = cx + (int)round(r * cos(alfa));
		int y = cy + (int)round(r * sin(alfa));
		points[i] = CPoint(x, y);
	}

	pDC->Polygon(points, n);
	delete[] points;
}

void CGrafikaLabTestView::DrawPolygon(CDC* pDC, CPoint* points, int n)
{
	if (points == nullptr || n < 3) return;
	// Postavljamo Winding režim da bi se ispravno bojili konkavni poligoni
	int oldMode = pDC->SetPolyFillMode(WINDING);
	// Crtanje poligona
	pDC->Polygon(points, n);
	// Vraæamo stari mod na mesto
	pDC->SetPolyFillMode(oldMode);
}
//Class wizard,messages, key down event handler
void CGrafikaLabTestView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	// Proveravamo da li je pritisnut taster 'G' ili 'g'
	if (nChar == 'G' || nChar == 'g')
	{
		m_showGrid = !m_showGrid; // Menja stanje iz true u false i obrnuto
		Invalidate();             // Poziva ponovno iscrtavanje prozora (poziva OnDraw)
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
