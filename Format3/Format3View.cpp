
// Format3View.cpp : CFormat3View クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "Format3.h"
#endif

#include "Format3Doc.h"
#include "Format3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFormat3View

IMPLEMENT_DYNCREATE(CFormat3View, CView)

BEGIN_MESSAGE_MAP(CFormat3View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormat3View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFormat3View コンストラクション/デストラクション

CFormat3View::CFormat3View()
{
	// TODO: 構築コードをここに追加します。

}

CFormat3View::~CFormat3View()
{
}

BOOL CFormat3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CFormat3View 描画

void CFormat3View::OnDraw(CDC* /*pDC*/)
{
	CFormat3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CFormat3View の印刷


void CFormat3View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFormat3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CFormat3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CFormat3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

void CFormat3View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFormat3View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFormat3View の診断

#ifdef _DEBUG
void CFormat3View::AssertValid() const
{
	CView::AssertValid();
}

void CFormat3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFormat3Doc* CFormat3View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFormat3Doc)));
	return (CFormat3Doc*)m_pDocument;
}
#endif //_DEBUG


// CFormat3View メッセージ ハンドラー
