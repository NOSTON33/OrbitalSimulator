add_library(Core INTERFACE)

target_include_directories(Core
	INTERFACE 
		include 
)

target_compile_features(Core
	INTERFACE 
		cxx_std_20
)
