# CMakeList.txt : CMake project for Level3Eda-HeartDiseaseDetection, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Level3Eda-HeartDiseaseDetection "main.cpp" "level3.h" "subset.cpp" "subset.h" "entropy.h" "entropy.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Level3Eda-HeartDiseaseDetection PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
