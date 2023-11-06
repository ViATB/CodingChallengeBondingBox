#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class SegmentationHelper
{
	public:
		SegmentationHelper();	
		
		void doSegementation(cv::Mat frame);
};