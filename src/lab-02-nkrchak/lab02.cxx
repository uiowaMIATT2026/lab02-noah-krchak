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


int main( int argc, char *argv[] )
{
    PARSE_ARGS;
    return EXIT_SUCCESS;
}