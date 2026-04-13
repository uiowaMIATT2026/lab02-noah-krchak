//
// Created by nkrchak on 4/13/26.
//



#include <itkEllipseSpatialObject.h>
#include <itkSpatialObjectToImageFilter.h>
#include "itkImage.h"
#include "itkImageFileWriter.h"

using PixelType = float;
const int numDim = 2;
using ImageType = itk::Image<PixelType, numDim>;
using EllipseType = itk::EllipseSpatialObject<numDim>;
using SpatialToImageFilterType = itk::SpatialObjectToImageFilter<EllipseType, ImageType>;
int main(int argc, char *argv[])
{
    SpatialToImageFilterType::Pointer spatialToImageFilter1 = SpatialToImageFilterType ::New();

    //Set spacing for spatialToImageFilter1
    ImageType::SpacingType img1Spacing;

    img1Spacing[0] = 1.0; // Spacing along x in mm
    img1Spacing[1] = 1.0; // Spacing along y in mm

    spatialToImageFilter1->SetSpacing(img1Spacing);

    //Set origin for spatialToImageFilter1
    const ImageType::PointType img1Origin{{0.0, 0.0}}; // x: 0.0 mm, y: 0.0 mm

    spatialToImageFilter1->SetOrigin(img1Origin);


    //Set direction for spatialToImageFilter2

    ImageType::DirectionType img1Direction;
    img1Direction.SetIdentity();

    spatialToImageFilter1->SetDirection(img1Direction);

    //Set largest region start location
    ImageType::IndexType img1Start;

    img1Start[0] = 0; // first index on x
    img1Start[1] = 0; // first index on y

    //Set largest region size (aka image size)

    ImageType::SizeType img1Size;

    img1Size[0] = 400; // size along x
    img1Size[1] = 400; // size along y



    spatialToImageFilter1->SetSize(img1Size);
    spatialToImageFilter1->SetIndex(img1Start);




    SpatialToImageFilterType ::Pointer spatialToImageFilter2 = SpatialToImageFilterType ::New();

    //Set spacing for spatialToImageFilter2
    ImageType::SpacingType img2Spacing;

    img2Spacing[0] = 1.0; // Spacing along x in mm
    img2Spacing[1] = 1.0; // Spacing along y in mm

    spatialToImageFilter2->SetSpacing(img1Spacing);

    //Set origin for spatialToImageFilter2
    const ImageType::PointType img2Origin{{0.0, 0.0}}; // x: 0.0 mm, y: 0.0 mm

    spatialToImageFilter2->SetOrigin(img2Origin);


    //Set direction for spatialToImageFilter2

    ImageType::DirectionType img2Direction;
    img2Direction.SetIdentity();

    spatialToImageFilter2->SetDirection(img2Direction);

    //Set largest region start location
    ImageType::IndexType img2Start;

    img2Start[0] = 0; // first index on x
    img2Start[1] = 0; // first index on y

    //Set largest region size (aka image size)

    ImageType::SizeType img2Size;

    img2Size[0] = 400; // Size along x
    img2Size[1] = 400; // Size along y

    //Create largest region for spatialToImageFilter2

    spatialToImageFilter2->SetSize(img2Size);
    spatialToImageFilter2->SetIndex(img2Start);



    //Create circle for spatialToImageFilter1
    EllipseType::Pointer ellipse1 = EllipseType::New();
    float radiusEllipseImg1 = 15.0; //Set circle radius to be 15.0 mm (diameter for spatialToImageFilter1 is 30.0)
    ImageType::PointType centerEllipseImg1{{50.0, 50.0}}; // Center of circle in image 1 is at 50.0 mm, 50.0 mm
    ellipse1->SetRadiusInObjectSpace(radiusEllipseImg1);
    ellipse1->SetCenterInObjectSpace(centerEllipseImg1);

    spatialToImageFilter1->SetInput(ellipse1);
    spatialToImageFilter1->SetInsideValue(1.0);
    spatialToImageFilter1->SetOutsideValue(0.0);

    spatialToImageFilter1->Update();

    ImageType::Pointer img1 = spatialToImageFilter1->GetOutput();

    //Create circle for spatialToImageFilter2
    EllipseType::Pointer ellipse2 = EllipseType::New();
    float radiusEllipseImg2 = 30.0; //Set circle radius to be 30.0 mm (diameter for img2.png is 60.0 mm)
    ImageType::PointType centerEllipseImg2{{200.0, 200.0}}; // Center of circle in image 2 is at 200.0 mm, 200.0 mm
    ellipse2->SetRadiusInObjectSpace(radiusEllipseImg2);
    ellipse2->SetCenterInObjectSpace(centerEllipseImg2);

    spatialToImageFilter2->SetInput(ellipse2);
    spatialToImageFilter2->SetInsideValue(1.0);
    spatialToImageFilter2->SetOutsideValue(0.0);

    spatialToImageFilter2->Update();

    ImageType::Pointer img2 = spatialToImageFilter1->GetOutput();




    return EXIT_SUCCESS;
}