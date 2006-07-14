/*
  This file is part of Tibia Map Viewer.

  Tibia Map Viewer is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  Tibia Map Viewer is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Tibia Map Viewer; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__2DAA641F_4905_4DE9_B9C3_A185EDED41C5__INCLUDED_)
#define AFX_CHILDVIEW_H__2DAA641F_4905_4DE9_B9C3_A185EDED41C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_ObjSelCount;
	void UpdateCursor();
	void HideMarkDescriptions();
	void InvalidateObj(CContentObj *obj);
	void ActivateDefStyle();
	void SelectAll(BOOL Select = TRUE);
	int m_DefStyleIdx;
	void SetViewerMode();
	void SetArrowCursor();
	void MapToScreenRect(CRect *rect);
	void ScreenToMapRect(CRect* rect);
	CRect m_Selection;
	BOOL m_Moving;
	void SetEditorMode();
	CPoint MapToScreen(const CPoint &point);
	void InvalidateMapRect(CRect& rect);
	CPoint ScreenToMap(const CPoint& point);
	BOOL m_EditorMode;
	HCURSOR m_DefCur;
	HCURSOR m_DragHand2Cur;
	HCURSOR m_MagnifyCur;
	HCURSOR m_MagnifyCur2;
	HCURSOR SetViewCursor(HCURSOR cur);
	void UpdateCurrentStyle();
	virtual ~CChildView();

	// Generated message map functions
protected:
	void ChangeZoom(CPoint point, int NewIdx);
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDelete();
	afx_msg void OnInsertText();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnSelectMode();
	afx_msg void OnUpdateInsertText(CCmdUI* pCmdUI);
	afx_msg void OnUpdateSelectMode(CCmdUI* pCmdUI);
	afx_msg void OnEditStyles();
	afx_msg void OnUpdateEditStyles(CCmdUI* pCmdUI);
	afx_msg void OnUpdateDelete(CCmdUI* pCmdUI);
	afx_msg void OnInsertMark();
	afx_msg void OnUpdateInsertMark(CCmdUI* pCmdUI);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnHideunexploredsymbols();
	afx_msg void OnUpdateHideunexploredsymbols(CCmdUI* pCmdUI);
	afx_msg void OnProperties();
	afx_msg void OnUpdateProperties(CCmdUI* pCmdUI);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnToFront();
	afx_msg void OnUpdateToFront(CCmdUI* pCmdUI);
	afx_msg void OnToBack();
	afx_msg void OnUpdateToBack(CCmdUI* pCmdUI);
	//}}AFX_MSG
  afx_msg void OnUpdateStatusBar(CCmdUI* pCmdUI);
  afx_msg void OnUpdateStatusBarFileName(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_InPopup;
	void EditObject(CContentObj* obj);
	void SelClick(CPoint point);
	CMenu* m_Popup;
	BOOL m_CurHideUnexplored;
	int m_LastZoomIdx;
	BYTE m_NewObjectType;
	void DrawSelectionRect(CDC& dc);
	CPoint m_ptClick;
  CBitmap m_MemBmp;
  CDC m_MemDC;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__2DAA641F_4905_4DE9_B9C3_A185EDED41C5__INCLUDED_)