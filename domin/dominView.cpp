
// dominView.cpp : implementation of the CdominView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "domin.h"
#endif

#include "dominDoc.h"
#include "dominView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include"HCN.h"

// CdominView

IMPLEMENT_DYNCREATE(CdominView, CView)

BEGIN_MESSAGE_MAP(CdominView, CView)
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CdominView construction/destruction

CdominView::CdominView() noexcept
{
	// TODO: add construction code here

}

CdominView::~CdominView()
{
}

BOOL CdominView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CdominView drawing

void CdominView::OnDraw(CDC* /*pDC*/)
{
	CdominDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CClientDC pdc(this);
	banco.vehinh(&pdc);
	// TODO: add draw code for native data here
}


// CdominView diagnostics

#ifdef _DEBUG
void CdominView::AssertValid() const
{
	CView::AssertValid();
}

void CdominView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdominDoc* CdominView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdominDoc)));
	return (CdominDoc*)m_pDocument;
}
#endif //_DEBUG


// CdominView message handlers


void CdominView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	banco.Bambanco(&pdc, point);
	CView::OnLButtonUp(nFlags, point);
}


void CdominView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC pdc(this);
	banco.Camco(&pdc, point);
	CView::OnRButtonUp(nFlags, point);
}




