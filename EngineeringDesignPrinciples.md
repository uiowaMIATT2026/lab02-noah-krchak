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
    - CMakeLists.txt
    - EngineeringDesignPrinciples.md
    - ExperimentalResults.md
    - README.md

# Assumptions on creating 2D images that have one circle in them
- Spacing is 1.0 mm x 1.0 mm
- Origin is 0.0 mm x 0.0 mm
- Image files are in DICOM format
  - Dicom format saves origin, spacing, and direction cosine of the image