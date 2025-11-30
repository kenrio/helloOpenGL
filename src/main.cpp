#include <iostream>
#include <cmath>

#include "Shader.hpp"
#include "Texture.hpp"

// #include <glad/glad.h>
#include <GLFW/glfw3.h>


void	framebuffer_size_callback(GLFWwindow *window, int width, int height);
void	processInput(GLFWwindow *window);

int	main(void)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return (1);
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return (1);
	}

	int	width;
	int	height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	std::cout << "=== OpenGL Information ===" << std::endl;
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "=========================" << std::endl;

	// float	vertices[] =
	// {
	// 	// positions			// colors			// texture coords
	// 	 0.5f,	0.5f, 0.0f,		1.0f, 0.0f, 0.0f,	1.0f, 1.0f,		// top right
	// 	 0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,	1.0f, 0.0f,		// bottom right
	// 	-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f,	0.0f, 0.0f,		// bottom left
	// 	-0.5f,  0.5f, 0.0f,		1.0f, 1.0f, 0.0f,	0.0f, 1.0f,		// top left
	// };

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,	0.0f, 1.0f,
    };

	glm::vec3	cubePositions[] =
	{
		glm::vec3( 0.0f,  0.0f,  0.0f),
		glm::vec3( 2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3( 2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3( 1.3f, -2.0f, -2.5f),
		glm::vec3( 1.5f,  2.0f, -2.5f),
		glm::vec3( 1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f),
	};

	unsigned int	indices[] =
	{
		0, 1, 3,
		3, 1, 2,
	};

	Texture	texture1("texture/container.jpg", 1);
	Texture	texture2("texture/awesomeface.png", 1);

	unsigned int	VBO;
	glGenBuffers(1, &VBO);

	unsigned int	EBO;
	glGenBuffers(1, &EBO);

	unsigned int	VAO;
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);

	Shader	shader("shader/vertex.glsl", "shader/fragment.glsl");
	shader.use();
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// glm::mat4	model = glm::mat4(1.0f);
		// model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
		glm::mat4	view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		glm::mat4	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

		shader.use();
		// shader.setMat4("model", model);
		shader.setMat4("view", view);
		shader.setMat4("projection", projection);

		texture1.bind(0);
		texture2.bind(1);

		glBindVertexArray(VAO);
		for (unsigned int i = 0; i < 10; ++i)
		{
			glm::mat4	model = glm::mat4(1.0f);
			float		angle = 20.0f * i + (float)glfwGetTime() * 50.0f;

			model = glm::translate(model, cubePositions[i]);
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			shader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}
		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return (0);
}

void	framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);

	return ;
}

void	processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	return ;
}
