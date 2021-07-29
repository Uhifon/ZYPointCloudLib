using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Sample
{
  
    public class PointCloudLib
    {
        /// <summary>
        /// 雷达帧数据
        /// </summary>
        public struct FrameData
        {
            public IntPtr points;     //点坐标x,y,z循环(x为行走方向，为当前距离值)
            public int pointsLen;      //points数组长度
            public float circleX;    //拟合圆心坐标X(单位:mm)
            public float circleY;    //拟合圆心坐标Y(单位:mm)
            public float radius;     //拟合圆半径(单位:mm)
        };

        /// <summary>
        /// 视图
        /// </summary>
        public enum CamOrientation
        {
            Front,
            Back,
            Left,
            Right,
            Up,
            Down,
            Axonometric
        };

        public const string dllPath = "ZYPointCloudLib.dll";

        [DllImport(dllPath, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr BindingHandle( IntPtr hwd, int width, int height);


        [DllImport(dllPath, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern int EntryData(FrameData[] frameDatas, int pointNum);

        [DllImport(dllPath, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern int SetPipePara(int pipeDiameter);

        [DllImport(dllPath, CharSet = CharSet.Auto, CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetCameraOrientation(CamOrientation  t_camOrientation);
        

    }
}
