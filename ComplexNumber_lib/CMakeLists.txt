project(ComplexNumber_lib)

set(SOURCE_FILES ComplexNumber.cpp)

set(HEADER_FILES ComplexNumber.h)

add_library(ComplexNumber_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
