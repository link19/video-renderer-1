#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 10.1
//
// Parameters:
//
//   sampler2D USampler;
//   sampler2D VSampler;
//   sampler2D YSampler;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   YSampler     s0       1
//   USampler     s1       1
//   VSampler     s2       1
//

    ps_2_0
    def c0, -0.0627451017, -0.501960814, -0.501960814, 1
    def c1, 1.16439998, 0, 1.79270005, 0
    def c2, 1.16439998, -0.213200003, -0.532899976, 0
    def c3, 1.16439998, 2.11240005, 0, 0
    dcl t0.xy  // input<4,5>
    dcl_2d s0
    dcl_2d s1
    dcl_2d s2

#line 54 "G:\video-renderer\video-renderer\src\video-renderer\shader\d3d9\d3d9_yuv_bt709.hlsl"
    texld r0, t0, s0
    texld r1, t0, s1
    texld r2, t0, s2
    mov r0.x, r0.x  // ::yuv<0>
    mov r0.y, r1.x  // ::yuv<1>
    mov r0.z, r2.x  // ::yuv<2>
    add r0.xyz, r0, c0  // ::yuv<0,1,2>
    dp3 r1.x, r0, c1  // ::Output<0>
    dp3 r1.y, r0, c2  // ::Output<1>
    dp3 r1.z, r0, c3  // ::Output<2>

#line 64
    mov r1.x, r1.x  // ::main<0>
    mov r1.y, r1.y  // ::main<1>
    mov r1.z, r1.z  // ::main<2>
    mov r1.w, c0.w  // ::main<3>

#line 44
    mov oC0, r1  // ::main<0,1,2,3>

// approximately 15 instruction slots used (3 texture, 12 arithmetic)
#endif

const BYTE shader_d3d9_yuv_bt709[] =
{
      0,   2, 255, 255, 254, 255, 
    184,   0,  68,  66,  85,  71, 
     40,   0,   0,   0, 180,   2, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 124,   0, 
      0,   0,  23,   0,   0,   0, 
    128,   0,   0,   0,   4,   0, 
      0,   0, 100,   2,   0,   0, 
    116,   1,   0,   0,  71,  58, 
     92, 118, 105, 100, 101, 111, 
     45, 114, 101, 110, 100, 101, 
    114, 101, 114,  92, 118, 105, 
    100, 101, 111,  45, 114, 101, 
    110, 100, 101, 114, 101, 114, 
     92, 115, 114,  99,  92, 118, 
    105, 100, 101, 111,  45, 114, 
    101, 110, 100, 101, 114, 101, 
    114,  92, 115, 104,  97, 100, 
    101, 114,  92, 100,  51, 100, 
     57,  92, 100,  51, 100,  57, 
     95, 121, 117, 118,  95,  98, 
    116,  55,  48,  57,  46, 104, 
    108, 115, 108,   0,  40,   0, 
      0,   0,   0,   0, 255, 255, 
    204,   3,   0,   0,   0,   0, 
    255, 255, 228,   3,   0,   0, 
      0,   0, 255, 255, 252,   3, 
      0,   0,   0,   0, 255, 255, 
     20,   4,   0,   0,   0,   0, 
    255, 255,  44,   4,   0,   0, 
      0,   0, 255, 255,  56,   4, 
      0,   0,   0,   0, 255, 255, 
     68,   4,   0,   0,   0,   0, 
    255, 255,  80,   4,   0,   0, 
     54,   0,   0,   0,  92,   4, 
      0,   0,  55,   0,   0,   0, 
    108,   4,   0,   0,  56,   0, 
      0,   0, 124,   4,   0,   0, 
     54,   0,   0,   0, 140,   4, 
      0,   0,  55,   0,   0,   0, 
    152,   4,   0,   0,  56,   0, 
      0,   0, 164,   4,   0,   0, 
     58,   0,   0,   0, 176,   4, 
      0,   0,  59,   0,   0,   0, 
    192,   4,   0,   0,  60,   0, 
      0,   0, 208,   4,   0,   0, 
     61,   0,   0,   0, 224,   4, 
      0,   0,  64,   0,   0,   0, 
    240,   4,   0,   0,  64,   0, 
      0,   0, 252,   4,   0,   0, 
     64,   0,   0,   0,   8,   5, 
      0,   0,  64,   0,   0,   0, 
     20,   5,   0,   0,  44,   0, 
      0,   0,  32,   5,   0,   0, 
     79, 117, 116, 112, 117, 116, 
      0, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     16,   0,   0,   0, 255, 255, 
      1,   0, 255, 255, 255, 255, 
     17,   0,   0,   0, 255, 255, 
    255, 255,   2,   0, 255, 255, 
    109,  97, 105, 110,   0, 105, 
    110, 112, 117, 116,   0, 112, 
    111, 115,   0, 117, 118,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   2,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     99, 111, 108, 111, 114,   0, 
    171, 171, 127,   1,   0,   0, 
     64,   1,   0,   0, 131,   1, 
      0,   0, 136,   1,   0,   0, 
    152,   1,   0,   0,  64,   1, 
      0,   0,   5,   0,   0,   0, 
      1,   0,  10,   0,   1,   0, 
      3,   0, 160,   1,   0,   0, 
      4,   0,   0,   0,   4,   0, 
      5,   0, 255, 255, 255, 255, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,  19,   0, 
      0,   0, 255, 255,   1,   0, 
    255, 255, 255, 255,  20,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0, 255, 255,  21,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   3,   0,  22,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0, 121, 117, 
    118,   0,   1,   0,   3,   0, 
      1,   0,   3,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     11,   0,   0,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     12,   0,   0,   0, 255, 255, 
      1,   0, 255, 255, 255, 255, 
     13,   0,   0,   0, 255, 255, 
    255, 255,   2,   0, 255, 255, 
     14,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
      0,   0,   0,   0,  56,   1, 
      0,   0,  64,   1,   0,   0, 
      3,   0,   0,   0,  80,   1, 
      0,   0, 116,   1,   0,   0, 
    121,   1,   0,   0, 184,   1, 
      0,   0,   1,   0,   0,   0, 
    200,   1,   0,   0,   0,   0, 
      0,   0, 116,   1,   0,   0, 
    212,   1,   0,   0,   5,   0, 
      0,   0, 228,   1,   0,   0, 
      0,   0,   0,   0,  32,   2, 
      0,   0,  36,   2,   0,   0, 
      4,   0,   0,   0,  52,   2, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
    254, 255,  56,   0,  67,  84, 
     65,  66,  28,   0,   0,   0, 
    179,   0,   0,   0,   0,   2, 
    255, 255,   3,   0,   0,   0, 
     28,   0,   0,   0,   5,   1, 
      0,   0, 172,   0,   0,   0, 
     88,   0,   0,   0,   3,   0, 
      1,   0,   1,   0,   0,   0, 
    100,   0,   0,   0,   0,   0, 
      0,   0, 116,   0,   0,   0, 
      3,   0,   2,   0,   1,   0, 
      0,   0, 128,   0,   0,   0, 
      0,   0,   0,   0, 144,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0, 156,   0, 
      0,   0,   0,   0,   0,   0, 
     85,  83,  97, 109, 112, 108, 
    101, 114,   0, 171, 171, 171, 
      4,   0,  12,   0,   1,   0, 
      1,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  86,  83, 
     97, 109, 112, 108, 101, 114, 
      0, 171, 171, 171,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  89,  83,  97, 109, 
    112, 108, 101, 114,   0, 171, 
    171, 171,   4,   0,  12,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    112, 115,  95,  50,  95,  48, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     49,  48,  46,  49,   0, 171, 
     81,   0,   0,   5,   0,   0, 
     15, 160, 129, 128, 128, 189, 
    129, 128,   0, 191, 129, 128, 
      0, 191,   0,   0, 128,  63, 
     81,   0,   0,   5,   1,   0, 
     15, 160,  15,  11, 149,  63, 
      0,   0,   0,   0,  50, 119, 
    229,  63,   0,   0,   0,   0, 
     81,   0,   0,   5,   2,   0, 
     15, 160,  15,  11, 149,  63, 
     26,  81,  90, 190,  34, 108, 
      8, 191,   0,   0,   0,   0, 
     81,   0,   0,   5,   3,   0, 
     15, 160,  15,  11, 149,  63, 
    144,  49,   7,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,   3, 176, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   0,   8,  15, 160, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   1,   8,  15, 160, 
     31,   0,   0,   2,   0,   0, 
      0, 144,   2,   8,  15, 160, 
     66,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 176, 
      0,   8, 228, 160,  66,   0, 
      0,   3,   1,   0,  15, 128, 
      0,   0, 228, 176,   1,   8, 
    228, 160,  66,   0,   0,   3, 
      2,   0,  15, 128,   0,   0, 
    228, 176,   2,   8, 228, 160, 
      1,   0,   0,   2,   0,   0, 
      1, 128,   0,   0,   0, 128, 
      1,   0,   0,   2,   0,   0, 
      2, 128,   1,   0,   0, 128, 
      1,   0,   0,   2,   0,   0, 
      4, 128,   2,   0,   0, 128, 
      2,   0,   0,   3,   0,   0, 
      7, 128,   0,   0, 228, 128, 
      0,   0, 228, 160,   8,   0, 
      0,   3,   1,   0,   1, 128, 
      0,   0, 228, 128,   1,   0, 
    228, 160,   8,   0,   0,   3, 
      1,   0,   2, 128,   0,   0, 
    228, 128,   2,   0, 228, 160, 
      8,   0,   0,   3,   1,   0, 
      4, 128,   0,   0, 228, 128, 
      3,   0, 228, 160,   1,   0, 
      0,   2,   1,   0,   1, 128, 
      1,   0,   0, 128,   1,   0, 
      0,   2,   1,   0,   2, 128, 
      1,   0,  85, 128,   1,   0, 
      0,   2,   1,   0,   4, 128, 
      1,   0, 170, 128,   1,   0, 
      0,   2,   1,   0,   8, 128, 
      0,   0, 255, 160,   1,   0, 
      0,   2,   0,   8,  15, 128, 
      1,   0, 228, 128, 255, 255, 
      0,   0
};
