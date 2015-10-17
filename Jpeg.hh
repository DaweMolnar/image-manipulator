#ifndef JPEG_HH
#define JPEG_HH

#include <string>

class Jpeg {
public:
  Jpeg() {}
  ~Jpeg() {}
  void readImage(const std::string& fileName);
private:
  struct JpegHeader {
	unsigned char marker[2];
	unsigned char width[2];
	unsigned char height[2];
  };
};

#endif //JPEG_HH
