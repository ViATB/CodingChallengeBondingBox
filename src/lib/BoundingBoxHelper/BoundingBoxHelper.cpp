#include "include/BoundingBoxHelper.h"

using namespace std;

BoundingBoxHelper::BoundingBoxHelper(cv::Mat& frame)
{
    m_oTracker = cv::TrackerKCF::create();
    m_oTrackingBox = cv::selectROI(frame, false);
    m_oTracker->init(frame, m_oTrackingBox);
}

cv::Mat BoundingBoxHelper::update(const cv::Mat& frame)
{
    cv::Mat result = frame.clone();
    if (! m_oTracker->update(result, m_oTrackingBox))
    {
        return result;
    }
    
    cv::rectangle(result, m_oTrackingBox, cv::Scalar(255, 0, 0), 2, 8, 0);

    return result;
}

const cv::Rect BoundingBoxHelper::getBox() {
    return m_oTrackingBox;
}