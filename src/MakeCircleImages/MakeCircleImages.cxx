//
// Created by nkrchak on 4/13/26.
//



#include <itkEllipseSpatialObject.h>
#include "itkImage.h"
#include "itkImageFileWriter.h"

using PixelType = float;
const int numDim = 2;
using ImageType = itk::Image<PixelType, numDim>;

int main(int argc, char *argv[])
{
    ImageType::Pointer img1 = ImageType::New();

    //Set spacing for img1
    ImageType::SpacingType img1Spacing;

    img1Spacing[0] = 1.0; // Spacing along x
    img1Spacing[1] = 1.0; // Spacing along y

    img1->SetSpacing(img1Spacing);

    //Set origin for img1
    const ImageType::PointType img1Origin{{0.0, 0.0}}; // x: 0.0 mm, y: 0.0 mm

    img1->SetOrigin(img1Origin);


    //Set largest region start location
    ImageType::IndexType img1Start;

    img1Start[0] = 0;
    img1Start[1] = 0;

    //Set largest region size (aka image size)

    ImageType::SizeType img1Size;

    img1Size[0] = 400;
    img1Size[1] = 400;

    //Create largest region for img1
    ImageType::RegionType img1Region;

    img1Region.SetSize(img1Size);
    img1Region.SetIndex(img1Start);

    //Set regions for img1 and allocate
    img1->SetRegions(img1Region);
    img1->Allocate();

    return EXIT_SUCCESS;
}