#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

bool shouldExit = false;
GLFWwindow* window = nullptr;
bool isFullSreen = false;
int xpos = 0;
int ypos = 0;


void init(GLFWwindow* window) {}


void display(GLFWwindow* window, double currentTime) {

	if ( static_cast<long long>(currentTime) % 2 < 1 ) {
		glClearColor(0.0, 1.0, 0.5, 1.0);
	}
	else {
		glClearColor(0.0, 0.5, 1.0, 1.0);
	}
	
	glClear(GL_COLOR_BUFFER_BIT);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		shouldExit = true;
	}
	else if (key == GLFW_KEY_F11 && action == GLFW_PRESS) {

		if (!isFullSreen) {

			const GLFWvidmode* mode = glfwGetVideoMode( glfwGetPrimaryMonitor() );
			glfwGetWindowPos(window, &xpos, &ypos);

			glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate ); 	
			isFullSreen = true;
		}
		else {

			const GLFWvidmode* mode = glfwGetVideoMode( glfwGetPrimaryMonitor() );
			glfwSetWindowMonitor(window, NULL, xpos, ypos, 800, 600, mode->refreshRate ); 
			isFullSreen = false;
		}
	}
        
}

int main(void) {
	
	if ( !glfwInit() ) { exit(EXIT_FAILURE); }
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	window = glfwCreateWindow( 800, 600, "Chapter 2 - program 1a", NULL, NULL );
	
	glfwMakeContextCurrent( window );
	
	if (glewInit() != GLEW_OK) { exit( EXIT_FAILURE ); }
	
	glfwSwapInterval(1);

	init( window );

	glfwSetKeyCallback( window, key_callback );

	while ( !glfwWindowShouldClose( window ) && !shouldExit ) {
	
		display( window, glfwGetTime() );
		glfwSwapBuffers( window );
		glfwPollEvents();
	}

	glfwDestroyWindow( window );
	glfwTerminate();
	exit( EXIT_SUCCESS );
}