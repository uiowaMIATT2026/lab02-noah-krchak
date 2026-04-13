# Engineering Principles for Lab 02

# Directory Structure Design

- The algorithm should be housed in the src directory
- The algorithm should use Slicer Execution Model (SEM) to design the parameters needed for the algorithm
- CMake will be used to generate the build files for each system
- There will be a root CMakeLists.txt and a src CMakeLists.txt
- Directory structure is as follows
  - lab02-fullname
    - src
      - lab-02
        - CMakeLists.txt
        - Algorithm c++
        - Algorithm 
      - MakeCircleImages
        - CMakeLists.txt
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

# Register Circles Algorithm Assumptions
- Since we are creating the images with a circle as stated above, we can safely assume that the spacing and origin matches the assumptions made in creating the 2d images
- As stated above the algorithm will use the SEM to design the parameters needed
- The pixel type of the both input images will be float to preserve pixel intensity and not corrupt the image
- For registration we need the following functions: Transform, Optimizer, Metric and Registration
- Assumptions on the registration algorithm are stated below
  - Using affine transform: For the transform since the images are of the same "shape" but could be a different size, we need to use an Affine transformation to ensure we can rotate, translate and scale the image to register it
  - Using Regular Step Gradient Descent optimizer: For simplicity. It was used in Hello World registration in ITK Book 2
  - Using Mean squares image to image metric: Again for simplicity and for its use in ITK book 2. It provides the mean squared error on a pixel-level based on intensity
    - Using linear interpolators for both fixed and moving images for the metric: Found in ITK book 2 in same section as the optimizer was. Used for simplicity
  - Using ImageRegistrationV4 for registration: Used in ITK book 2. Most likely the best place to start for the registration method
- Optimizer Scale assumptions
  - For translation, start with the assumption that translation is equivalent to 1/1000 of 1 radian in rotation or scaling
  - Keep all other scales at 1.0
- Output
  - The algorithm will output:
    - An image containing the difference image between the fixed and moving images after registration has been completed
    - This image will be in PNG format using unsigned char
    - Default pixel value will be 100 so it is easily recognizable what pixels did match vs what didn't match
    - Image Size, Origin, spacing, and direction will match the fixed image