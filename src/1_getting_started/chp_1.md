* glGenObject()
glGenObject用于生成一个或者多个Opengl对象的名称。这些对象可以是缓冲区对象、纹理对象、帧缓存对象、
渲染缓冲对象等。在Opengl中，对象名称是一个无符号证书，它标识了一个对象。  
```cpp
// glGenObject函数签名 
void glGenObject(int n, unit* objects); // 类型签名代确认
```
其中，n表示要成成的对象数量，objects是一个指向无符号证书数组的指针，用于存储生成的对象的名称。

[参考连接](https://blog.csdn.net/qq_41449986/article/details/122705441)
