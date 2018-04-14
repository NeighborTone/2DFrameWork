#include "DX9_Texture.h"
using namespace DX9;
Texture::Texture()
{
	p_tex = nullptr;
}
Texture::~Texture()
{
	if (p_tex != nullptr)
	{
		p_tex->Release();
	}
}
bool Texture::Create(IDirect3DDevice9* device, const std::string path)
{
	//画像のサイズ情報等を取得
	D3DXGetImageInfoFromFile(path.c_str(), &info);
	//劣化したので使わない
	//if (FAILED(D3DXCreateTextureFromFileEx(
	//	device,								//Direct3Dのデバイス
	//	path.c_str(),						//ファイルパス
	//	info.Width,							//サイズ
	//	info.Height,						//
	//	NULL,									//ミップマップレベル(画像の補完)
	//	NULL,									//テクスチャのメモリの場所を指定
	//	D3DFMT_UNKNOWN,					//テクスチャのピクセルフォーマット
	//	D3DPOOL_MANAGED,					//メモリの位置と管理のフラグ
	//	D3DX_FILTER_POINT,				//画像のピクセル補完方法
	//	D3DX_DEFAULT,						//フィルタリング方法
	//	NULL,									//カラーキー。画像の透過職色
	//	NULL,									//D3DXIMAGE_INFOのポインタ。渡さない場合NULL
	//	NULL,									//画像のパレットへのポインタ
	//	&p_tex								//生成したオブジェクトのポインタ
	//)))

	if (FAILED(D3DXCreateTextureFromFile(device, path.c_str(), &p_tex)))
	{
		MessageBox(NULL, "画像の読み込みに失敗しました", "Error", MB_OK);
		return false;
	};
	
	return true;
}

