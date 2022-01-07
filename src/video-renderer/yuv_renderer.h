#pragma once

#include "d3d11_renderer.h"

class YUVRenderer : public xop::D3D11Renderer
{
public:
	YUVRenderer();
	virtual ~YUVRenderer();

	virtual void RenderRGB(ID3D11Texture2D* rgb_texture);
	virtual void RenderYUV(ID3D11Texture2D* yuv420_texture, ID3D11Texture2D* chroma420_texture);

private:

};
