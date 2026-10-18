add_executable(OrbitalSimulator main.cpp)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

target_link_libraries(OrbitalSimulator
	PUBLIC 
		Physics
		Integrator
	PRIVATE
		Qt::Widgets
)


target_compile_features(OrbitalSimulator
	PUBLIC cxx_std_20
)