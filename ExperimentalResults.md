# Experimental Results

This algorithm outputs a difference image with the overlapping area between the moving image and fixed image
being a gray color. The circles in the input images are white and the background is black. If both the moving image 
circle and fixed image circle completely overlap the circle in the output image should appear grey. 
# Transformation
In the EngineeringDesignPrinciples document, it was stated that we would use affine transform to 
as the transform for the registration method. The main downside of the affine transform is it's ability
to non-uniformly scale (aka shear) the image (i.e. turning a square into a rhombus). This
cause the circle in the moving image we were trying to register to the fixed image to turn into an ellipse
which in turn made it impossible to achieve a good registration. After 200 iterations the registration
ended far off the mark with only the lowest learning rate able to overlap the moving image circle.

We solved this issue by identifying a transform that had the ability to scale but still kept "rigid" properties,
meaning that it scales the moving image uniformly, never causing the image to shear, thus the circle in
the moving image to always remain a circle even when resized.

This achieved better results with the moving image circle mostly overlapping the fixed image circle.

# Conclusions

Although I have run out of time to fully test all of the optimization parameters, I was able
to determine that Similarity2DTransform is better than affine transform in 2d for this particular problem.
I was only able to test a few learning rates and was only able to judge the registration visually via the 
the output difference image. If I did have more time, I would also quantitatively prove that my registration
method is the best method for this particular problem and would test more of the optimization parameters
to determine which of them have the biggest impact on the registration output.