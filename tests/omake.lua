project = Project()

flags = {"-Wall", "-Werror", "-Wextra"}

project:CreateBinary("test_mt19937"):AddDependencies(
    project:CreateDependency()
        :AddFlags(flags)
        :AddSourceFiles("test_mt19937.c")
        :AddStaticLibraries("..", "math_static"))

project:CreateBinary("test_perf"):AddDependencies(
    project:CreateDependency()
        :AddFlags(flags)
        :AddSourceFiles("test_perf.c")
        :AddStaticLibraries("..", "math_static"))

return project
