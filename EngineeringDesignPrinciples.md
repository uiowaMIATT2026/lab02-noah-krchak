# Engineering Principles for Lab 02

# Directory Structure Design

- The algorithm should be housed in the src directory
- The algorithm should use Slicer Execution Model (SEM) to design the parameters needed for the algorithm
- CMake will be used to generate the build files for each system
- There will be a root CMakeLists.txt and a src CMakeLists.txt
- Directory structure is as follows
  - lab02-fullname
    - src
      - CMakeLists.txt
      - Algorithm c++
      - Algorithm 
      - MakeCircleImages.cpp
    - CMakeLists.txt
    - EngineeringDesignPrinciples.md
    - ExperimentalResults.md
    - README.md

# Assumptions on creating 2D images that have one circle in them
- Spacing is 1.0 mm x 1.0 mm
- Origin is 0.0 mm x 0.0 mm
- Images have exactly one circle in them
- The circle has these characteristics in img1.png
  - Center: 50 mm, 50 mm
  - Diameter: 30 mm
- The circle has these characteristics in img2.png
  - Center: 200 mm, 200 mm
  - Diameter: 60 mm
- Image files must be saved in png format, as to adhere to the requirements stated in the README, specifically the file extensions of img1 and img2 are both .png