
// LeftView.cpp : CLeftView クラスの実装
//

#include "stdafx.h"
#include "Format2.h"

#include "Format2Doc.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
END_MESSAGE_MAP()


// CLeftView コンストラクション/デストラクション

CLeftView::CLeftView()
{
	// TODO: 構築コードをここに追加します。
}

CLeftView::~CLeftView()
{
}

BOOL CLeftView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs を変更して、Window クラスまたはスタイルを変更します。

	return CTreeView::PreCreateWindow(cs);
}

void CLeftView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO:  GetTreeCtrl() メンバー関数の呼び出しをとおして直接そのリスト コントロールに
	//  アクセスすることによって TreeView をアイテムで固定できます。
}


// CLeftView の診断

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CFormat2Doc* CLeftView::GetDocument() // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormat2Doc)));
	return (CFormat2Doc*)m_pDocument;
}
#endif //_DEBUG


// CLeftView メッセージ ハンドラー
