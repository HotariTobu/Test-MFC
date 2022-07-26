
// Format3View.h : CFormat3View クラスのインターフェイス
//

#pragma once


class CFormat3View : public CView
{
protected: // シリアル化からのみ作成します。
	CFormat3View();
	DECLARE_DYNCREATE(CFormat3View)

// 属性
public:
	CFormat3Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 実装
public:
	virtual ~CFormat3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Format3View.cpp のデバッグ バージョン
inline CFormat3Doc* CFormat3View::GetDocument() const
   { return reinterpret_cast<CFormat3Doc*>(m_pDocument); }
#endif

