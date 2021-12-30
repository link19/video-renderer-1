#include "d3d11_rgb_to_yuv_converter.h"

using namespace xop;

D3D11RGBToYUVConverter::D3D11RGBToYUVConverter(ID3D11Device* d3d11_device)
	: d3d11_device_(d3d11_device)
{
	d3d11_device_->AddRef();
}

D3D11RGBToYUVConverter::~D3D11RGBToYUVConverter()
{
	Destroy();
	d3d11_device_->Release();
}

bool D3D11RGBToYUVConverter::Init(int yuv_width, int yuv_height)
{

	return true;
}

void D3D11RGBToYUVConverter::Destroy()
{

}
