
// Style9View.cpp : CStyle9View クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "Style9.h"
#endif

#include "Style9Doc.h"
#include "Style9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStyle9View

IMPLEMENT_DYNCREATE(CStyle9View, CView)

BEGIN_MESSAGE_MAP(CStyle9View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStyle9View コンストラクション/デストラクション

CStyle9View::CStyle9View()
{
	// TODO: 構築コードをここに追加します。

}

CStyle9View::~CStyle9View()
{
}

BOOL CStyle9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CStyle9View 描画

void CStyle9View::OnDraw(CDC* /*pDC*/)
{
	CStyle9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CStyle9View の印刷

BOOL CStyle9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CStyle9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CStyle9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CStyle9View の診断

#ifdef _DEBUG
void CStyle9View::AssertValid() const
{
	CView::AssertValid();
}

void CStyle9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStyle9Doc* CStyle9View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStyle9Doc)));
	return (CStyle9Doc*)m_pDocument;
}
#endif //_DEBUG


// CStyle9View メッセージ ハンドラー
