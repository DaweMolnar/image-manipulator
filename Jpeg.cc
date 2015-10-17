#include "Jpeg.hh"
#include <fstream>
#include <stdexcept>
void
Jpeg::readImage(const std::string& fileName)
{
  std::ifstream ifp;
  ifp.open(fileName.c_str(), std::ifstream::in | std::ifstream::binary);
  if(!ifp) {
	throw std::runtime_error("Can't read image file.");
  }
  ifp.read((char*)&header_,sizeof(JFIFHEAD));
  if(header_.SOI[0]!=0xFF || header_.SOI[1] != 0xD8) {
	throw std::runtime_error("File is not a JPEG file");
  }
}
