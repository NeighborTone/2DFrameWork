#include "DX9_Texture.h"
namespace DX9
{
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
	bool Texture::Create(const std::string path)
	{
		// ‰æ‘œ“Ç‚İ‚İ
		D3DXGetImageInfoFromFile(path.c_str(), &info);
		if (FAILED(D3DXCreateTextureFromFileEx(
			direct3d.p_d3dDevice,
			path.c_str(),
			info.Width, info.Height,
			NULL,
			NULL,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_FILTER_POINT,
			D3DX_DEFAULT,
			NULL,
			NULL,
			NULL,
			&p_tex
		)))
		{
			MessageBox(NULL, "‰æ‘œ‚Ì“Ç‚İ‚İ‚É¸”s‚µ‚Ü‚µ‚½", "Error", MB_OK);
			return false;

		}
		return true;

	}


}
