#include "include/VideoHelper.h"

using namespace std;

VideoHelper::VideoHelper()
    : m_oCaptVideo(0)
{
	std::cout << "No video file path provided. Using default camera." << endl;
    setup();
}

VideoHelper::VideoHelper(const std::string& filename)
    : m_oCaptVideo(filename)
{
	// create video capturing object
    setup();
}

VideoHelper::~VideoHelper()
{
    // Release video capture and writer
    m_oWriterVideo.release();
    m_oCaptVideo.release();
}

void VideoHelper::setup()
{
    if (! m_oCaptVideo.isOpened())
    {
        cout << "Could neither open video file nor default camera." << endl;
        // error case!!
        return;
    }

    // Get video resolution
    int frameWidth = static_cast<int>(m_oCaptVideo.get(cv::CAP_PROP_FRAME_WIDTH));
    int frameHeigth = static_cast<int>(m_oCaptVideo.get(cv::CAP_PROP_FRAME_HEIGHT));
    int framerate = static_cast<int>(m_oCaptVideo.get(cv::CAP_PROP_FPS));

    cv::Size size = cv::Size(frameWidth, frameHeigth);

    // Create video writer object
    m_oWriterVideo = cv::VideoWriter("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), framerate, size);
}

bool VideoHelper::read(cv::Mat& frame)
{
    return m_oCaptVideo.read(frame);
}

void VideoHelper::write(cv::Mat& frame)
{
    // Write video frame to output
    m_oWriterVideo.write(frame);
}

