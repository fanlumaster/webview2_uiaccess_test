# Win32 Webview2 uiaccess topmost test

When we want to make webview2 window tompost while we set uiaccess to true, we need to set the window style to TOP_MOST after webview2 is created.

Also, when we set the window style to TOP_MOST, right context memu window will be hidden although we still could click it by mouse. So I disable right context menu manually in this code base.

![](https://i.postimg.cc/C158gdPJ/image.png)
