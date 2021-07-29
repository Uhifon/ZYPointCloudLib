#pragma once
#define NOMINMAX 

#include <string>
#include <wtypes.h> 
#include <vector>


/// <summary>
   /// �߶α�
   /// </summary>
 struct LineSegmentMark
{
    /// <summary>
    /// �߶�(0��ʾ)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// ��ע�ֽ�ʱ��λ��(��ע����������ʱ��)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// ��ʼ��֡����
    /// </summary>
     int StartFrameIndex;
    /// <summary>
    /// ������֡����
    /// </summary>
     int EndFrameIndex;
    /// <summary>
    /// ���λ���ڵ�ǰ֡������
    /// </summary>
     int StartPointIndex;
    /// <summary>
    /// ������λ���ڵ�ǰ֡������
    /// </summary>
     int EndPointIndex;
};

/// <summary>
/// Բ����ά��
/// </summary>
 struct CircleMark
{
    /// <summary>
    /// Բ��(1��ʾ)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// Բ�����ڵ�֡����
    /// </summary>
     int CircleFrameIndex;
    /// <summary>
    /// Բ�����ڵ�ǰ֡λ������
    /// </summary>
     int CirclePLIndex;
    /// <summary>
    /// Բ�İ뾶 mm
    /// </summary>
     float CircleRadius;
};


/// <summary>
/// ���߱���ά��
/// </summary>
struct PolylineMark
{
    /// <summary>
    /// ����(2��ʾ)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// ��ע�ֽ�ʱ��λ��(��ע����������ʱ��)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// �����ϴ��ڶ��ٸ���
    /// </summary>
     int PolylinePointCount;
    /// <summary>
    /// ���������е��Ӧ��֡����
    /// </summary>
     int* PolylineFramesIndex;
    /// <summary>
    /// ���������е��Ӧ֡�ĵ�����
    /// </summary>
     int* PolylinePointsIndex;
};

/// <summary>
/// ���α���ά��
/// </summary>
 struct RectangleMark
{
    /// <summary>
    /// ����(3��ʾ)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// ��ע�ֽ�ʱ��λ��(��ע����������ʱ��)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// ��ʼ���Ӧ��֡����
    /// </summary>
     int RectangleSFIndex;
    /// <summary>
    /// ��ʼ���Ӧ֡�ĵ�����
    /// </summary>
     int RectangleSPIndex;
    /// <summary>
    /// �������Ӧ��֡����
    /// </summary>
     int RectangleEFIndex;
    /// <summary>
    /// �������Ӧ֡�ĵ�����
    /// </summary>
     int RectangleEPIndex;
};


/// <summary>
/// ����α���ά��
/// </summary>
 struct PolygonMark
{
    /// <summary>
    /// �����(4��ʾ)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// ��ע�ֽ�ʱ��λ��(��ע����������ʱ��)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// ������ϴ��ڶ��ٸ���
    /// </summary>
     int PolygonPointCount;
    /// <summary>
    /// ������ϵ�һ�����֡����
    /// </summary>
     int* PolygonFramesIndex;
    /// <summary>
    /// ������ϵ�һ�����Ӧ֡�ĵ�����
    /// </summary>
     int* PolygonPointsIndex;

};

/// <summary>
/// �ֲ��ʶ����ά��
/// </summary>
 struct LayeredMark
{
    /// <summary>
    /// �ֲ��ʶ(5��ʾ)
    /// </summary>
     unsigned char MarkType;
    /// <summary>
    /// ��ע�ֽ�ʱ��λ��(��ע����������ʱ��)
    /// </summary>
     unsigned char DividingTime;
    /// <summary>
    /// ǰ�߶���ʼ���Ӧ��֡����
    /// </summary>
     int FLineSFrameIndex;
    /// <summary>
    /// ǰ�߶ν������Ӧ��֡����
    /// </summary>
     int FLineEFrameIndex;
    /// <summary>
    /// ǰ�߶���ʼ���Ӧ֡�ĵ�����
    /// </summary>
     int FLineSPointIndex;
    /// <summary>
    /// ǰ�߶ν������Ӧ֡�ĵ�����
    /// </summary>
     int FLileEPointIndex;
    /// <summary>
    /// ǰ�߶ε�������Ϣ
    /// </summary>
     int FLineRemark;
    /// <summary>
    /// ���߶���ʼ���Ӧ��֡����
    /// </summary>
     int RLineSFrameIndex;
    /// <summary>
    /// ���߶ν������Ӧ��֡����
    /// </summary>
     int RLineEFrameIndex;
    /// <summary>
    /// ���߶���ʼ���Ӧ֡�ĵ�����
    /// </summary>
     int RLineSPointIndex;
    /// <summary>
    /// ���߶ν������Ӧ֡�ĵ�����
    /// </summary>
     int RLileEPointIndex;
    /// <summary>
    /// ���߶ε�������Ϣ
    /// </summary>
     int RLineRemark;
};


/// <summary>
/// �ļ�β��
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
 /// �״�֡����
 /// </summary>
 struct FrameData
 {
     float* points;   //������x,y,zѭ��(xΪ���߷���Ϊ��ǰ����ֵ)
     int pointsLen;      //pointsָ�����鳤��
     float distance;  //��ǰ����(��λ:m)
     float circleX;   //���Բ������X(��λ:mm)
     float circleY;   //���Բ������Y(��λ:mm)
 };



/// <summary>
/// ��ͼ
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
/// ����ʾ�ؼ����
/// </summary>
/// <param name="hwd">�ؼ����</param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <returns></returns>
extern "C" _declspec(dllexport) void* _stdcall BindingHandle(HWND hwd, int width, int height);

/// <summary>
/// ��������
/// </summary>
/// <param name="frameDatas">֡����</param>
/// <param name="pointNum">֡����</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall EntryData(FrameData* frameDatas, int pointNum);
 
/// <summary>
/// ���ùܵ�����
/// </summary>
/// <param name="pipeDiameter">�ܵ�ֱ��</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall SetPipePara(int pipeDiameter);

/// <summary>
/// ���ñ�ע����
/// </summary>
/// <param name="drawMarks">��עָ��</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall SetMarkArray(DrawMarks drawMarks);

/// <summary>
/// ��ʾ/���ر�ע
/// </summary>
/// <param name="visible">true�ɼ�/false���ɼ�</param>
/// <returns></returns>
extern "C" _declspec(dllexport) int _stdcall SetMarksVisible(bool visible);



extern "C" _declspec(dllexport) void _stdcall SetCameraOrientation(CamOrientation t_camOrientation);