//==========================================================
//
//   DirextXの初期化 [main.cpp]
//									 Author :
//									 Date   :
//==========================================================
#include "main.h"

#include "scene.h"


//==========================================================
// ライブラリのリンク
//==========================================================
#pragma comment (lib, "d3d11.lib")		
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "d3dx11.lib")	
#pragma comment (lib, "d3dx9.lib")	
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "dxerr.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "dinput8.lib")

//==========================================================
// マクロ定義
//==========================================================
#define CLASS_NAME			"GameWindow"				// ウインドウのクラス名
#define WINDOW_CAPTION		"DirectXの初期化"			// ウインドウのキャプション名

//==========================================================
// 構造体定義
//==========================================================

//==========================================================
// プロトタイプ宣言
//==========================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);
void Uninit(void);
void Update(void);
void Draw(void);


//==========================================================
// グローバル変数:
//==========================================================

#ifdef _DEBUG
	int		g_CountFPS;							// FPSカウンタ
	char	g_DebugStr[2048] = WINDOW_CAPTION;	// デバッグ文字表示用
#endif

//==========================================================
// メイン関数
//==========================================================
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);	// 無くても良いけど、警告が出る（未使用宣言）
	UNREFERENCED_PARAMETER(lpCmdLine);		// 無くても良いけど、警告が出る（未使用宣言）

	// 時間計測用
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;

	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);

	RegisterClass(&wc);

	// ウィンドウの作成
	HWND hWnd = CreateWindow(CLASS_NAME,
		WINDOW_CAPTION,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,																		// ウィンドウの左座標
		CW_USEDEFAULT,																		// ウィンドウの上座標
		SCREEN_WIDTH + GetSystemMetrics(SM_CXDLGFRAME) * 2,									// ウィンドウ横幅
		SCREEN_HEIGHT + GetSystemMetrics(SM_CXDLGFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION),	// ウィンドウ縦幅
		NULL,
		NULL,
		hInstance,
		NULL);

	// DirectXの初期化(ウィンドウを作成してから行う)
	if (FAILED(Init(hInstance, hWnd, true)))
	{
		return -1;
	}

	// フレームカウント初期化
	timeBeginPeriod(1);	// 分解能を設定
	dwExecLastTime = dwFPSLastTime = timeGetTime();	// システム時刻をミリ秒単位で取得
	dwCurrentTime = dwFrameCount = 0;

	// ウインドウの表示(Init()の後に呼ばないと駄目)
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MSG			msg;

	// メッセージループ
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{// PostQuitMessage()が呼ばれたらループ終了
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			dwCurrentTime = timeGetTime();					// システム時刻を取得

			if ((dwCurrentTime - dwFPSLastTime) >= 1000)	// 1秒ごとに実行
			{
#ifdef _DEBUG
				g_CountFPS = dwFrameCount;
#endif
				dwFPSLastTime = dwCurrentTime;				// FPSを測定した時刻を保存
				dwFrameCount = 0;							// カウントをクリア
			}

			if ((dwCurrentTime - dwExecLastTime) >= (1000 / 60))	// 1/60秒ごとに実行
			{
				dwExecLastTime = dwCurrentTime;	// 処理した時刻を保存

#ifdef _DEBUG	// デバッグ版の時だけFPSを表示する
				wsprintf(g_DebugStr, WINDOW_CAPTION);
				wsprintf(&g_DebugStr[strlen(g_DebugStr)], " FPS:%d", g_CountFPS);
				SetWindowText(hWnd, g_DebugStr);
#endif

				Update();			// 更新処理
				Draw();				// 描画処理
				CheckScene();

				dwFrameCount++;		// 処理回数のカウントを加算
			}
		}
	}

	timeEndPeriod(1);				// 分解能を戻す

	// 終了処理
	Uninit();

	return (int)msg.wParam;
}

//==========================================================
// プロシージャ
//==========================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		break;

	case WM_CLOSE:
		if (MessageBox(hWnd, "本当に終了してよろしいですか？", "確認", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK) {
			DestroyWindow(hWnd);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	};

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//==========================================================
// 初期化処理
//==========================================================
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	//入力処理の初期化
	InitInput(hInstance, hWnd);

	// レンダリング処理の初期化
	InitRenderer(hInstance, hWnd, bWindow);

	//スプライト初期化
	InitSprite();	

	//サウンド初期化
	InitSound(hWnd);

	//ゲーム起動時のシーン設定
	InitScene(SCENE::SCENE_TITLE);

	return S_OK;
}


//==========================================================
// 終了処理
//==========================================================
void Uninit(void)
{
	//入力処理の終了処理
	UninitInput();

	// レンダリングの終了処理
	UninitRenderer();

	//スプライトの終了処理
	UninitSprite();

	//テクスチャの解放
	UninitTexture();
	
	//サウンドの終了処理
	UninitSound();

	UninitScene();

}

//==========================================================
// 更新処理
//==========================================================
void Update(void)
{
	//入力処理の更新処理(Updateの中で最初のほうに書く)
	UpdateInput();



	UpdateScene();


}

//==========================================================
// 描画処理
//==========================================================
void Draw(void)
{
	// バックバッファクリア
	Clear();

	// 2D描画なので深度無効
	SetDepthEnable(false);


	DrawScene();

	// バックバッファ、フロントバッファ入れ替え
	Present();
}


