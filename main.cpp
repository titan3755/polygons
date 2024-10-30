// Github Repo: https://github.com/titan3755/polygons
// Author: titan3755
// Source code of polygons -->

// necessary includes

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// constants

constexpr auto WIDTH = 1280;
constexpr auto HEIGHT = 720;
constexpr auto TITLE = "OGL First Program";
constexpr auto SHADER_FILE_DIRECTORY = "C:\\Users\\mahmu\\Desktop\\codez\\vs\\cpp\\opengl-polygons\\opengl-polygons\\src\\shaders\\";

// vertex and fragment shader source code

const char* vertexShaderSource;
const char* fragmentShaderSource;

// setup function return data struct

struct SetupDataOut {
	bool successStatus;
	GLFWwindow* window;
	unsigned int shaderProgram;
};

struct SetupDataIn {
	int glMinor;
	int glMajor;
	int WIDTH;
	int HEIGHT;
	const char* TITLE;
};

// function prototypes

SetupDataOut setupOpenGL(SetupDataIn sDt);
void printOpenGLVersionAndRenderer();
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void calculateFPS(GLFWwindow* window);
const char* readShaderFileGLSL(const char* shaderFile);


int main() {
	srand(time(0));
	// ---------------------------------------- start setup OpenGL ----------------------------------------
	SetupDataIn sDt = {
		3,
		3,
		WIDTH,
		HEIGHT,
		TITLE
	};
	SetupDataOut sDo = setupOpenGL(sDt);
	if (!sDo.successStatus) {
		std::cout << "Failed to setup OpenGL application!" << std::endl;
		return -1;
	}
	else {
		std::cout << "\nOpenGL application setup successfully!\n" << std::endl;
	}
	GLFWwindow* window = sDo.window;
	unsigned int shaderProgram = sDo.shaderProgram;
	// ---------------------------------------- end setup OpenGL ----------------------------------------
	// ---------------------------------------- start render initialization ----------------------------------------
	// to complete
	unsigned int polygonType = 5; // 0 for triangle, 1 for square, 2 for pentagon, 3 for hexagon, 4 for heptagon, 5 for octagon
	// to complete
	float vertices_triangle[]{
		// change here if polygon type changes ***
		// positions       // colors
		-0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
		0.5, -0.5, 0.0, 0.0, 1.0, 0.0,
		0.0, 0.5, 0.0, 0.0, 0.0, 1.0
	};
	unsigned int indices_triangle[]{
		// change here if polygon type changes ***
		0, 1, 2
	};
	float vertices_square[] = {
		// change here if polygon type changes ***
		// positions       // colors
		-0.5, -0.5, 0.0, 1.0, 0.0, 0.0,
		0.5, -0.5, 0.0, 0.0, 1.0, 0.0,
		0.5, 0.5, 0.0, 0.0, 0.0, 1.0,
		-0.5, 0.5, 0.0, 1.0, 0.0, 0.0
	};
	unsigned int indices_square[] = {
		// change here if polygon type changes ***
		0, 1, 2,
		0, 2, 3
	};
	float vertices_pentagon[] = {
		// change here if polygon type changes ***
		// positions       // colors
		-0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		-0.2, 0.5, 0.0, 0.0, 1.0, 0.0,
		0.2, 0.5, 0.0, 0.0, 0.0, 1.0,
		0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		0.0, -0.5, 0.0, 0.0, 1.0, 0.0
	};
	unsigned int indices_pentagon[] = {
		// change here if polygon type changes ***
		0, 1, 2, // first triangle
		0, 2, 3, // second triangle
		0, 3, 4  // third triangle
	};
	float vertices_hexagon[] = {
		// change here if polygon type changes ***
		// positions       // colors
		-0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		-0.2, 0.5, 0.0, 0.0, 1.0, 0.0,
		0.2, 0.5, 0.0, 0.0, 0.0, 1.0,
		0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		0.2, -0.5, 0.0, 0.0, 1.0, 0.0,
		-0.2, -0.5, 0.0, 0.0, 0.0, 1.0
	};
	unsigned int indices_hexagon[] = {
		// change here if polygon type changes ***
		0, 1, 2, // first triangle
		0, 2, 3, // second triangle
		0, 3, 4, // third triangle
		0, 4, 5  // fourth triangle
	};
	float vertices_heptagon[] = {
		// change here if polygon type changes ***
		// positions       // colors
		-0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		-0.3, 0.5, 0.0, 0.0, 1.0, 0.0,
		0.3, 0.5, 0.0, 0.0, 0.0, 1.0,
		0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		0.3, -0.5, 0.0, 0.0, 1.0, 0.0,
		-0.3, -0.5, 0.0, 0.0, 0.0, 1.0,
		-0.5, 0.0, 0.0, 1.0, 0.0, 0.0
	};
	unsigned int indices_heptagon[] = {
		// change here if polygon type changes ***
		0, 1, 2, // first triangle
		0, 2, 3, // second triangle
		0, 3, 4, // third triangle
		0, 4, 5, // fourth triangle
		0, 5, 6  // fifth triangle
	};
	float vertices_octagon[] = {
		// change here if polygon type changes ***
		// positions       // colors
		-0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		-0.3, 0.5, 0.0, 0.0, 1.0, 0.0,
		0.3, 0.5, 0.0, 0.0, 0.0, 1.0,
		0.5, 0.0, 0.0, 1.0, 0.0, 0.0,
		0.5, -0.5, 0.0, 0.0, 1.0, 0.0,
		0.3, -0.7, 0.0, 0.0, 0.0, 1.0,
		-0.3, -0.7, 0.0, 1.0, 0.0, 0.0,
		-0.5, -0.5, 0.0, 0.0, 1.0, 0.0
	};
	unsigned int indices_octagon[] = {
		// change here if polygon type changes ***
		0, 1, 2, // first triangle
		0, 2, 3, // second triangle
		0, 3, 4, // third triangle
		0, 4, 5, // fourth triangle
		0, 5, 6, // fifth triangle
		0, 6, 7  // sixth triangle
	};
	// vertex buffer object
	unsigned int VBO;
	unsigned int EBO;
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// binding the vertex array object
	glBindVertexArray(VAO);
	// copying our vertices array in a vertex buffer for OpenGL to use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	switch (polygonType) {
	case 0:
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_triangle), vertices_triangle, GL_STATIC_DRAW);
		break;
	case 1:
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_square), vertices_square, GL_STATIC_DRAW);
		break;
	case 2:
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_pentagon), vertices_pentagon, GL_STATIC_DRAW);
		break;
	case 3:
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_hexagon), vertices_hexagon, GL_STATIC_DRAW);
		break;
	case 4:
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_heptagon), vertices_heptagon, GL_STATIC_DRAW);
		break;
	case 5:
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_octagon), vertices_octagon, GL_STATIC_DRAW);
		break;
	default:
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_triangle), vertices_triangle, GL_STATIC_DRAW);
		break;
	}
	// element buffer object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	switch (polygonType) {
	case 0:
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_triangle), indices_triangle, GL_STATIC_DRAW);
		break;
	case 1:
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_square), indices_square, GL_STATIC_DRAW);
		break;
	case 2:
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_pentagon), indices_pentagon, GL_STATIC_DRAW);
		break;
	case 3:
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_hexagon), indices_hexagon, GL_STATIC_DRAW);
		break;
	case 4:
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_heptagon), indices_heptagon, GL_STATIC_DRAW);
		break;
	case 5:
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_octagon), indices_octagon, GL_STATIC_DRAW);
		break;
	default:
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_triangle), indices_triangle, GL_STATIC_DRAW);
		break;
	}
	// setting the vertex attributes pointers
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 *sizeof(float)));
	glEnableVertexAttribArray(1);
	// ---------------------------------------- end render initialization ----------------------------------------
	// ---------------------------------------- start render loop and print status logs ----------------------------------------
	// print OpenGL version and renderer
	printOpenGLVersionAndRenderer();
	// render loop
	while (!glfwWindowShouldClose(window)) {
		// calculate FPS
		calculateFPS(window);
		// inputs
		processInput(window);
		// rendering
		// make background color random
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		// render the triangle
		glBindVertexArray(VAO);
		// change here if polygon type changes ***
		switch (polygonType) {
		case 0:
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
			break;
		case 1:
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			break;
		case 2:
			glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
			break;
		case 3:
			glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
			break;
		case 4:
			glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, 0);
			break;
		case 5:
			glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
			break;
		default:
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
			break;
		}
		glBindVertexArray(0);
		// check and call events and swap the buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// clear all the resources and exit program
	glfwTerminate();
	return 0;
	// ---------------------------------------- terminate glfw and end program ----------------------------------------
}

// setup OpenGL function

SetupDataOut setupOpenGL(SetupDataIn sDt) {
	SetupDataOut result = {
		false,
		NULL,
		0
	};
	// ---------------------------------------- start window initialization ----------------------------------------
	std::cout << "Initializing OpenGL application ..." << std::endl;
	glfwInit();
	// set OpenGL version to 3.3 and window metadata
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, sDt.glMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, sDt.glMinor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(sDt.WIDTH, sDt.HEIGHT, sDt.TITLE, NULL, NULL);
	// check if window is created successfully
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		result.successStatus = false;
		result.shaderProgram = 0;
		result.window = NULL;
		return result;
	}
	// make the window's context current
	glfwMakeContextCurrent(window);
	//// disable window resize (disabled)
	//glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
	// load GLAD to manage function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		result.successStatus = false;
		result.shaderProgram = 0;
		result.window = NULL;
		return result;
	}
	// set the viewport size
	glViewport(0, 0, sDt.WIDTH, sDt.HEIGHT);
	// set the window resize callback functions
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	// ---------------------------------------- end window initialization ----------------------------------------
	// ---------------------------------------- start vertex shader initialization ----------------------------------------
	vertexShaderSource = readShaderFileGLSL((SHADER_FILE_DIRECTORY + std::string("vrtxone.vert")).c_str());
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		glfwTerminate();
		result.successStatus = false;
		result.shaderProgram = 0;
		result.window = NULL;
		return result;
	}
	else {
		std::cout << "Vertex shader compiled successfully!" << std::endl;
	}
	// ---------------------------------------- end vertex shader initialization ----------------------------------------
	// ---------------------------------------- start fragment shader initialization ----------------------------------------
	fragmentShaderSource = readShaderFileGLSL((SHADER_FILE_DIRECTORY + std::string("frgone.frag")).c_str());
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		result.successStatus = false;
		result.shaderProgram = 0;
		result.window = NULL;
		return result;
	}
	else {
		std::cout << "Fragment shader compiled successfully!" << std::endl;
	}
	// ---------------------------------------- end fragment shader initialization ----------------------------------------
	// ---------------------------------------- start shader program initialization ----------------------------------------
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		glfwTerminate();
		result.successStatus = false;
		result.shaderProgram = 0;
		result.window = NULL;
		return result;
	}
	else {
		std::cout << "Shader program linked successfully!" << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// ---------------------------------------- end shader program initialization ----------------------------------------
	// ---------------------------------------- SETUP END ----------------------------------------
	result.successStatus = true;
	result.shaderProgram = shaderProgram;
	result.window = window;
	return result;
}

// print OpenGL version and renderer

void printOpenGLVersionAndRenderer() {
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "OpenGL renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "OpenGL vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "OpenGL shading language version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "\nOpenGL application initialized successfully!" << std::endl;
}

// callback function for window resize

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// process input function

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

// calculate FPS

void calculateFPS(GLFWwindow* window) {
	static double previousSeconds = glfwGetTime();
	static int frameCount;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime();
	elapsedSeconds = currentSeconds - previousSeconds;
	if (elapsedSeconds > 0.25) {
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerFrame = 1000.0 / fps;
		char title[256];
		sprintf_s(title, "Polygons (OPENGL_APPLICATION) [FPS: %.2f] [ms/frame: %.2f]", fps, msPerFrame);
		glfwSetWindowTitle(window, title);
		frameCount = 0;
	}
	frameCount++;
}

// read shader file

const char* readShaderFileGLSL(const char* shaderFile) {
    std::ifstream file(shaderFile);
    std::string shaderCode = "";
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            shaderCode += line + "\n";
        }
        file.close();
		std::cout << "Shader file read successfully!" << std::endl;
    } else {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ" << std::endl;
    }
    // Allocate memory for the shader code and copy the string content
    char* code = new char[shaderCode.size() + 1];
	code = (char*)shaderCode.c_str();
    return code;
}