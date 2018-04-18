#include "DirectX.h"
#include "MyClass.h"
using namespace DX9;
using namespace MyClass;

bool DirectX::Init(System& win)
{
	if (direct3d.Create(win))
	{
		font.Create(direct3d.p_d3dDevice);

		back.sprite.Create(direct3d.p_d3dDevice);
		back.tex.Create(direct3d.p_d3dDevice,"bg_title.png");
		back.pos = { 0,0 };

		cursor.sprite.Create(direct3d.p_d3dDevice);
		cursor.tex.Create(direct3d.p_d3dDevice, "ƒJ[ƒ\ƒ‹.png");
		cursor.pos = { 0,50 };

		hoge.sprite.Create(direct3d.p_d3dDevice);
		hoge.tex.Create(direct3d.p_d3dDevice, "ƒJ[ƒ\ƒ‹.png");
		hoge.pos = { 200,200 };
		return true;
	}
	return false;
}
float r;
void DirectX::Update()
{
	++r;
	++cursor.pos.x;
	++cursor.pos.y;
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
		
		
		{
			Box src = { 0, 0, 960, 540 };
			Box draw (480,270,960,540);
			back.sprite.Draw(back.pos,draw.ToRECT(), src.ToRECT(), back.tex.Gettexture(), 0, D3DXVECTOR2(draw.x, draw.y));
		}
		{
			Box src = { 0, 0, 80, 80 };
			Box draw( 40,40,80,80);	//(’†S“_(x,y)•`‰æ”ÍˆÍ(w,h))
			cursor.sprite.Draw(cursor.pos,draw.ToRECT(), src.ToRECT(), cursor.tex.Gettexture(), r, draw.OffSet(cursor.pos.x, cursor.pos.y));
			font.Draw(GetColor(0, 0, 0), 0, 900, "%f\n%f", cursor.pos.x,draw.x);
		}
	
		hoge.sprite.SimpleDraw(hoge.tex.Gettexture(), hoge.pos);
		
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