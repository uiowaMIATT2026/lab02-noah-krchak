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