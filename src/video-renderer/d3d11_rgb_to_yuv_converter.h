#pragma once

#include "d3d11_render_texture.h"
#include <memory>

namespace xop {

class D3D11RGBToYUVConverter
{
public:
	D3D11RGBToYUVConverter(IDXGISwapChain* swap_chain);
	virtual ~D3D11RGBToYUVConverter();

	bool Init(int width, int height);
	void Destroy();

	bool Convert(ID3D11Texture2D* argb_texture);
	bool Recovery(ID3D11Texture2D* main_texture, ID3D11Texture2D* auxiliary_texture);

	ID3D11Texture2D* GetMainTexture();
	ID3D11Texture2D* GetAuxiliaryTexture();

private:
	IDXGISwapChain* swap_chain_ = NULL;
	ID3D11Device* d3d11_device_ = NULL;
	ID3D11DeviceContext* d3d11_context_ = NULL;
	std::unique_ptr<D3D11RenderTexture> main_texture_;
	std::unique_ptr<D3D11RenderTexture> auxiliary_texture_;
};

}
