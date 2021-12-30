#pragma once
#include "d3d11_render_texture.h"

namespace xop {

class D3D11RGBToYUVConverter
{
public:
	D3D11RGBToYUVConverter(ID3D11Device* d3d11_device);
	virtual ~D3D11RGBToYUVConverter();

	bool Init(int width, int height);
	void Destroy();

	bool Convert(ID3D11Texture2D* argb_texture);
	bool Recovery(ID3D11Texture2D* main_texture, ID3D11Texture2D* auxiliary_texture);

	ID3D11Texture2D* GetMainTexture();
	ID3D11Texture2D* GetAuxiliaryTexture();

private:
	ID3D11Device* d3d11_device_ = NULL;
};

}
