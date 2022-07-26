
// LeftView.h : CLeftView クラスのインターフェイス
//


#pragma once

class CFormat2Doc;

class CLeftView : public CTreeView
{
protected: // シリアル化からのみ作成します。
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// 属性
public:
	CFormat2Doc* GetDocument();

// 操作
public:

// オーバーライド
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // 構築後に初めて呼び出されます。

// 実装
public:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LeftView.cpp のデバッグ バージョン
inline CFormat2Doc* CLeftView::GetDocument()
   { return reinterpret_cast<CFormat2Doc*>(m_pDocument); }
#endif

