
// Format2.cpp : アプリケーションのクラス動作を定義します。
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Format2.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "Format2Doc.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFormat2App

BEGIN_MESSAGE_MAP(CFormat2App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CFormat2App::OnAppAbout)
	// 標準のファイル基本ドキュメント コマンド
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CFormat2App の構築

CFormat2App::CFormat2App()
{
	m_bHiColorIcons = TRUE;

	// 再起動マネージャーをサポートします
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// アプリケーションが共通言語ランタイム サポート (/clr) を使用して作成されている場合:
	//     1) この追加設定は、再起動マネージャー サポートが正常に機能するために必要です。
	//     2) 作成するには、プロジェクトに System.Windows.Forms への参照を追加する必要があります。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 下のアプリケーション ID 文字列を一意の ID 文字列で置換します。推奨される
	// 文字列の形式は CompanyName.ProductName.SubProduct.VersionInformation です
	SetAppID(_T("Format2.AppID.NoVersion"));

	// TODO: この位置に構築用コードを追加してください。
	// ここに InitInstance 中の重要な初期化処理をすべて記述してください。
}

// 唯一の CFormat2App オブジェクト

CFormat2App theApp;


// CFormat2App の初期化

BOOL CFormat2App::InitInstance()
{
	// アプリケーション マニフェストが visual スタイルを有効にするために、
	// ComCtl32.dll Version 6 以降の使用を指定する場合は、
	// Windows XP に InitCommonControlsEx() が必要です。さもなければ、ウィンドウ作成はすべて失敗します。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// アプリケーションで使用するすべてのコモン コントロール クラスを含めるには、
	// これを設定します。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE ライブラリを初期化します。
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// RichEdit コントロールを使用するには AfxInitRichEdit2() が必要です
	// AfxInitRichEdit2();

	// 標準初期化
	// これらの機能を使わずに最終的な実行可能ファイルの
	// サイズを縮小したい場合は、以下から不要な初期化
	// ルーチンを削除してください。
	// 設定が格納されているレジストリ キーを変更します。
	// TODO: 会社名または組織名などの適切な文字列に
	// この文字列を変更してください。
	SetRegistryKey(_T("アプリケーション ウィザードで生成されたローカル アプリケーション"));
	LoadStdProfileSettings(4);  // 標準の INI ファイルのオプションをロードします (MRU を含む)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// アプリケーション用のドキュメント テンプレートを登録します。ドキュメント テンプレート
	//  はドキュメント、フレーム ウィンドウとビューを結合するために機能します。
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_Format2TYPE,
		RUNTIME_CLASS(CFormat2Doc),
		RUNTIME_CLASS(CChildFrame), // カスタム MDI 子フレーム
		RUNTIME_CLASS(CLeftView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// メイン MDI フレーム ウィンドウを作成します。
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// DDE、file open など標準のシェル コマンドのコマンド ラインを解析します。
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// コマンド ラインで指定されたディスパッチ コマンドです。アプリケーションが
	// /RegServer、/Register、/Unregserver または /Unregister で起動された場合、False を返します。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// メイン ウィンドウが初期化されたので、表示と更新を行います。
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CFormat2App::ExitInstance()
{
	//TODO: 追加したリソースがある場合にはそれらも処理してください
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CFormat2App メッセージ ハンドラー


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// ダイアログを実行するためのアプリケーション コマンド
void CFormat2App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CFormat2App のカスタマイズの読み込みと保存方法

void CFormat2App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CFormat2App::LoadCustomState()
{
}

void CFormat2App::SaveCustomState()
{
}

// CFormat2App メッセージ ハンドラー



