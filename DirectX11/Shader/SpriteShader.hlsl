// テクスチャ
Texture2D g_texture : register(t0);
// サンプラ
SamplerState g_sampler : register(s0);

// 頂点シェーダーから出力するデータ
struct VSOutput
{
    float4 Pos : SV_Position;   // 頂点の座標(射影座標系)
    float2 UV : TEXCOORD0;      // UV座標
    float4 Color : COLOR0;//色
};

//========================================
// 頂点シェーダー
//========================================
VSOutput VS(float4 pos : POSITION,
    float2 uv : TEXUV, 
    float4 col:COLOR0)
{
    VSOutput Out;
    // 頂点座標を、何も加工せずそのまま出力
    Out.Pos = pos;
    // 頂点のUV座標を、何も加工せずそのまま出力
    Out.UV = uv;
    Out.Color = col;
    return Out;
}

//========================================
// ピクセルシェーダー
//========================================
float4 PS(VSOutput In) : SV_Target0
{
    // テクスチャから色を取得
    //float4 texColor = g_texture.Sample(g_sampler, In.UV);
    //カラーから色を取得
    float4 texColor = In.Color;

// 緑色にする
return texColor;
}