#include"playVorbis.hpp"

playVorbis::playVorbis(const QString& ovFilePath){
    this->filePath = ovFilePath;
}

bool playVorbis::play(){
    OggVorbis_File vf;/*http://xiph.org/vorbis/doc/vorbisfile/OggVorbis_File.html*/
    if(ov_fopen(this->filePath.toStdString().c_str(),&vf) != 0){ //0 indicates success.
        return false;//ERROR
    }



    ov_clear(&vf);
}
