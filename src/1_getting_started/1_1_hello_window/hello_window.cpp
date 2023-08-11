//
// Created by yeshooo on 2023/8/11.
// https://github.com/JoeyDeVries/LearnOpenGL/blob/master/src/1.getting_started/1.1.hello_window/hello_window.cpp
//
/*
 * 请确认是在包含GLFW的头文件之前包含了GLAD的头文件。
 * GLAD的头文件包含了正确的OpenGL头文件（例如GL/gl.h），所以需要在其它依赖于OpenGL的头文件之前包含GLAD。
 * */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
int main() {
    // GLFW
    // 初始化glfw窗口
    glfwInit();
    // glfwWindowHint函数来配置GLFW
    // 该函数的所有的选项以及对应的值
    // https://www.glfw.org/docs/latest/window.html#window_hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 无边框模式
    // https://learnopengl-cn.github.io/01%20Getting%20started/03%20Hello%20Window/ 地下的评论
    glfwWindowHint(GLFW_DECORATED, GL_FALSE);
    // 颜色缓冲带透明后，可以显示后面的内容
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GL_TRUE);
#ifdef __APPLE__
    // 具体的宏取决于编译器
    // https://stackoverflow.com/questions/6802903/c-ifdef-mac-os-x-question
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // 创建一个窗口对象，这个窗口对象存放了所有和窗口相关的数据，而且会被GLFW的其他函数频繁地用到
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // 通知GLFW将我们窗口的上下文设置为当前线程的主上下文
    glfwMakeContextCurrent(window);

    //

    // GLAD
    // GLAD是用来管理OpenGL的函数指针的，所以在调用任何OpenGL的函数之前我们需要初始化GLAD
    // 给GLAD传入了用来加载系统相关的OpenGL函数指针地址的函数。GLFW给我们的是glfwGetProcAddress，它根据我们编译的系统定义了正确的函数。
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "初始化GLAD失败" << std::endl;
        return -1;
    }

    // 注册窗口的回调函数，告诉GLFW每当窗口调整大小的时候调用这个函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Render Loop
    while (!glfwWindowShouldClose(window))
    {
        // 处理输入
        processInput(window);

        // 渲染指令
        // 把所有的渲染(Rendering)操作放到渲染循环中，让这些渲染指令在每次渲染循环迭代的时候都能被执行

        // 使用一个自定义的颜色清空屏幕。在每个新的渲染迭代开始的时候清屏，否则仍能看见上一次迭代的渲染结果
        // glClear函数它接受一个缓冲位(Buffer Bit)来指定要清空的缓冲，
        // 可能的缓冲位有GL_COLOR_BUFFER_BIT，GL_DEPTH_BUFFER_BIT和GL_STENCIL_BUFFER_BIT。
        // glClearColor函数是一个状态设置函数，而glClear函数则是一个状态使用的函数，它使用了当前的状态来获取应该清除为的颜色。
        glClearColor(0.2f, 0.3f, 0.3f, 0.3f); //设置清空屏幕所用的颜色
        glClear(GL_COLOR_BUFFER_BIT); //glClear函数，清除颜色缓冲之后，整个颜色缓冲都会被填充为glClearColor里所设置的颜色。




        // glfwSwapBuffers函数会交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色值的大缓冲），它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
        glfwSwapBuffers(window);
        // glfwPollEvents函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，并调用对应的回调函数（可以通过回调方法手动设置）。
        glfwPollEvents();

    }
    // 当渲染循环结束后我们需要正确释放/删除之前的分配的所有资源。
    glfwTerminate();
    return 0;








}

// 改变窗口的大小的时候，视口也应该被调整。对窗口注册一个回调函数，它会在每次窗口大小被调整的时候被调用
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Viewport
    // 告诉OpenGL渲染窗口的尺寸大小，这样OpenGL才只能知道怎样根据窗口大小显示数据和坐标。
    // glViewport函数前两个参数控制窗口左下角的位置。第三个和第四个参数控制渲染窗口的宽度和高度（像素）。
    glViewport(0, 200, width, height);
}

// 使用GLFW的几个输入函数实现一些输入控制
void processInput(GLFWwindow* window)
{
    //glfwGetKey函数，它需要一个窗口以及一个按键作为输入，返回这个按键是否正在被按下。
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
