#include <iostream> // for standard I/O
#include <string>   // for strings
#include <opencv2/opencv.hpp>
//#include <opencv2/core.hpp>     // Basic OpenCV structures (cv::Mat, Scalar)
//#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>  // OpenCV window I/O
#include <opencv2/tracking.hpp>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Please add a video file path.";
        return -1;
    }

    const string source = argv[1];

    // create video capturing object
    //cv::VideoCapture captVideo(source);
    cv::VideoCapture captVideo(source);

    if (! captVideo.isOpened())
    {
        cout << "Could not open video file: " << source << endl;
        return -1;
    }

    // Get video resolution
    int frameWidth = static_cast<int>(captVideo.get(cv::CAP_PROP_FRAME_WIDTH));
    int frameHeigth = static_cast<int>(captVideo.get(cv::CAP_PROP_FRAME_HEIGHT));

    cv::Size size = cv::Size(frameWidth, frameHeigth);

    cout << "Reference frame resolution: Width=" << size.width << "  Height=" << size.height
        << " of nr#: " << captVideo.get(cv::CAP_PROP_FRAME_COUNT) << endl;


    // Create video writer object
    cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, size);

    cv::Mat frame;
    //cv::Ptr<cv::Tracker> tracker = cv::TrackerNano::create();
    cv::Ptr<cv::Tracker> tracker = cv::TrackerKCF::create();
    cv::Rect trackingBox = cv::selectROI(frame, false);
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
        if (cv::waitKey(25) >= 0) break;
    }
        
    // Release video capture and writer
    output.release();
    captVideo.release();

    // Destroy all windows
    cv::destroyAllWindows();

    return 0;
}




/*

1. Read Video Stream
2. Object Erkennung
3. Bounding Box hinzufügen
4. Video in Datei schreiben

*/