#ifndef JPEG_HH
#define JPEG_HH

#include <string>

typedef struct _JFIFHeader
{
  unsigned char SOI[2];			/* 00h  Start of Image Marker		*/
  unsigned char APP0[2];		/* 02h  Application Use Marker		*/
  unsigned char Length[2];		/* 04h  Length of APP0 Field		*/
  unsigned char Identifier[5];	/* 06h  "JFIF" (zero terminated) Id String */
  unsigned char Version[2];		/* 07h  JFIF Format Revision		*/
  unsigned char Units;			/* 09h  Units used for Resolution	*/
  unsigned char Xdensity[2];	/* 0Ah  Horizontal Resolution		*/
  unsigned char Ydensity[2];	/* 0Ch  Vertical Resolution			*/
  unsigned char XThumbnail;		/* 0Eh  Horizontal Pixel Count		*/
  unsigned char YThumbnail;		/* 0Fh  Vertical Pixel Count		*/
} JFIFHEAD;

class Jpeg {
public:
  Jpeg() {}
  ~Jpeg() {}
  void readImage(const std::string& fileName);
private:
  JFIFHEAD header_;
};

#endif //JPEG_HH
