
// Style1View.h : CStyle1View クラスのインターフェイス
//

#pragma once


class CStyle1View : public CView
{
protected: // シリアル化からのみ作成します。
	CStyle1View();
	DECLARE_DYNCREATE(CStyle1View)

// 属性
public:
	CStyle1Doc* GetDocument() const;

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
	virtual ~CStyle1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Style1View.cpp のデバッグ バージョン
inline CStyle1Doc* CStyle1View::GetDocument() const
   { return reinterpret_cast<CStyle1Doc*>(m_pDocument); }
#endif

