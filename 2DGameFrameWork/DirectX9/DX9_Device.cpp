#include "DX9_Device.h"
//グローバルな変数があるので、名前空間に入れる(usingはダメ)
namespace DX9
{
	Direct3D direct3d;

	Direct3D::Direct3D()
	{
		p_d3d = nullptr;
		p_d3dDevice = nullptr;
	}

	Direct3D::~Direct3D()
	{
		if (p_d3d != nullptr)
		{
			p_d3d->Release();
		}
		if (p_d3dDevice != nullptr)
		{
			p_d3dDevice->Release();
		}
	}

	bool Direct3D::Create(System& win)
	{
		//IDirect3D9コンポーネント取得
		if (NULL == (p_d3d = Direct3DCreate9(D3D_SDK_VERSION))) { return false; }
		// ディスプレイ情報取得(これを取得してフォーマットを指定しないとフルスクリーンにならない)
		D3DDISPLAYMODE display;
		p_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &display);

		D3DPRESENT_PARAMETERS parameter;
		SecureZeroMemory(&parameter, sizeof(parameter));

		parameter.BackBufferWidth = win.Width();											//バックバッファ(裏画面)設定値
		parameter.BackBufferHeight = win.Height();										//
		parameter.BackBufferFormat = display.Format;									//画面のフォーマット情報
		parameter.BackBufferCount = 0;														//バックバッファの数
		parameter.MultiSampleType = D3DMULTISAMPLE_NONE;							//マルチサンプル数（これを上げると画像がきれいになる）
		parameter.MultiSampleQuality = 0;													//マルチサンプルの品質(NONEなら0でいい)
		parameter.SwapEffect = D3DSWAPEFFECT_DISCARD;								//フロントバッファとバックバッファの切り替え方法。とりあえずはこれでおｋ
		parameter.hDeviceWindow = win.GetWindow();										//画面を描画するウィンドウハンドル。nullなら現在フォーカスされているウィンドウが使用される
		parameter.Windowed = true;															//ウィンドウサイズの切り替え。trueならウィンドウモード
		parameter.EnableAutoDepthStencil = true;										//深度ステンシルバッファ、3Dを使うならtrue一択(Zバッファとマスク機能)
		parameter.AutoDepthStencilFormat = D3DFMT_D24S8;							//ステンシルバッファのフォーマット
		parameter.Flags = 0;																		//バックバッファからフロントバッファへ転送するときのオプション
		parameter.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;		//リフレッシュレート、ウインドウなら0にする
		parameter.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;		//スワップの書き換えタイミング
																			//HALモードでデバイス生成
		if (FAILED(p_d3d->CreateDevice(
			D3DADAPTER_DEFAULT,																	//ディスプレイアダプタの番号。基本変更しない
			D3DDEVTYPE_HAL,																		//描画処理をハードウェアで行う
			parameter.hDeviceWindow,															//描画を行うウィンドウハンドル
			D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
			&parameter,
			&p_d3dDevice))
			)
			if (FAILED(p_d3d->CreateDevice(
				D3DADAPTER_DEFAULT,
				D3DDEVTYPE_HAL,
				parameter.hDeviceWindow,
				D3DCREATE_MIXED_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
				&parameter,
				&p_d3dDevice))
				)
				// REFモードで3Dデバイス作成
				if (FAILED(p_d3d->CreateDevice(
					D3DADAPTER_DEFAULT,
					D3DDEVTYPE_REF,
					parameter.hDeviceWindow,
					D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
					&parameter,
					&p_d3dDevice))
					)
					if (FAILED(p_d3d->CreateDevice(
						D3DADAPTER_DEFAULT,
						D3DDEVTYPE_REF,
						parameter.hDeviceWindow,
						D3DCREATE_SOFTWARE_VERTEXPROCESSING | D3DCREATE_MULTITHREADED,
						&parameter,
						&p_d3dDevice))
						)

					{
						MessageBox(parameter.hDeviceWindow, "デバイスの生成に失敗しました", "Error", MB_OK);
						p_d3d->Release();
						return false;
					}



		p_d3dDevice->SetRenderState(D3DRS_ZENABLE, true);								//これ以降の描画にZバッファを適用
		p_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);				//カリングをオン（ポリゴンの裏を描画しない）
		p_d3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);				//アルファブレンドを有効にする
		p_d3dDevice->SetRenderState(D3DRS_LIGHTING, false);							//ライトなし
																					//ソースデータとデステネーションデータのブレンド
		p_d3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		p_d3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);



		return true;
	}

}

