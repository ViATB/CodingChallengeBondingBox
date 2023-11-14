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

    m_fileWriter = cv::FileStorage("output_tracking_box.yml", cv::FileStorage::WRITE);
}

BoundingBoxHelper::~BoundingBoxHelper() {

    m_fileWriter.release();
}

void BoundingBoxHelper::writeBoxToTextfile() {

    m_fileWriter << "box";
    m_fileWriter << "{";
    m_fileWriter << "top-left-corner" << m_oTrackingBox.tl();
    m_fileWriter << "size" << m_oTrackingBox.size();
    m_fileWriter << "}";
}


Mat BoundingBoxHelper::update(const Mat& frame) {

    Mat result = frame.clone();
    if (! m_oTracker->update(result, m_oTrackingBox)) {
        return result;
    }

    writeBoxToTextfile();

    rectangle(result, m_oTrackingBox, COLOR_BLUE, 2);

    return result;
}

Rect BoundingBoxHelper::getBox() {

    return m_oTrackingBox;
}

