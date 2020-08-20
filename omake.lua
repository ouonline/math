project = CreateProject()

dep = project:CreateDependency()
    :AddSourceFiles("*.c")
    :AddFlags("-Wall", "-Werror", "-Wextra", "-fPIC")

project:CreateStaticLibrary("math_static"):AddDependencies(dep)
project:CreateSharedLibrary("math_shared"):AddDependencies(dep)

return project
