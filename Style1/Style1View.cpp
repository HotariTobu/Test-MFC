
// Style1View.cpp : CStyle1View クラスの実装
//

#include "stdafx.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "Style1.h"
#endif

#include "Style1Doc.h"
#include "Style1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStyle1View

IMPLEMENT_DYNCREATE(CStyle1View, CView)

BEGIN_MESSAGE_MAP(CStyle1View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CStyle1View コンストラクション/デストラクション

CStyle1View::CStyle1View()
{
	// TODO: 構築コードをここに追加します。

}

CStyle1View::~CStyle1View()
{
}

BOOL CStyle1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CStyle1View 描画

void CStyle1View::OnDraw(CDC* /*pDC*/)
{
	CStyle1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}


// CStyle1View の印刷

BOOL CStyle1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CStyle1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CStyle1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CStyle1View の診断

#ifdef _DEBUG
void CStyle1View::AssertValid() const
{
	CView::AssertValid();
}

void CStyle1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStyle1Doc* CStyle1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStyle1Doc)));
	return (CStyle1Doc*)m_pDocument;
}
#endif //_DEBUG


// CStyle1View メッセージ ハンドラー
