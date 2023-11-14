#include "include/SegmentationHelper.h"

using namespace std;
using namespace cv;

namespace {
    const Scalar COLOR_BLACK = Scalar(0, 0, 0);
    const Scalar COLOR_WHITE = Scalar(255, 255, 255);
}

SegmentationHelper::SegmentationHelper() {

}

void SegmentationHelper::getBinMask(const Mat& comMask, Mat& binMask) {

    if (comMask.empty() || comMask.type() != CV_8UC1) {
        CV_Error(Error::StsBadArg, "comMask is empty or has incorrect type.");
    }

    binMask.create(comMask.size(), CV_8UC1);
    binMask = comMask & 1;
}

Mat SegmentationHelper::doGrabCut(const Mat& frame, const Rect& trackingBox) {

    Mat mask, bg, fg;
    grabCut(frame, mask, trackingBox, bg, fg, 3, GC_INIT_WITH_RECT);

    Mat binMask;
    getBinMask(mask, binMask);

    Mat black(binMask.rows, binMask.cols, CV_8UC3, COLOR_BLACK);
    black.setTo(COLOR_WHITE, binMask);

    Mat result = frame.clone();
    addWeighted(black, 0.5, result, 0.5, 0.0, result);

    return result;
}

