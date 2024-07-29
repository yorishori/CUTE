#include <iostream>
#include <vector>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;
void error_callback(int error, const char* description);
void close_window(GLFWwindow* window);


static unsigned int ComplileShader (unsigned int type, const string& source){
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(result == GL_FALSE){
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		
		char* msg = (char*) (alloca(length * sizeof(char)));
		glGetShaderInfoLog(id, length, &length, msg);
		
		cout << "Failed to complile " << (type==GL_VERTEX_SHADER?"vertex":"fragment") << " shader." << endl 
			<<"Error message: " << msg;
		
		glDeleteShader(id);
		return 0;
	}
	return id;
}

static unsigned int CreateShader(const string& vertexShader, const string& fragmentShader){
	unsigned int program = glCreateProgram();
	unsigned int vs = ComplileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = ComplileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main(int argc, char* argv[]){
	GLFWwindow* window;

	// Initialize library
	if(!glfwInit()){
		cout << "An error ocurred initializing GLFW";
		return 1;
	}

	// Set the error callback
	glfwSetErrorCallback(error_callback);

	// Create a window
	window = glfwCreateWindow(500, 500, "Test", NULL, NULL);
	if (!window){
		cout << "An error ocurred creating window" << endl;
		glfwTerminate();
		return -1;
	}

	// Set the context to the current window
	glfwMakeContextCurrent(window);

	// Start GLEW
	if(glewInit() != GLEW_OK){
		cout << "An error ocurred initializing GLFW" << endl;
	}

	const unsigned char* renderer = glGetString(GL_RENDERER);
	const unsigned char* version = glGetString(GL_VERSION);

	cout << "Renderer: " << renderer << endl;
	cout << "GL Version: " << version << endl;

	// Data buffer
	float tPoints[6] ={
		 0.0f,   0.5f,   
		 0.5f,  -0.5f, 
		-0.5f,  -0.5f
	};

	// Vertex buffer object
	unsigned int vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), tPoints, GL_STATIC_DRAW);


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE , 2*sizeof(float), 0);

	// Upload shaders
	string vertexShader = 
		"#version 330 core\n"
		"layout(location = 0) in vec4 position;\n"
		"void main(){\n"
		"	gl_Position = position;\n"
		"}\n";
	string fragmentShader = 
		"#version 330 core\n"
		"layout(location = 0) out vec4 color;\n"
		"void main(){\n"
		"	color = vec4(0.1, 0.5, 0.7, 0.8);\n"
		"}\n";
	
	cout << vertexShader << endl;
	cout << fragmentShader << endl;
	
	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);
	// Main loop
	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT);
		
		glDrawArrays(GL_TRIANGLES, 0, 3);


		
		// Poll for and process events
		glfwPollEvents();
		// Swap front and back buffers
		glfwSwapBuffers(window);
	}

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}

void error_callback(int error, const char* description){
	fprintf(stderr, "Error: %s\n", description);
}

void close_window(GLFWwindow* window){
	glfwDestroyWindow(window);
}
