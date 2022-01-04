Texture2D YUV420YTexture      : register(t0);
Texture2D YUV420UVTexture     : register(t1);
Texture2D Chroma420YTexture   : register(t2);
Texture2D Chroma420UVTexture  : register(t3);

SamplerState LinearSampler : register(s0);
SamplerState PointSampler  : register(s1);

struct PixelShaderInput
{
	float4 pos   : SV_POSITION;
	float2 uv    : TEXCOORD0;
	float4 color : COLOR0;
};

cbuffer ImageParams : register(b0)
{
	float width;
	float height;
};

float4 main(PixelShaderInput input) : SV_TARGET
{
	float4 Output;

	const float3 offset = { -0.0627451017, -0.501960814, -0.501960814 };
	const float3 Rcoeff = { 1.1644,  0.0000,  1.5960 };
	const float3 Gcoeff = { 1.1644, -0.3918, -0.8130 };
	const float3 Bcoeff = { 1.1644,  2.0172,  0.0000 };

	int2 pos = int2(input.uv * float2(width, height));
	float3 yuv444 = offset;

	// B1
	yuv444.r = YUV420YTexture.Sample(PointSampler, input.uv).r;

	if (pos.x % 2 == 1)
	{
		// B4 B5
		yuv444.g = Chroma420YTexture.Sample(PointSampler, float2(input.uv.x / 2, input.uv.y));
		yuv444.b = Chroma420YTexture.Sample(PointSampler, float2(input.uv.x / 2 + 0.5, input.uv.y));
	}
	else if (pos.x % 4 == 0 && pos.y % 2 == 1)
	{
		// B6 B7
		yuv444.g = Chroma420UVTexture.Sample(PointSampler, float2(input.uv.x / 2, input.uv.y)).r;
		yuv444.b = Chroma420UVTexture.Sample(PointSampler, float2(input.uv.x / 2 + 0.5, input.uv.y)).r;
	}
	else if (pos.x % 4 == 2 && pos.y % 2 == 1)
	{
		// B8 B9
		yuv444.g = Chroma420UVTexture.Sample(PointSampler, float2(input.uv.x / 2, input.uv.y)).g;
		yuv444.b = Chroma420UVTexture.Sample(PointSampler, float2(input.uv.x / 2 + 0.5, input.uv.y)).g;
	}
	else  if (pos.x % 2 == 0 && pos.y % 2 == 0)
	{
		// B2 B3
		yuv444.gb = YUV420UVTexture.Sample(PointSampler, input.uv).rg;
	}

	// yuv444 to rgba
	yuv444 += offset;
	Output.r = dot(yuv444, Rcoeff);
	Output.g = dot(yuv444, Gcoeff);
	Output.b = dot(yuv444, Bcoeff);
	Output.a = 1.0f;

	return Output;
}
