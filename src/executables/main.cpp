#include <iostream>

const char *XPATH = "my/path"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Please add video"
        return 1;
    }

    pugi::xml_document oXMLDoc;

    const auto oParseStatus = oXMLDoc.load_file(argv[1]);

    return 0;
}




/*

1. Read Video Stream
2. Object Erkennung
3. Bounding Box hinzufügen
4. Video in Datei schreiben

*/