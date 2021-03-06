#include "window.h"
//#include <GL\gl.h>
//#include <GL\glew.h>

using namespace std;

namespace ollin
{
	namespace graficas
	{
		void windowResize(GLFWwindow *window, int width, int height);

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
				glfwTerminate();

		}

		Window::~Window()
		{
			glfwTerminate();
		}


		bool Window::init()
		{
			if (!glfwInit())
			{
				cout << "No inicio correctamente GLFW!" << endl;
				return false;
			}


			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{

				std::cout << "Fallo al crear ventana!" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowSizeCallback(m_Window, windowResize);

			std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;
			
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Fallo al crear GLEW" << std::endl;
				return false;
			}

			return true;
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);

		}


		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void windowResize(GLFWwindow *window, int width, int height)
		{
			glViewport(0, 0, width, height);

		}

	}
}

//