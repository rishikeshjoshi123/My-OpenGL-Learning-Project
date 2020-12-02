#include"Shader.h"
std::unordered_map<std::string, int> dp;


Shader::Shader(const std::string& filepath)
	:m_filepath(filepath)
{
    std::cout << filepath << " : " << "string path cout in shader constructor \n";
    ShaderSource source = GetShaders(filepath);
    std::cout << source.vs << "\n\n" << source.fs << "\n";
    m_ID = CreateShaderProgram(source.vs, source.fs);
}

Shader::~Shader()
{
    glDeleteProgram(m_ID);
}

void Shader::Bind() const
{
    glUseProgram(m_ID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}
void Shader::SetUniform(std::string name, float v1, float v2, float v3, float v4) const
{
    //location can be -1 also if we declare a uniform and never use it..
    int location=-1;
    if (dp.find(name) == dp.end())
    {
        int location = glGetUniformLocation(m_ID, name.c_str());
        dp[name] = location;
    }
    else location = dp[name];

    glUniform4f(location, v1, v2, v3, v4);
}

ShaderSource GetShaders(std::string path)
{
    std::cout << path << " : " << "string path cout in GetShader function \n";

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
        std::cout << line << "\n";
        if (line.find("#vertex shader") != std::string::npos)
            type = Vertex;
        else if (line.find("#fragment shader") != std::string::npos)
            type = Fragment;
        else ss[(unsigned int)type] << line << '\n';
    }

    return { ss[0].str(),ss[1].str() };
}

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

unsigned int CompileShader(unsigned int type, std::string& source)
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