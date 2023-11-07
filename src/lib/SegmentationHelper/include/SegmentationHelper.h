#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class SegmentationHelper
{
	public:
		SegmentationHelper();	
		
		void doWatershedAlgo(cv::Mat& frame);
		void doGrabCut(cv::Mat& frame, const cv::Rect& trackingBox);

	private:
		cv::Rect* m_oRect = nullptr;
};