#include "include/BoundingBoxHelper.h"

using namespace std;

BoundingBoxHelper::BoundingBoxHelper(cv::Mat frame)
{
    m_oTracker = cv::TrackerKCF::create();
    m_oTrackingBox = cv::selectROI(frame, false);
    m_oTracker->init(frame, m_oTrackingBox);
}

void BoundingBoxHelper::update(cv::Mat frame)
{
    if (! m_oTracker->update(frame, m_oTrackingBox))
    {
        return;
    }
    
    cv::rectangle(frame, m_oTrackingBox, cv::Scalar(255, 0, 0), 2, 8);
}

