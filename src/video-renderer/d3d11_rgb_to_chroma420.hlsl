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
    //const float3 offset = { 0.0627451017, 0.501960814, 0.501960814 };
    const float3 offset = float3(0.062, 0.501, 0.501);
    const float3 YCoeff = float3(0.257, 0.504, 0.098);
    const float3 UCoeff = float3(-0.148, -0.291, 0.439);
    const float3 VCoeff = float3(0.439, -0.368, -0.071);
    
    //const float3 YCoeff = float3(0.21260, 0.71520, 0.07220);
    //const float3 UCoeff = float3(-0.11457, -0.38543, 0.50000);
    //const float3 VCoeff = float3(0.50000, -0.45415, -0.04585);
    

    float3 coeff = UCoeff;
    int2 pos = int2(input.uv * float2(width, height));
    int  x_pos = pos.x;
    int  y_pos = pos.y;

    // Chroma420 - B4:U444(2x+1, y)  B5:V444(2x+1, y)
    if (pos.x <= (width / 2 - 1))
    {
        coeff = UCoeff;
    }
    else
    {
        coeff = VCoeff;
    }

    // B4 B5
    x_pos = pos.x * 2 + 1;
    x_pos = x_pos % width;
    float2 image_uv  = float2(x_pos / width, y_pos / height);
    float3 image_rgb = RGBTexture.Sample(PointSampler, image_uv).rgb;
    float  y = dot(image_rgb, coeff) + offset.y;

    // Chroma420 - B6:U444(4x,2y+1) B7:V444(4x,2y+1) B8:U444(4x+2,2y+1) B9:V444(4x+2,2y+1)
    if (pos.x <= (width / 4 - 1))
    {
        coeff = UCoeff;
    }
    else
    {
        coeff = VCoeff;
    }

    // B6 B7
    x_pos = pos.x * 4;
    x_pos = x_pos % width;
    y_pos = pos.y * 2 + 1;
    y_pos = y_pos % height;
    image_uv = float2(x_pos / width, y_pos / height);
    image_rgb = RGBTexture.Sample(PointSampler, image_uv).rgb;
    float u = dot(image_rgb, coeff) + offset.y;

    // B8 B9
    x_pos = pos.x * 4 + 2;
    x_pos = x_pos % width;
    y_pos = pos.y * 2 + 1;
    y_pos = y_pos % height;
    image_uv = float2(x_pos / width, y_pos / height);
    image_rgb = RGBTexture.Sample(PointSampler, image_uv).rgb;
    float v = dot(image_rgb, coeff) + offset.z;

    Output.YColor   = float4(y, 0, 0, 0);
    Output.UVClolor = float4(u, v, 0, 0);
    return Output;
}
