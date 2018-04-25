#include "DirectX.h"
#include "../MyClass.h"

using namespace MyClass;

namespace DX9
{
	bool DirectX::Init(System& win)
	{
		if (direct3d.Create(win))
		{
			in.CreateInput(win.GetWindow());
			pad.CreatePadInput(win.GetWindow());
			scene = SceneManeger::GetInstance();
			scene->PushScene(new Game);
			return true;
		}
		return false;
	}

	void DirectX::Update()
	{
	
		scene->GetCurrentScene()->Update();
	}

	void DirectX::Draw()
	{
		//•`‰æŠJŽn
		if (SUCCEEDED(direct3d.p_d3dDevice->BeginScene()))
		{
			//”wŒiƒNƒŠƒA
			direct3d.p_d3dDevice->Clear(
				0,
				NULL,
				D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,
				GetColor(100, 149, 237),
				1.0f,
				0
			);

			scene->GetCurrentScene()->Draw();

			//•`‰æI—¹
			direct3d.p_d3dDevice->EndScene();
		}
		else
		{
			MessageBox(NULL, "•`‰æ‚ÉŽ¸”s‚µ‚Ü‚µ‚½", "Error", MB_OK);
		}
		//•`‰æ”½‰f
		direct3d.p_d3dDevice->Present(NULL, NULL, NULL, NULL);
	}
}
