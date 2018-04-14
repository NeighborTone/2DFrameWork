#include "DirectX.h"
#include "Define.hpp"
using namespace DX9;

bool DirectX::Init(System& win)
{
	if (direct3d.Create(win))
	{
		font.Create(direct3d.p_d3dDevice);
		tex.Create(direct3d.p_d3dDevice,"bg_title.png");
		sprite.pos = { 480,270 };



		return true;
	}
	return false;
}

void DirectX::Update()
{
	
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
		sprite.Draw(direct3d.p_d3dDevice, tex);
		font.Draw(GetColor(255,255,255),0,0,"AAAAAA\nBBBBBB");
		//•`‰æI—¹
		direct3d.p_d3dDevice->EndScene();
	}
	else
	{
		MessageBox(NULL, "•`‰æ‚ÉŽ¸”s‚µ‚Ü‚µ‚½", "Error", MB_OK);
	}
	//•`‰æ”½‰f
	direct3d.p_d3dDevice->Present(NULL,NULL, NULL,NULL);
}