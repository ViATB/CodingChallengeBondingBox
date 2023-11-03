#include <iostream> // for standard I/O
#include <string>   // for strings
#include <opencv2/core.hpp>     // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>  // OpenCV window I/O

const char* XPATH = "my/path";

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Please add a video file path.";
        return -1;
    }

    const string sourceReference = argv[1];
    const string sourceCompareWith = argv[2];

    int frameNum = -1;          // Frame counter
    cv::VideoCapture captRefrnc(sourceReference);
    cv::VideoCapture captUndTst(sourceCompareWith);

    if (! captRefrnc.isOpened())
    {
        cout << "Could not open reference " << sourceReference << endl;
        return -1;
    }

    cv::Size refS = cv::Size(
        static_cast<int>(captRefrnc.get(cv::CAP_PROP_FRAME_WIDTH)),
        static_cast<int>(captRefrnc.get(cv::CAP_PROP_FRAME_HEIGHT))
    );
    cv::Size uTSi = cv::Size(
        static_cast<int>(captUndTst.get(cv::CAP_PROP_FRAME_WIDTH)),
        static_cast<int>(captUndTst.get(cv::CAP_PROP_FRAME_HEIGHT))
    );


    cout << "Reference frame resolution: Width=" << refS.width << "  Height=" << refS.height
        << " of nr#: " << captRefrnc.get(cv::CAP_PROP_FRAME_COUNT) << endl;

    return 0;
}




/*

1. Read Video Stream
2. Object Erkennung
3. Bounding Box hinzufügen
4. Video in Datei schreiben

*/