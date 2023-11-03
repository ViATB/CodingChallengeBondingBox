#include <iostream>
#include <opencv2/core.hpp>     // Basic OpenCV structures (cv::Mat, Scalar)

const char* XPATH = "my/path";

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Please add video blaaa";
        return 1;
    }

    cv::Mat frameReference;

    //pugi::xml_document oXMLDoc;
    //const auto oParseStatus = oXMLDoc.load_file(argv[1]);

    return 0;
}




/*

1. Read Video Stream
2. Object Erkennung
3. Bounding Box hinzufügen
4. Video in Datei schreiben

*/