#include "Jpeg.hh"
#include <fstream>
#include <stdexcept>
void
Jpeg::readImage(const std::string& fileName)
{
  std::ifstream ifp;
  JpegHeader header;
  ifp.open(fileName.c_str(), std::ifstream::in | std::ifstream::binary);
  if(!ifp) {
	throw std::runtime_error("Can't read image file.");
  }
  ifp.read((char*)&header,sizeof(JpegHeader));
  if(header.marker[0]!=0xFF || header.marker[1] != 0xD8) {
	throw std::runtime_error("File is not a JPEG file");
  }
}
