#include "DirectX.h"
#include "../MyClass.h"

using namespace MyClass;

namespace DX9
{
	bool DirectX::Init(System& win)
	{
		
		if (direct3D->GetInst()->Create(win))
		{
			in.CreateInput(win.GetWindow());
			pad.CreatePadInput(win.GetWindow());
			mouse.CreateMousenput(win.GetWindow());
			system->GetSystem()->Create();
			font.Create();
			//

			return true;
		}
		return false;
	}

	void DirectX::Update()
	{
		mouse.UpDate();
		mouse.GetMousePos();

	}

	void DirectX::Draw()
	{
		//•`‰æŠJŽn
		if (SUCCEEDED(direct3D->GetInst()->GetDevice()->BeginScene()))
		{
			//”wŒiƒNƒŠƒA
			direct3D->GetInst()->GetDevice()->Clear(
				0,
				NULL,
				D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER,
				GetColor(0, 0, 0),
				1.0f,
				0
			);
			//--------------------
			//ƒ}ƒEƒX‚ÌÀ•W•\Ž¦
			font.Draw(0xffffffff,0,0,"x%d  y%d",mouse.pos.x,mouse.pos.y);
			//•`‰æI—¹
			direct3D->GetInst()->GetDevice()->EndScene();
		}
		else
		{
			MessageBox(NULL, "•`‰æ‚ÉŽ¸”s‚µ‚Ü‚µ‚½", "Error", MB_OK);
		}
		//•`‰æ”½‰f
		direct3D->GetInst()->GetDevice()->Present(NULL, NULL, NULL, NULL);
	}

	void DirectX::End()
	{
	
		
	}
	
}