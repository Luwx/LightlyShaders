 ![default](https://github.com/Luwx/LightlyShaders/blob/master/screenshot.png)
 This is a fork of [ShapeCorners](https://sourceforge.net/projects/shapecorners/) KWin effect that additionally implements an outline around the window.
 
 # warning
 - This effect may cause a heavy performance impact
 - This effect can be affected by this KWin bug: https://bugs.kde.org/show_bug.cgi?id=395725
 - Aurorae decoration themes are not compatible
 - The decoration border/shadow and the effect must have the same corner radius
 
 # Dependencies:
 
From: https://github.com/alex47/KDE-Rounded-Corners
 
Debian based (Ubuntu, Kubuntu, KDE Neon):
```
sudo apt install git cmake g++ gettext extra-cmake-modules qttools5-dev libqt5x11extras5-dev libkf5configwidgets-dev libkf5crash-dev libkf5globalaccel-dev libkf5kio-dev libkf5notifications-dev kinit-dev kwin-dev 
```
Fedora based
```
sudo dnf install git cmake gcc-c++ extra-cmake-modules qt5-qttools-devel qt5-qttools-static qt5-qtx11extras-devel kf5-kconfigwidgets-devel kf5-kcrash-devel kf5-kguiaddons-devel kf5-kglobalaccel-devel kf5-kio-devel kf5-ki18n-devel kf5-knotifications-devel kf5-kinit-devel kwin-devel qt5-qtbase-devel libepoxy-devel
```

# Manual instalation
```
git clone https://github.com/Luwx/LightlyShaders

cd LightlyShaders; mkdir qt5build; cd qt5build; cmake ../ -DCMAKE_INSTALL_PREFIX=/usr -DQT5BUILD=ON && make && sudo make install && (kwin_x11 --replace &)
```
 
 
 
