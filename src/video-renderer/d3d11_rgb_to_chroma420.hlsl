Texture2D RGBTexture      : register(t0);

SamplerState PointSampler : register(s0);

struct PixelShaderInput
{
    float4 pos   : SV_POSITION;
    float2 uv    : TEXCOORD0;
    float4 color : COLOR0;
};

struct PixelShaderOutput
{
    float4  YColor   : SV_Target0;
    float4  UVClolor : SV_Target1;
};

cbuffer RGBParams : register(b0)
{
    float width;
    float height;
};

PixelShaderOutput main(PixelShaderInput input) : SV_TARGET
{
    PixelShaderOutput Output;

    const float3 UCoeff = float3(-0.115, -0.385, 0.500);
    const float3 VCoeff = float3(0.500, -0.454, -0.046);
    
    int2   pos = int2(input.uv * float2(width, height));
    float3 coeff = UCoeff;
    float  offset = 0.5;

    // Chroma420 - B4:U444(2x+1, y)  B5:V444(2x+1, y)
	if (pos.x <= (width / 2 - 1))
	{
		// B4
        coeff = UCoeff;
	}
    else
    {
        // B5
        coeff = VCoeff;
    }

    // B4  B5
    float2 image_uv  = float2((pos.x*2 + 1) / width, pos.y / height);
    float3 image_rgb = RGBTexture.Sample(PointSampler, image_uv).rgb;
    float  y = dot(image_rgb, coeff) + offset;

    // Chroma420 - B6:U444(4x,2y+1) B7:V444(4x,2y+1) B8:U444(4x+2,2y+1) B9:V444(4x+2,2y+1)
    if (pos.x <= (width / 4 - 1))
    {
        // B6 B8
        coeff = UCoeff;
    }
    else
    {
        // B7 B9
        coeff = VCoeff;
    }

    // B6 B7
    image_uv = float2((pos.x * 4) / width, (pos.y * 2 + 1) / height);
    image_rgb = RGBTexture.Sample(PointSampler, image_uv).rgb;
    float  u = dot(image_rgb, coeff) + offset;

    // B8 B9
    image_uv = float2((pos.x * 4 + 2) / width, (pos.y * 2 + 1) / height);
    image_rgb = RGBTexture.Sample(PointSampler, image_uv).rgb;
    float v = dot(image_rgb, coeff) + offset;

    Output.YColor   = float4(y, 0, 0, 0);
    Output.UVClolor = float4(u, v, 0, 0);
    return Output;
}
