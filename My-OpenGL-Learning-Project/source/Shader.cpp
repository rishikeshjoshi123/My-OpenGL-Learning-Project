#include"Shader.h"


unsigned int CreateShaderProgram(std::string VS, std::string FS)
{
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, VS);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, FS);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    int success;
    char InfoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, InfoLog);
        //(type == GL_VERTEX_SHADER) ? (std::cout << "VERTEX ") : (std::cout << "FRAGMENT ");
        std::cout << "Program Linking failed " << "\n";
        int i = 0;
        while (InfoLog[i] != '\0')
        {
            std::cout << InfoLog[i];
            ++i;
        }
        return 0;
    }
    return program;
}

unsigned int CompileShader(unsigned int type, std::string &source)
{
    unsigned int shader = glCreateShader(type);
    char* src = &source[0];
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    int success;
    char InfoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, InfoLog);
        (type == GL_VERTEX_SHADER) ? (std::cout << "VERTEX ") : (std::cout << "FRAGMENT ");
        std::cout << "Shader compilation failed " << "\n";
        int i = 0;
        while (InfoLog[i] != '\0')
        {
            std::cout << InfoLog[i];
            ++i;
        }
        return 0;
    }
    return shader;
}

Shaders GetShaders()
{
    std::string path = "Shader/Source.shader";

    enum shadertype
    {
        NONE = -1, Vertex = 0, Fragment = 1
    };
    int type = shadertype::NONE;

    std::ifstream IN(path);
    std::string line;
    std::stringstream ss[2];

    while (getline(IN, line))
    {
        if (line.find("#vertex shader") != std::string::npos)
            type = Vertex;
        else if (line.find("#fragment shader") != std::string::npos)
            type = Fragment;
        else ss[(unsigned int)type] << line<<'\n';
    }

    return { ss[0].str(),ss[1].str() };
}


void PressESCtoClose(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}