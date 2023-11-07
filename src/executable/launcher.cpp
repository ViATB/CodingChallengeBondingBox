#include <iostream> // for standard I/O
#include <string>   // for strings
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>  // OpenCV window I/O
#include <BoundingBoxHelper.h>
#include <SegmentationHelper.h>
#include <VideoHelper.h>

using namespace std;

int main(int argc, char* argv[])
{
    SegmentationHelper oSegmentationHelper = SegmentationHelper();
    VideoHelper oVideoHelper = (argc == 2) ? VideoHelper(argv[1]) : VideoHelper();

    cv::Mat frame;
    oVideoHelper.read(frame);

    BoundingBoxHelper oBoundingBoxHelper(frame);

    while (oVideoHelper.read(frame))
    {
        oBoundingBoxHelper.update(frame);

        oSegmentationHelper.doGrabCut(frame, oBoundingBoxHelper.getBox());
        oSegmentationHelper.doWatershedAlgo(frame);

        cv::imshow("Video feed", frame);

        oVideoHelper.write(frame);

        if (cv::waitKey(25) >= 0)
        {
            break;
        }
    }

    // Destroy all windows
    cv::destroyAllWindows();

    return 0;
}

