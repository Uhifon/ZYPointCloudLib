using FileManagerLib;
using FileManagerLib.Lidar;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sample
{
    public partial class Form1 : Form
    {
        IntPtr vtkPtr;
        public Form1()
        {
            InitializeComponent();
            cmbViewAngle.SelectedIndex = 0;
            vtkPtr = PointCloudLib.BindingHandle(pictureBox1.Handle, pictureBox1.Width, pictureBox1.Height);
        }


        /// <summary>
        /// 打开文件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
            int ret = -1; ;
            OpenFileDialog fileDia = new OpenFileDialog();
            fileDia.Filter = "*.lid|*.lid";
            if (fileDia.ShowDialog() == DialogResult.OK)
            {
                ILidarFile lidarFile =  FileManagerLib.Lidar.LidarFile.GetInstance(fileDia.FileName);
                LidData lidData = new LidData();
                bool result = lidarFile.ReadAllData(true, out lidData);
                if(result)
                {
                    PointCloudLib.FrameData[] frameDatas = new PointCloudLib.FrameData[lidData.frameDatas.Length];
                    for (int i = 0; i < lidData.frameDatas.Length; i++)
                    {
                        List<PointF> CoordinatePoints = DataProcess.DataProcessing(lidData.frameDatas[i].FrameData, 0, lidData.frameDatas[i].ValidDataCount, 0, 360, true);
                        float[] points = new float[CoordinatePoints.Count * 3];
                        frameDatas[i].pointsLen = CoordinatePoints.Count * 3;
                        int index = 0;
                        for (int j = 0; j < CoordinatePoints.Count; j++)
                        {
                            points[index] = lidData.frameDatas[i].Distance * 1000;
                            points[index + 1] = CoordinatePoints[j].X;
                            points[index + 2] = CoordinatePoints[j].Y;
                            index += 3;
                        }
                        frameDatas[i].points = Marshal.AllocHGlobal(CoordinatePoints.Count * 3* sizeof(float));
                        Marshal.Copy(points, 0, frameDatas[i].points, points.Length);
                        frameDatas[i].circleX = lidData.frameDatas[i].CircleX;
                        frameDatas[i].circleY = lidData.frameDatas[i].CircleY;
                        frameDatas[i].radius = lidData.frameDatas[i].FittingCircleDia / 2;
                    }
                    ret = PointCloudLib.SetPipePara(lidData.headInfo.PipeSize[0]);

                    ret = PointCloudLib.EntryData(frameDatas, frameDatas.Length);
                }
                else
                {
                    MessageBox.Show("打开文件失败！");

                }

               
                

            }
        }


        /// <summary>
        /// 窗体大小变化
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Form1_Resize(object sender, EventArgs e)
        {
            vtkPtr = PointCloudLib.BindingHandle(pictureBox1.Handle, pictureBox1.Width, pictureBox1.Height);



        }

        /// <summary>
        /// 选择视角
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void cmbViewAngle_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = this.cmbViewAngle.SelectedIndex;
            if(index>=0)
                PointCloudLib.SetCameraOrientation((PointCloudLib.CamOrientation)index);
        }
    }
}

 