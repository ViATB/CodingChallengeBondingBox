#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <BoundingBoxHelper.h>
#include <SegmentationHelper.h>
#include <VideoHelper.h>

using namespace std;

int main(int argc, char* argv[]) {

    SegmentationHelper oSegmentationHelper = SegmentationHelper();
    VideoHelper oVideoHelper = (argc == 2) ? VideoHelper(argv[1]) : VideoHelper();

    cv::Mat frame, frameOut;
    if (! oVideoHelper.read(frame)) {
        return -1;
    }

    BoundingBoxHelper oBoundingBoxHelper(frame);

    while (oVideoHelper.read(frame)) {

        frameOut = oBoundingBoxHelper.update(frame);
        cv::imshow("Bounding Box Video Output", frameOut);
        oVideoHelper.write(frameOut, "output_bounding_box");

        frameOut = oSegmentationHelper.doGrabCut(frame, oBoundingBoxHelper.getBox());
        cv::imshow("Grab Cut Video Output", frameOut);
        oVideoHelper.write(frameOut, "output_grab_cut");

        // break the loop
        if (cv::waitKey(25) >= 0) {
            break;
        }
    }

    // Destroy all windows
    cv::destroyAllWindows();

    return 0;
}

