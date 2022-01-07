#include "yuv_renderer.h"

YUVRenderer::YUVRenderer()
{

}

YUVRenderer::~YUVRenderer()
{

}

void YUVRenderer::RenderRGB(ID3D11Texture2D* rgb_texture)
{
	std::lock_guard<std::mutex> locker(mutex_);

	if (!d3d11_context_) {
		return;
	}

	D3D11_TEXTURE2D_DESC desc;
	rgb_texture->GetDesc(&desc);

	if (pixel_format_ != xop::PIXEL_FORMAT_ARGB ||
		width_ != desc.Width || height_ != desc.Height) {
		if (!CreateTexture(desc.Width, desc.Height, xop::PIXEL_FORMAT_ARGB)) {
			return;
		}
	}

	Begin();

	ID3D11Texture2D* argb_texture = input_textures_[xop::PIXEL_PLANE_ARGB]->GetTexture();
	ID3D11ShaderResourceView* argb_texture_svr = input_textures_[xop::PIXEL_PLANE_ARGB]->GetShaderResourceView();

	d3d11_context_->CopySubresourceRegion(
		argb_texture,
		0,
		0,
		0,
		0,
		(ID3D11Resource*)rgb_texture,
		0,
		NULL);

	xop::D3D11RenderTexture* render_target = render_targets_[xop::PIXEL_SHADER_ARGB].get();
	if (render_target) {
		render_target->Begin();
		render_target->PSSetTexture(0, argb_texture_svr);
		render_target->PSSetSamplers(0, linear_sampler_);
		render_target->PSSetSamplers(1, point_sampler_);
		render_target->Draw();
		render_target->End();
		render_target->PSSetTexture(0, NULL);
		output_texture_ = render_target;
	}

	End();
}

void YUVRenderer::RenderYUV(ID3D11Texture2D* yuv420_texture, ID3D11Texture2D* chroma420_texture)
{
	std::lock_guard<std::mutex> locker(mutex_);

	if (!d3d11_context_) {
		return;
	}

	D3D11_TEXTURE2D_DESC desc;
	yuv420_texture->GetDesc(&desc);

	if (pixel_format_ != xop::PIXEL_FORMAT_NV12 ||
		width_ != desc.Width || height_ != desc.Height) {
		if (!CreateTexture(desc.Width, desc.Height, xop::PIXEL_FORMAT_NV12)) {
			return;
		}
		pixel_format_ = xop::PIXEL_FORMAT_NV12;
	}

	Begin();

	auto& input_texture = input_textures_[xop::PIXEL_PLANE_NV12];
	ID3D11Texture2D* nv12_texture = input_texture->GetTexture();
	ID3D11ShaderResourceView* nv12_texture_y_srv = input_texture->GetNV12YShaderResourceView();
	ID3D11ShaderResourceView* nv12_texture_uv_srv = input_texture->GetNV12UVShaderResourceView();

	d3d11_context_->CopySubresourceRegion(
		nv12_texture,
		0,
		0,
		0,
		0,
		(ID3D11Resource*)yuv420_texture,
		0,
		NULL);

	xop::D3D11RenderTexture* render_target = render_targets_[xop::PIXEL_SHADER_NV12_BT601].get();

	if (render_target) {
		render_target->Begin();
		render_target->PSSetTexture(0, nv12_texture_y_srv);
		render_target->PSSetTexture(1, nv12_texture_uv_srv);
		render_target->PSSetSamplers(0, linear_sampler_);
		render_target->PSSetSamplers(1, point_sampler_);
		render_target->Draw();
		render_target->End();
		render_target->PSSetTexture(0, NULL);
		render_target->PSSetTexture(1, NULL);
		output_texture_ = render_target;
	}
	Process();
	End();
}
