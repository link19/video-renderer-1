#include "d3d11_rgb_to_yuv_converter.h"

using namespace xop;

D3D11RGBToYUVConverter::D3D11RGBToYUVConverter(IDXGISwapChain* swap_chain)
	: swap_chain_(swap_chain)
{
	swap_chain_->AddRef();
	swap_chain->GetDevice(__uuidof(ID3D11Device), (void**)&d3d11_device_);
	d3d11_device_->GetImmediateContext(&d3d11_context_);
}

D3D11RGBToYUVConverter::~D3D11RGBToYUVConverter()
{
	Destroy();	

	d3d11_context_->Release();
	d3d11_device_->Release();
	swap_chain_->Release();
}

bool D3D11RGBToYUVConverter::Init(int width, int height)
{
	main_texture_.reset(new D3D11RenderTexture(swap_chain_));
	auxiliary_texture_.reset(new D3D11RenderTexture(swap_chain_));

	D3D11_USAGE usage = D3D11_USAGE_DYNAMIC;
	UINT bind_flags = D3D11_BIND_SHADER_RESOURCE;
	UINT cpu_flags = D3D11_CPU_ACCESS_WRITE;

	main_texture_->InitTexture(width, height, DXGI_FORMAT_NV12, usage, bind_flags, cpu_flags, 0);
	auxiliary_texture_->InitTexture(width, height, DXGI_FORMAT_NV12, usage, bind_flags, cpu_flags, 0);

	return true;
}

void D3D11RGBToYUVConverter::Destroy()
{
	main_texture_.reset();
	auxiliary_texture_.reset();
}