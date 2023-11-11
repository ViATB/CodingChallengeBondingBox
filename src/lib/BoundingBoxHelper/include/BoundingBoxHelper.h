#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/tracking.hpp>

class BoundingBoxHelper
{
	public:
		BoundingBoxHelper(cv::Mat& frame);
		cv::Mat update(const cv::Mat& frame);
		const cv::Rect getBox();

	private:
		cv::Rect m_oTrackingBox;
		cv::Ptr<cv::Tracker> m_oTracker;
};