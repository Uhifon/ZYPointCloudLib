#pragma once


#include "vtkSmartPointer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkCylinderSource.h"
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkBMPReader.h"
#include "vtkJPEGReader.h"
#include "vtkTexture.h"
#include "vtkLight.h"
#include "vtkCamera.h"
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkTubeFilter.h>
#include <vtkLineSource.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkConeSource.h>
#include <vtkCubeSource.h>
#include <vtkStructuredPointsReader.h>
#include <vtkSphereSource.h>
#include <vtkMarchingCubes.h>
#include <vtkXMLPolyDataReader.h>//加载模型数据
#include <vtkTextureMapToCylinder.h>//采用圆柱作为中介
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkImageData.h> 
#include <vtkImageViewer2.h>
#include <vtkTransformTextureCoords.h>
#include <vtkPoints.h>
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkPolyDataWriter.h>
#include <vtk3DSImporter.h>
#include <vtkStructuredPoints.h>
#include <vtkStructuredPointsReader.h>
#include <vtkVolumeTexture.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkImageShiftScale.h>
#include <vtkOpenGLGPUVolumeRayCastMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkTransform.h>

//解决no override found for ""
#include "vtkAutoInit.h"
#include <vtkImageResliceMapper.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);

 
vtkSmartPointer< vtkOrientationMarkerWidget> widget  ;
vtkSmartPointer<vtkRenderWindow> renderWindow;
vtkSmartPointer<vtkRenderer> renderer;
vtkSmartPointer<vtkActor> actor ;
int diameter = 600;



