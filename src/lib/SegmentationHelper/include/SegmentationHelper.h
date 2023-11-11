#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class SegmentationHelper
{
	public:
		SegmentationHelper();	
		cv::Mat doGrabCut(const cv::Mat& frame, const cv::Rect& trackingBox);

	private:
		void getBinMask(const cv::Mat& comMask, cv::Mat& binMask);
};

