
// GrafikaLabTestView.h : interface of the CGrafikaLabTestView class
//

#pragma once


class CGrafikaLabTestView : public CView
{
protected: // create from serialization only
	CGrafikaLabTestView() noexcept;
	bool m_showGrid = true;
	const float PI = 3.14159265f;
	DECLARE_DYNCREATE(CGrafikaLabTestView)

// Attributes
public:
	CGrafikaLabTestDoc* GetDocument() const;
	void DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle);
	void DrawPolygon(CDC* pDC, CPoint* points, int n);
	//CDC ima podatke za olovku,cetku,font i boju koji su CPen, CBrush, CFont i COLORREF. 
	//CDC je klasa koja se koristi za crtanje u MFC aplikacijama. 
	// Ona predstavlja kontekst ureðaja (device context) koji omoguæava crtanje na ekranu ili u datoteci. 
	// CPen je klasa koja predstavlja olovku koja se koristi za crtanje linija i obrisa oblika. 
	// CBrush je klasa koja predstavlja èetku koja se koristi za popunjavanje oblika bojom ili uzorkom. 
	// CFont je klasa koja predstavlja font koji se koristi za ispisivanje teksta. 
	// COLORREF je tip podataka koji predstavlja boju u RGB formatu.

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CGrafikaLabTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in GrafikaLabTestView.cpp
inline CGrafikaLabTestDoc* CGrafikaLabTestView::GetDocument() const
   { return reinterpret_cast<CGrafikaLabTestDoc*>(m_pDocument); }
#endif

