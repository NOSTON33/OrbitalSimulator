add_library(Integrator src/Integrator.cpp)

target_include_directories(Integrator
	PUBLIC 
		include 
)

target_link_libraries(Integrator
	PUBLIC
		Core
	PRIVATE
		Physics
)

target_compile_features(Integrator 
	PUBLIC 
		cxx_std_20
)