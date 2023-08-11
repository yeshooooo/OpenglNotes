//
// Created by yeshooo on 2023/8/12.
//
// glfw 需要一个opengl的实现，所以一定要先包含glad，当然也可以连接windows自带的opengl32.lib，这里不用自己带的
#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include <gl/GL.h>
//#pragma comment(lib,"C:\\'Program Files (x86)'\\Windows Kits\\10\\Lib\\10.0.20348.0\\um\\x64\\opengl32.lib")

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // 传统模式下的三角形绘制
//        glBegin(GL_TRIANGLES);
//        glVertex2f(-0.5f, -0.5f);
//        glVertex2f(0.0f, 0.5f);
//        glVertex2f(0.5f, -0.5f);
//        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}