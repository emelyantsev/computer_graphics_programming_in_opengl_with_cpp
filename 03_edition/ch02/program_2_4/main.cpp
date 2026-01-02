#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>


#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];

std::string readFile(const char *filePath) {
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);
	std::string line = "";
	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();
	return content;
}

GLuint createShaderProgram() {
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint vfprogram = glCreateProgram();

	std::string vertShaderStr = readFile("vertShader_2_4.vert");
	std::string fragShaderStr = readFile("fragShader_2_4.frag");
	const char *vertShaderSrc = vertShaderStr.c_str();
	const char *fragShaderSrc = fragShaderStr.c_str();

	glShaderSource(vShader, 1, &vertShaderSrc, NULL);
	glShaderSource(fShader, 1, &fragShaderSrc, NULL);
	glCompileShader(vShader);
	glCompileShader(fShader);

	glAttachShader(vfprogram, vShader);
	glAttachShader(vfprogram, fShader);
	glLinkProgram(vfprogram);

	return vfprogram;
}

void init(GLFWwindow* window) {
	renderingProgram = createShaderProgram();
	glGenVertexArrays(numVAOs, vao);
	glBindVertexArray(vao[0]);
}

void display(GLFWwindow* window, double currentTime) {
	glUseProgram(renderingProgram);
	glPointSize(30.0f);
	glDrawArrays(GL_POINTS, 0, 1);
}

int main(void) {

	if (!glfwInit()) { exit(EXIT_FAILURE); }
	
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
    GLFWwindow* window = glfwCreateWindow(600, 600, "Chapter 2 - program 4", NULL, NULL);
	glfwMakeContextCurrent(window);
	
    if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
	glfwSwapInterval(1);

	init(window);

	while (!glfwWindowShouldClose(window)) {
		display(window, glfwGetTime());
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}