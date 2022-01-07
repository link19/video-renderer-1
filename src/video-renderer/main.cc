#include "main_window.h"
#include "yuv_renderer.h"
#include "d3d11_screen_capture.h"
#include "d3d11_rgb_to_yuv_converter.h"
#include "d3d11_yuv_to_rgb_converter.h"

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")


int main(int argc, char** argv)
{
	bool is_double_frame = false;

	MainWindow window;
	window.SetMessageCallback([&is_double_frame](UINT msg, WPARAM wp, LPARAM lp, LRESULT* result) {
		if (wp == VK_SPACE) {
			is_double_frame = !is_double_frame;
		}
	});
	if (!window.Init(100, 100, 3440 * 4 / 5, 1440 * 4 / 5)) {
		return -1;
	}

	YUVRenderer renderer;
	if (!renderer.Init(window.GetHandle())) {
		return -2;
	}

	DX::D3D11ScreenCapture screen_capture;
	if (!screen_capture.Init()) {
		return -3;
	}

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT) {
		if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			continue;
		}
		else {
			DX::Image argb_image;
			if (screen_capture.Capture(argb_image)) {
				IDXGISwapChain* swap_chain = renderer.GetDXGISwapChain();
				ID3D11Device* d3d11_device = renderer.GetD3D11Device();
				ID3D11Texture2D* argb_texture = NULL;

				HRESULT hr = d3d11_device->OpenSharedResource((HANDLE)(uintptr_t)argb_image.shared_handle,
					__uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&argb_texture));
				if (FAILED(hr)) {
					break;
				}

				xop::D3D11RGBToYUVConverter yuv_converter(swap_chain);
				yuv_converter.Init(argb_image.width, argb_image.height);
				yuv_converter.Convert(argb_texture);
				

				if (is_double_frame) {
					xop::D3D11YUVToRGBConverter rgb_converter(swap_chain);
					rgb_converter.Init(argb_image.width, argb_image.height);
					rgb_converter.Combine(yuv_converter.GetYUV420Texture(), yuv_converter.GetChroma420Texture());
					renderer.RenderRGB(rgb_converter.GetRGBATexture());
				}
				else {
					renderer.RenderYUV(yuv_converter.GetYUV420Texture(), NULL);
				}
				argb_texture->Release();
			}
		}
	}

	return 0;
}
