#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
namespace ollin 

{

	namespace graficas
	{
		class Window
		{
		private://Atributos o caracteristicas
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;


		public://Metodos o acciones
			Window(const char *name, int width, int height);//(con el mismo nombre de la clase)METODO CONSTRUCTOR PARA INICIALIZAR LOS ATRIBUTOS
			~Window();
			void clear() const;
			void update(); //const;
			bool closed() const;

			inline int getWidth()const
			{
				return m_Width;
			}


			inline int getHeight()const
			{
				return m_Height;
			}

		private:
			bool init();


		};





	}


}
