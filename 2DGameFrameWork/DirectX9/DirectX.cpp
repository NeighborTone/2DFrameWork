#include "DirectX.h"
#include "MyClass.h"
#include "../Game.h"
using namespace DX9;
using namespace MyClass;

bool DirectX::Init(System& win)
{
	if (direct3d.Create(win))
	{
		font.Create(direct3d.p_d3dDevice);

		for (int i = 0; i < 16; ++i)
		{
			rota[i].image.Load(direct3d.p_d3dDevice, "ƒJ[ƒ\ƒ‹.png");
			rota[i].vec2 = { 0 + (float)i * 80, 80 };

		}
	
		return true;
	}
	return false;
}
float r;
void DirectX::Update()
{
	r += 6;
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

		for (int i = 0; i < 16; ++i)
		{
			rota[i].src = { 0,0,80,80 };
			rota[i].draw = { 40,40,80,80 };
			rota[i].image.DrawRota(rota[i].vec2, r, rota[i].src, rota[i].draw);
		}
		
		//	font.Draw(GetColor(0, 0, 0), 0, 900, "%f\n%f", cursor.pos.x,draw.x);

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