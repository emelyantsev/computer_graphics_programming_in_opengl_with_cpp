#include <string>

#include <tools.h>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	static int xpos = 0, ypos = 0, xsize = 800, ysize = 600;

    if (key == GLFW_KEY_F11 && action == GLFW_PRESS) {

        const bool isFullScreen = glfwGetWindowMonitor(window) != NULL;

		if (!isFullScreen) {

			const GLFWvidmode* mode = glfwGetVideoMode( glfwGetPrimaryMonitor() );
			glfwGetWindowPos(window, &xpos, &ypos);
            glfwGetWindowSize(window, &xsize, &ysize);

			glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate ); 	
		}
		else {

			const GLFWvidmode* mode = glfwGetVideoMode( glfwGetPrimaryMonitor() );
			glfwSetWindowMonitor(window, NULL, xpos, ypos, xsize, ysize, mode->refreshRate ); 
		}
	}

    else if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {

		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
        
}


void updateFPS(GLFWwindow* window) {

    static double previousTime = glfwGetTime();
    static int frameCount = 0;
    
	double currentTime = glfwGetTime();
    
	frameCount++;

    if ( currentTime - previousTime >= 1.0) {
        std::string title = "My Program | FPS: " + std::to_string(frameCount);
        glfwSetWindowTitle(window, title.c_str()); // Updates the bar at the top
        frameCount = 0;
        previousTime = currentTime;
    }
}