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
*
