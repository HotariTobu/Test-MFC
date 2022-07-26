
// Format2View.cpp : CFormat2View クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "Format2.h"
#endif

#include "Format2Doc.h"
#include "Format2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFormat2View

IMPLEMENT_DYNCREATE(CFormat2View, CListView)

BEGIN_MESSAGE_MAP(CFormat2View, CListView)
	ON_WM_STYLECHANGED()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFormat2View コンストラクション/デストラクション

CFormat2View::CFormat2View()
{
	// TODO: 構築コードをここに追加します。

}

CFormat2View::~CFormat2View()
{
}

BOOL CFormat2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CListView::PreCreateWindow(cs);
}

void CFormat2View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl() メンバー関数の呼び出しをとおして直接そのリスト コントロールに
	//  アクセスすることによって ListView をアイテムで固定できます。
}

void CFormat2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFormat2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFormat2View の診断

#ifdef _DEBUG
void CFormat2View::AssertValid() const
{
	CListView::AssertValid();
}

void CFormat2View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CFormat2Doc* CFormat2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormat2Doc)));
	return (CFormat2Doc*)m_pDocument;
}
#endif //_DEBUG


// CFormat2View メッセージ ハンドラー
void CFormat2View::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
	//TODO: ユーザーが変更するウィンドウのビュー スタイルに対応するコードを追加してください
	CListView::OnStyleChanged(nStyleType,lpStyleStruct);
}
