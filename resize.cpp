// Project UID af1f95f547e44c8ea88730dfb185559d
#include <iostream>
#include <fstream>
#include "Image.h"
#include "Matrix.h"
#include <cassert>
#include "processing.h"
#include <cstdlib>
#include <ostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
    ifstream in_file;
    ofstream out_file;
    string filename;
    int width;
    int height;
    filename = argv[1];
    in_file.open(filename.c_str());
    if (!in_file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return 1;
    }
    if (argc == 5 || argc == 4)
    {
        string filename = argv[1];
        string filenameOut = argv[2];
        Image *img = new Image;
        ofstream out_file(filenameOut.c_str());
        width = atoi(argv[3]);

        if (argc == 5)
        {
            height = atoi(argv[4]);
            Image_init(img, in_file);
            seam_carve(img, width, height);
        }
        if (argc == 4)
        {
            Image_init(img, in_file);
            seam_carve(img, width, Image_height(img));
        }
        Image_print(img, out_file);
        delete img;
    }
    else
    {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
             << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    return 0;
}