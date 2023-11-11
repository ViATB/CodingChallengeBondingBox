#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/tracking.hpp>

class VideoHelper
{
	public:
		VideoHelper();
		VideoHelper(const std::string& filename);
		~VideoHelper();

		bool read(cv::Mat& frame);
		void write(const cv::Mat& frame, const std::string& keyWriter);

	private:
		cv::VideoCapture m_oCaptVideo;
		std::map<std::string, cv::VideoWriter> m_mapWriter;
};

