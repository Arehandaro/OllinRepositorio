#include <iostream>
#include <GLFW\glfw3.h>
#include "window.h"

using namespace std;


int main()
{
	
	using namespace ollin;
	using namespace graficas;

	Window window("Ollin", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	cout << "Vercion de OpenGL: ";
	cout << glGetString(GL_VERSION);


			while (!window.closed())
			{
				cout << window.getWidth() << ", " << window.getHeight() << endl;
				window.clear();
				glBegin(GL_QUADS);
				glVertex2f(-0.5f, -0.5f);
				glVertex2f(-0.5f,  0.5f);
				glVertex2f( 0.5f,  0.5f);
				glVertex2f( 0.5f, -0.5f);
				glEnd();
				window.update();
			}

	
	return 0;
}