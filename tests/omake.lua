project = CreateProject()

project:CreateBinary("test_mt19937"):AddDependencies(
    project:CreateDependency()
        :AddFlags("-Wall", "-Werror", "-Wextra")
        :AddSourceFiles("test_mt19937.c")
        :AddStaticLibrary("..", "math_static"))

return project
