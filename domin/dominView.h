
// dominView.h : interface of the CdominView class
//

#pragma once

#include"HCN.h"
#include"Banco.h"
class CdominView : public CView
{
protected: // create from serialization only
	CdominView() noexcept;
	DECLARE_DYNCREATE(CdominView)

// Attributes
public:
	CdominDoc* GetDocument() const;

// Operations
public:
	Banco banco;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CdominView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in dominView.cpp
inline CdominDoc* CdominView::GetDocument() const
   { return reinterpret_cast<CdominDoc*>(m_pDocument); }
#endif

