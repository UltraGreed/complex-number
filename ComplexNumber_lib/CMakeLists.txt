project(ComplexNumber_lib)

set(SOURCE_FILES ComplexNumber.tpp)

add_library(ComplexNumber_lib STATIC ${SOURCE_FILES})

set_target_properties(
        ComplexNumber_lib
        PROPERTIES
        LINKER_LANGUAGE CXX
)
