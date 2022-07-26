
// Style9View.h : CStyle9View クラスのインターフェイス
//

#pragma once


class CStyle9View : public CView
{
protected: // シリアル化からのみ作成します。
	CStyle9View();
	DECLARE_DYNCREATE(CStyle9View)

// 属性
public:
	CStyle9Doc* GetDocument() const;

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
	virtual ~CStyle9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Style9View.cpp のデバッグ バージョン
inline CStyle9Doc* CStyle9View::GetDocument() const
   { return reinterpret_cast<CStyle9Doc*>(m_pDocument); }
#endif

