//
// Created by nkrchak on 4/13/26.
//
#include "lab02CLP.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkImageRegistrationMethodv4.h"
#include "itkAffineTransform.h"
#include "itkMeanSquaresImageToImageMetricv4.h"
#include "itkRegularStepGradientDescentOptimizerv4.h"
#include "itkCompositeTransform.h"
#include "itkResampleImageFilter.h"

const int numDim = 2;
using InputPixelType = float;
using AffineTransformPixelType = double;
using OptimizerValueType = double;
using InterpolatorCoordinateValueType = double;
using OutputPixelType = unsigned char;

using FixedImageType = itk::Image<InputPixelType, numDim>;
using MovingImageType = itk::Image<InputPixelType, numDim>;

using OutputImageType = itk::Image<OutputPixelType, numDim>;

using FixedImageReaderType = itk::ImageFileReader<FixedImageType>;
using MovingImageReaderType = itk::ImageFileReader<MovingImageType>;
using ImageWriterType = itk::ImageFileWriter<OutputImageType>;

using AffineTransformType = itk::AffineTransform<AffineTransformPixelType, numDim>;
using OptimizerType = itk::RegularStepGradientDescentOptimizerv4<OptimizerValueType>;
using MetricType = itk::MeanSquaresImageToImageMetricv4<FixedImageType, MovingImageType>;
using RegistrationType = itk::ImageRegistrationMethodv4<FixedImageType, MovingImageType, AffineTransformType>;

using FixedInterpolatorType = itk::LinearInterpolateImageFunction<FixedImageType, InterpolatorCoordinateValueType>;
using MovingInterpolatorType = itk::LinearInterpolateImageFunction<MovingImageType, InterpolatorCoordinateValueType>;

using ResampleFilterType = itk::ResampleImageFilter<MovingImageType, FixedImageType>;
using CasterFilterType = itk::CastImageFilter<FixedImageType, OutputImageType>;
int main( int argc, char *argv[] )
{
    PARSE_ARGS;

    try{
        //Read in both the fixed image and the moving image
        typename FixedImageReaderType::Pointer fixedReader = FixedImageReaderType::New();
        typename MovingImageReaderType::Pointer movingReader = MovingImageReaderType::New();

        fixedReader->SetFileName(fixedImageFile);
        movingReader->SetFileName(movingImageFile);

        fixedReader->Update();
        movingReader->Update();

        FixedImageType::Pointer fixedImage = fixedReader->GetOutput();
        MovingImageType::Pointer movingImage = movingReader->GetOutput();


    }
    catch(itk::ExceptionObject &err)
    {
        std::cerr << "ExceptionObject caught !" << std::endl;
        std::cerr << err << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}