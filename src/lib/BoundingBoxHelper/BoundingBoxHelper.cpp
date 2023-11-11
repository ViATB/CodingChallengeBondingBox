#include "include/BoundingBoxHelper.h"

using namespace std;
using namespace cv;

namespace {
    const Scalar COLOR_BLUE = Scalar(255, 0, 0);
}

BoundingBoxHelper::BoundingBoxHelper(const Mat& frame) {

    m_oTracker = TrackerKCF::create();
    m_oTrackingBox = selectROI(frame, false);
    m_oTracker->init(frame, m_oTrackingBox);
}

Mat BoundingBoxHelper::update(const Mat& frame) {

    Mat result = frame.clone();
    if (! m_oTracker->update(result, m_oTrackingBox)) {
        return result;
    }

    rectangle(result, m_oTrackingBox, COLOR_BLUE, 2);

    return result;
}

const Rect BoundingBoxHelper::getBox() {

    return m_oTrackingBox;
}

