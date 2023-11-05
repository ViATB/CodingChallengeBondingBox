#include <iostream> // for standard I/O
#include <string>   // for strings
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>  // OpenCV window I/O
#include <opencv2/tracking.hpp>

using namespace std;

int main(int argc, char* argv[])
{
    cv::VideoCapture captVideo;
    if (argc != 2)
    {
        std::cout << "No video file path provided. Using default camera."  << endl;
        captVideo = cv::VideoCapture(0);
    } else {
        // create video capturing object
        captVideo = cv::VideoCapture(argv[1]);
    }

    if (! captVideo.isOpened())
    {
        cout << "Could neither open video file nor default camera." << endl;
        return -1;
    }

    // Get video resolution
    int frameWidth = static_cast<int>(captVideo.get(cv::CAP_PROP_FRAME_WIDTH));
    int frameHeigth = static_cast<int>(captVideo.get(cv::CAP_PROP_FRAME_HEIGHT));
    int framerate = static_cast<int>(captVideo.get(cv::CAP_PROP_FPS));

    cv::Size size = cv::Size(frameWidth, frameHeigth);

    // Create video writer object
    cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), framerate, size);

    cv::Mat frame;
    captVideo.read(frame);
    cv::Rect trackingBox = cv::selectROI(frame, false);
    
    cv::Ptr<cv::Tracker> tracker = cv::TrackerKCF::create();
    tracker->init(frame, trackingBox);

    while (captVideo.read(frame))
    {
        if (tracker->update(frame, trackingBox))
        {
            cv::rectangle(frame, trackingBox, cv::Scalar(255, 0, 0), 2, 8);
        }

        // Display the frame
        cv::imshow("Video feed", frame);

        // Write video frame to output
        output.write(frame);

        // For breaking the loop
        if (cv::waitKey(25) >= 0)
        {
            break;
        }
    }
        
    // Release video capture and writer
    output.release();
    captVideo.release();

    // Destroy all windows
    cv::destroyAllWindows();

    return 0;
}

