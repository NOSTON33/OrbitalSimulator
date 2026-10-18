add_library(Physics src/Physics.cpp)

target_include_directories(Physics
	PUBLIC 
		include
)

target_link_libraries(Physics
	PUBLIC
		Core
)

target_compile_features(Physics 
	PUBLIC cxx_std_20
)
