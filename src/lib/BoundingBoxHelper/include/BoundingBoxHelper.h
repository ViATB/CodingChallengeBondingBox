#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/tracking.hpp>

class BoundingBoxHelper
{
	public:
		BoundingBoxHelper(const cv::Mat& frame);
		~BoundingBoxHelper();
		cv::Mat update(const cv::Mat& frame);
		cv::Rect getBox();

	private:
		cv::Rect m_oTrackingBox;
		cv::Ptr<cv::Tracker> m_oTracker;
		cv::FileStorage m_fileWriter;
		void writeBoxToTextfile();
};