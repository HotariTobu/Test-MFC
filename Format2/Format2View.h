
// Format2View.h : CFormat2View クラスのインターフェイス
//

#pragma once


class CFormat2View : public CListView
{
protected: // シリアル化からのみ作成します。
	CFormat2View();
	DECLARE_DYNCREATE(CFormat2View)

// 属性
public:
	CFormat2Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 構築後に初めて呼び出されます。

// 実装
public:
	virtual ~CFormat2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Format2View.cpp のデバッグ バージョン
inline CFormat2Doc* CFormat2View::GetDocument() const
   { return reinterpret_cast<CFormat2Doc*>(m_pDocument); }
#endif

