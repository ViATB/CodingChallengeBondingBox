#include "include/VideoHelper.h"

using namespace std;

VideoHelper::VideoHelper()
    : m_oCaptVideo(0)
{
	std::cout << "No video file path provided. Using default camera." << endl;
}

VideoHelper::VideoHelper(const std::string& filename)
    : m_oCaptVideo(filename)
{
}
// Release video capture and writers
VideoHelper::~VideoHelper()
{

    m_oCaptVideo.release();

    for (auto& writer : m_mapWriter)
    {
        writer.second.release();
    }
}

bool VideoHelper::read(cv::Mat& frame)
{
    if (! m_oCaptVideo.isOpened())
    {
        cout << "Could not open video stream." << endl;
        return false;
    }

    return m_oCaptVideo.read(frame);
}

void VideoHelper::write(const cv::Mat& frame, const std::string& keyWriter)
{
    if (m_mapWriter.find(keyWriter) == m_mapWriter.end())
    {
        // Get video resolution
        int frameWidth = static_cast<int>(m_oCaptVideo.get(cv::CAP_PROP_FRAME_WIDTH));
        int frameHeigth = static_cast<int>(m_oCaptVideo.get(cv::CAP_PROP_FRAME_HEIGHT));
        int frameRate = static_cast<int>(m_oCaptVideo.get(cv::CAP_PROP_FPS));

        cv::Size size = cv::Size(frameWidth, frameHeigth);

        // Create new video writer object
        m_mapWriter[keyWriter] = cv::VideoWriter(keyWriter + ".avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), frameRate, size);
    }
        
    if (! m_mapWriter[keyWriter].isOpened())
    {
        cout << "Could not write video stream." << endl;
        return;
    }

    // Write video frame to output
    m_mapWriter[keyWriter].write(frame);
}

//void VideoHelper::write(const cv::Mat& frame, const std::string& keyWriter)