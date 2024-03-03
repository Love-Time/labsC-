# CMakeList.txt: проект CMake для FILES; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (FILES2 "FILES2.cpp" "FILES2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FILES2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
