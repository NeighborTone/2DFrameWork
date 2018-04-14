#include "Mainloop.h"


bool Mainloop::Init(HINSTANCE hInstance, int nCmdShow)
{
	window.SetWindowSize(1280, 960);
	//ウィンドウ生成
	const bool iswin = 	window.Create("test",hInstance, nCmdShow);
	//DirectX9のデバイス生成
	const bool isDirectX = directx.Init(window);
	//ウィンドウ描画
	const bool isshow = ShowWindow(window.GetWindow(), nCmdShow);
	if (!iswin  || isDirectX || isshow)
	{
		return false;
	}
	return true;
}


void Mainloop::Run()
{
	//メッセージを取得
	GetMessage(&msg, NULL, 0, 0);
	//メッセージループ(入力などの命令を読む)
	while (msg.message != WM_QUIT)
	{
	
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			//メッセージをデコードしてWinProcに渡す
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			directx.Update();
			directx.Draw();
		}

	//	ShowCursor(false);	//マウス非表示
	
	}
}
