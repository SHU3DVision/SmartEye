# Description

基于QT、PCL和Opencv与实验室EPC660相机建立tcp-socket通信操作软件，提供实时显示点云、保存16位深度图像等功能

# Environmet

Windows 10

VS2013

QT5.7.0 64bit

OenCV2.4.13

PCL1.8.0 64bit

# Compiling
## （仅测试windows）
* 复制opencv2.4.13环境文件到工程目录下，debug/release分别命名为：OpenCV2.4_Win64_Debug.props和OpenCV2.4_Win64_Release.props（更高版本应该也支持，但没有测试）

* 复制pcl1.8.0环境文件到工程目录下，debug/release分别命名为：PCL_1.8.0_x64_debug.props和PCL_1.8.0_x64_release.props（更高版本应该也支持，但没有测试）

* 用vs打开工程（我们使用VS 2013）

* 解决方案平台选择x64（未经win32平台测试）

* QT5->Qt Project Settings，设置Qt版本（仅测试了Qt 5.7.0）

* 编辑调试

# Contents

双击SmartEye.exe即可运行，界面如下：
![](https://github.com/dongmuliu/SmartEye/blob/master/SmartEye/Image/2.png) 

## 1.图片功能

### 1.1 显示伪彩色图像

当点击ShowColorImage按钮时，会弹出新的界面，可以显示全屏的伪彩色图像(自由调节大小)

### 1.2 显示图像深度

当鼠标点击320*240大小的伪彩色图像时，可以实时显示该点的坐标及深度值

### 1.3 保存深度图像

点击Save按钮，可以实时保存16bit的png图像(自由选择保存路径)，直到再次点击该按钮，保存结束

 ## 2.调整积分时间

 修改积分时间数值，回车，即可修改积分时间
 
 ## 3.点云显示
 
 ### 3.1 修改畸变系数及内参
 
  可以自由修畸变系数及内参
  
 ### 3.2 实时显示点云
 
   点击PointCloud Convert ，可以实时显示点云。再次点击，则关闭点云显示。
   
# Release版本：

 https://github.com/dongmuliu/SmartEye/releases
