#pragma once
#define NOMINMAX 

#include <string>
#include <wtypes.h> 
#include <vector>


/// <summary>
   /// 线段表
   /// </summary>
 struct LineSegmentMark
{
    /// <summary>
    /// 线段(0表示)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// 标注分界时间位置(标注不允许经过此时间)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// 起始点帧索引
    /// </summary>
     int StartFrameIndex;
    /// <summary>
    /// 结束点帧索引
    /// </summary>
     int EndFrameIndex;
    /// <summary>
    /// 起点位置在当前帧的索引
    /// </summary>
     int StartPointIndex;
    /// <summary>
    /// 结束点位置在当前帧的索引
    /// </summary>
     int EndPointIndex;
};

/// <summary>
/// 圆表（二维）
/// </summary>
 struct CircleMark
{
    /// <summary>
    /// 圆形(1表示)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// 圆心所在的帧索引
    /// </summary>
     int CircleFrameIndex;
    /// <summary>
    /// 圆心所在当前帧位置索引
    /// </summary>
     int CirclePLIndex;
    /// <summary>
    /// 圆的半径 mm
    /// </summary>
     float CircleRadius;
};


/// <summary>
/// 折线表（二维）
/// </summary>
struct PolylineMark
{
    /// <summary>
    /// 折线(2表示)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// 标注分界时间位置(标注不允许经过此时间)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// 折线上存在多少个点
    /// </summary>
     int PolylinePointCount;
    /// <summary>
    /// 折线上所有点对应的帧索引
    /// </summary>
     int* PolylineFramesIndex;
    /// <summary>
    /// 折线上所有点对应帧的点索引
    /// </summary>
     int* PolylinePointsIndex;
};

/// <summary>
/// 矩形表（二维）
/// </summary>
 struct RectangleMark
{
    /// <summary>
    /// 矩形(3表示)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// 标注分界时间位置(标注不允许经过此时间)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// 起始点对应的帧索引
    /// </summary>
     int RectangleSFIndex;
    /// <summary>
    /// 起始点对应帧的点索引
    /// </summary>
     int RectangleSPIndex;
    /// <summary>
    /// 结束点对应的帧索引
    /// </summary>
     int RectangleEFIndex;
    /// <summary>
    /// 结束点对应帧的点索引
    /// </summary>
     int RectangleEPIndex;
};


/// <summary>
/// 多变形表（二维）
/// </summary>
 struct PolygonMark
{
    /// <summary>
    /// 多边形(4表示)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// 标注分界时间位置(标注不允许经过此时间)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// 多边形上存在多少个点
    /// </summary>
     int PolygonPointCount;
    /// <summary>
    /// 多边形上第一个点的帧索引
    /// </summary>
     int* PolygonFramesIndex;
    /// <summary>
    /// 多边形上第一个点对应帧的点索引
    /// </summary>
     int* PolygonPointsIndex;

};

/// <summary>
/// 分层标识表（二维）
/// </summary>
 struct LayeredMark
{
    /// <summary>
    /// 分层标识(5表示)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// 标注分界时间位置(标注不允许经过此时间)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// 前线段起始点对应的帧索引
    /// </summary>
     int FLineSFrameIndex;
    /// <summary>
    /// 前线段结束点对应的帧索引
    /// </summary>
     int FLineEFrameIndex;
    /// <summary>
    /// 前线段起始点对应帧的点索引
    /// </summary>
     int FLineSPointIndex;
    /// <summary>
    /// 前线段结束点对应帧的点索引
    /// </summary>
     int FLileEPointIndex;
    /// <summary>
    /// 前线段的描述信息
    /// </summary>
     int FLineRemark;
    /// <summary>
    /// 后线段起始点对应的帧索引
    /// </summary>
     int RLineSFrameIndex;
    /// <summary>
    /// 后线段结束点对应的帧索引
    /// </summary>
     int RLineEFrameIndex;
    /// <summary>
    /// 后线段起始点对应帧的点索引
    /// </summary>
     int RLineSPointIndex;
    /// <summary>
    /// 后线段结束点对应帧的点索引
    /// </summary>
     int RLileEPointIndex;
    /// <summary>
    /// 后线段的描述信息
    /// </summary>
     int RLineRemark;
};


/// <summary>
/// 文件尾部
/// </summary>
 struct DrawMarks
{
     LineSegmentMark* lineSegments;
     int lineCnt; 
     CircleMark* circles;
     int circleCnt;
     PolylineMark* polylines;
     int polylineCnt;
     RectangleMark* rectangles;
     int rectangleCnt;
     RectangleMark* polygons;
     int polygonCnt;
     LayeredMark* layeredMarks;
     int layeredCnt;
};
  
 

 /// <summary>
 /// 雷达帧数据
 /// </summary>
 struct FrameData
 {
     float* points;   //点坐标x,y,z循环(x为行走方向，为当前距离值)
     int pointsLen;      //points指针数组长度
     float distance;  //当前距离(单位:m)
     float circleX;   //拟合圆心坐标X(单位:mm)
     float circleY;   //拟合圆心坐标Y(单位:mm)
 };



/// <summary>
/// 视图
/// </summary>
 enum  CamOrientation 
 {
     Front=0,
     Back,
     Left,
     Right,
     Up,
     Down,
     Axonometric
 };

/// <summary>
/// 绑定显示控件句柄
/// </summary>
/// <param name="hwd">控件句柄</param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <returns></returns>
extern "C" _declspec(dllexport) void* _stdcall BindingHandle(HWND hwd, int width, int height);

/// <summary>
/// 传入数据
/// </summary>
/// <param name="frameDatas">帧数据</param>
/// <param name="pointNum">帧总数</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall EntryData(FrameData* frameDatas, int pointNum);
 
/// <summary>
/// 设置管道参数
/// </summary>
/// <param name="pipeDiameter">管道直径</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall SetPipePara(int pipeDiameter);

/// <summary>
/// 设置标注数组
/// </summary>
/// <param name="drawMarks">标注指针</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall SetMarkArray(DrawMarks drawMarks);

/// <summary>
/// 显示/隐藏标注
/// </summary>
/// <param name="visible">true可见/false不可见</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall SetMarksVisible(bool visible);



extern "C" _declspec(dllexport) void _stdcall SetCameraOrientation(CamOrientation t_camOrientation);