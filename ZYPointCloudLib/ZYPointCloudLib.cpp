// ZYPointCloudLib.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "ZYPointCloudLib.h"
#include "vtk.h"


 
 
/// <summary>
/// 绑定控件
/// </summary>
/// <param name="hwd"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <returns></returns>
void* _stdcall BindingHandle(HWND hwd, int width, int height)
{
    if (renderWindow == NULL)
    {
        renderWindow = vtkSmartPointer<vtkRenderWindow> ::New();
        renderer = vtkSmartPointer<vtkRenderer> ::New();
        actor = vtkSmartPointer<vtkActor> ::New();
        renderWindow->SetParentId(hwd);
        renderWindow->SetSize(width, height);
       
        renderer->AddActor(actor);
        renderWindow->AddRenderer(renderer);

        //获取渲染窗口上发生的鼠标,键盘,事件事件
        vtkSmartPointer<vtkRenderWindowInteractor> iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
        iren->SetRenderWindow(renderWindow);
        
        //设置鼠标交互方式
        vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
        iren->SetInteractorStyle(style);
        iren->Initialize();

        //左下角坐标系
        vtkSmartPointer< vtkAxesActor> axes = vtkSmartPointer< vtkAxesActor>::New();
        //以Widget方式,在左下角的视口中显示坐标系，可进行鼠标交互
        if (widget == NULL)
            widget = vtkSmartPointer< vtkOrientationMarkerWidget>::New();
        widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
        widget->SetOrientationMarker(axes);
        widget->SetInteractor(iren);
        widget->SetViewport(0.0, 0.0, 0.2, 0.2);
        widget->SetEnabled(1);     //使可用（显示）
        widget->InteractiveOff();  //禁止拖动    
    }  
    else
    {
        renderWindow->SetParentId(hwd);
        renderWindow->SetSize(width, height);
  
    }
 
    renderWindow->Render();
    return renderWindow;
}

/// <summary>
/// 传入数据
/// </summary>
/// <param name="frameDatas"></param>
/// <param name="pointNum"></param>
/// <returns></returns>
int _stdcall EntryData(FrameData* frameDatas, int pointNum)
{
    vtkSmartPointer<vtkCellArray> cells = vtkSmartPointer<vtkCellArray>::New();
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    vtkIdType idtype;
    for (int i = 0; i < pointNum; i++)
    {
        for (int j = 0; j < frameDatas[i].pointsLen; j += 3)
        {
            float x = frameDatas[i].points[j];
            float y = frameDatas[i].points[j+1];
            float z = frameDatas[i].points[j + 2];
            idtype = points->InsertNextPoint(x, y,z);
            cells->InsertNextCell(1, &idtype);   //第一个参数值标是cell中点的个数，第二个参数指向那些点的坐标数据。
        }    
    }
   
    polyData->SetPoints(points);//SetPoints设置几何数据点的坐标；
    polyData->SetVerts(cells);  //SetVerts将vtkCellArray按照离散点拓扑结构处理；
    mapper->SetInputData(polyData);
   
    actor->SetMapper(mapper);
 
    
    renderer->ResetCamera();
    renderWindow->Render();
    return 1;
}

int _stdcall SetPipePara(int pipeDiameter)
{
    diameter = pipeDiameter;
    return 1;
}

int _stdcall SetMarkArray(DrawMarks drawMarks)
{
    return 0;
}


int _stdcall SetMarksVisible(bool visible)
{
    return 0;
}


/// <summary>
/// 设置视图方向
/// </summary>
/// <param name="t_camOrientation"></param>
void _stdcall SetCameraOrientation(CamOrientation t_camOrientation)
{
     vtkCamera* camera = renderer->GetActiveCamera();
     if (renderer->GetActiveCamera())
     {
         switch (t_camOrientation)
         {
             case  CamOrientation::Left:
             {
                 camera->SetPosition(1, 0, 0); //相机位置
                 break;
             }
             case  CamOrientation::Right:
             {
                 camera->SetPosition(-1, 0, 0);
                 break;
             }
             case  CamOrientation::Front:
             {
                 camera->SetPosition(0, -1, 0);
                 break;
             }
             case  CamOrientation::Back:
             {
                 camera->SetPosition(0, 1, 0);
                 break;
             }
             case  CamOrientation::Up:
             {
                 camera->SetPosition(0, 0, -1);
                 break;
             }
             case  CamOrientation::Down:
             {
                 camera->SetPosition(0, 0, 1);
                 break;
             }
         }
         camera->SetViewUp(0, 0, 1);    //设置相机朝上方向  
         camera->SetFocalPoint(0, 0, 0);//相机焦点：从相机看向的点
         renderer->SetActiveCamera(camera);
         renderer->ResetCamera();
         renderWindow->Render();
     }
}
 