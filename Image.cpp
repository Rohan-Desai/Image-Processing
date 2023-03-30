// Project UID af1f95f547e44c8ea88730dfb185559d

#include <cassert>
#include "Image.h"

// REQUIRES: img points to an Image
//           0 < width && width <= MAX_MATRIX_WIDTH
//           0 < height && height <= MAX_MATRIX_HEIGHT
// MODIFIES: *img
// EFFECTS:  Initializes the Image with the given width and height.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, int width, int height) {
  img->width = width;
  img ->height = height;

  Matrix_init(&img->red_channel,width,height);
  Matrix_init(&img->green_channel,width,height);
  Matrix_init(&img->blue_channel,width,height);
}

// REQUIRES: img points to an Image
//           is contains an image in PPM format without comments
//           (any kind of whitespace is ok)
// MODIFIES: *img
// EFFECTS:  Initializes the Image by reading in an image in PPM format
//           from the given input stream.
// NOTE:     See the project spec for a discussion of PPM format.
// NOTE:     Do NOT use new or delete here.
void Image_init(Image* img, std::istream& is) {
  //initial charectorisitis
  char initial_chars[10];
  is >> initial_chars;
  is >> img->width;
  is >> img->height;
  is >> initial_chars;

  //intialize each channel Matrix
  Matrix_init(&img->red_channel, img->width, img->height);
  Matrix_init(&img->blue_channel, img->width, img->height);
  Matrix_init(&img->green_channel, img->width, img->height);

  //create pointers for each channel
  int* red_ptr = Matrix_at(&img->red_channel, 0, 0);
  int* blue_ptr = Matrix_at(&img->blue_channel, 0, 0);
  int* green_ptr = Matrix_at(&img->green_channel, 0, 0);

  //loop through file and fill matrixes
  while(!is.eof()){
    is >> *red_ptr;
    red_ptr++;
    is >> *green_ptr;
    green_ptr++;
    is >> *blue_ptr;
    blue_ptr++;
  }
  
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Writes the image to the given output stream in PPM format.
//           You must use the kind of whitespace specified here.
//           First, prints out the header for the image like this:
//             P3 [newline]
//             WIDTH [space] HEIGHT [newline]
//             255 [newline]
//           Next, prints out the rows of the image, each followed by a
//           newline. Each pixel in a row is printed as three ints
//           for its red, green, and blue components, in that order. Each
//           int is followed by a space. This means that there will be an
//           "extra" space at the end of each line. See the project spec
//           for an example.
void Image_print(const Image* img, std::ostream& os) {
  os << "P3" << "\n";
  os << img->width << " " << img->height << "\n";
  os << "255" << "\n";

  const int* red_ptr = Matrix_at(&img->red_channel, 0, 0);
  const int* green_ptr = Matrix_at(&img->green_channel, 0, 0);
  const int* blue_ptr = Matrix_at(&img->blue_channel, 0, 0);

  for(int i = 0; i < img->height; i++){
    for(int j = 0; j < img->width; j++){
      os << *red_ptr << " ";
      os << *green_ptr << " ";
      os << *blue_ptr << " ";
      red_ptr++;
      green_ptr++;
      blue_ptr++;
    }
    os << "\n";
  }
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the width of the Image.
int Image_width(const Image* img) {
  int width = img->width;
  return width;
}

// REQUIRES: img points to a valid Image
// EFFECTS:  Returns the height of the Image.
int Image_height(const Image* img) {
  int height = img->height;
  return height;
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// EFFECTS:  Returns the pixel in the Image at the given row and column.
Pixel Image_get_pixel(const Image* img, int row, int column) {
  int red_ptr = *Matrix_at(&img->red_channel, row, column);
  int green_ptr = *Matrix_at(&img->green_channel, row, column);
  int blue_ptr = *Matrix_at(&img->blue_channel, row, column);

  Pixel pix;
  pix.r = red_ptr;
  pix.g = green_ptr;
  pix.b = blue_ptr;

  return pix;
  
}

// REQUIRES: img points to a valid Image
//           0 <= row && row < Image_height(img)
//           0 <= column && column < Image_width(img)
// MODIFIES: *img
// EFFECTS:  Sets the pixel in the Image at the given row and column
//           to the given color.
void Image_set_pixel(Image* img, int row, int column, Pixel color) {
  int* red_ptr = Matrix_at(&img->red_channel, row, column);
  *red_ptr = color.r;
  int* green_ptr = Matrix_at(&img->green_channel, row, column); 
  *green_ptr = color.g;
  int* blue_ptr = Matrix_at(&img->blue_channel, row, column);
  *blue_ptr = color.b;

}

// REQUIRES: img points to a valid Image
// MODIFIES: *img
// EFFECTS:  Sets each pixel in the image to the given color.
void Image_fill(Image* img, Pixel color) {
  Matrix_fill(&img->red_channel, color.r);
  Matrix_fill(&img->green_channel, color.g);
  Matrix_fill(&img->blue_channel, color.b);
}
