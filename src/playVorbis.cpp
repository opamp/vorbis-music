#include"playVorbis.hpp"

playVorbis::playVorbis(const QString& ovFilePath){
    this->filePath = ovFilePath;
}

bool playVorbis::play(){
    FILE* f = fopen("test.pcm","wb"); //for test
    OggVorbis_File vf;/*http://xiph.org/vorbis/doc/vorbisfile/OggVorbis_File.html*/
    if(ov_fopen(this->filePath.toStdString().c_str(),&vf) != 0){ //0 indicates success.
        return false;//ERROR
    }

    char pcmout[PCMOUT_SIZE];//default is 4096
    int eof = 0;
    int currentSection;

    while(!eof){
        long ret = ov_read(&vf,pcmout,PCMOUT_SIZE,0,2,1,&currentSection);//http://xiph.org/vorbis/doc/vorbisfile/ov_read.html
        /*
          1st arg -> OggVorbis_FIle pointer
          2nd arg -> buffer(decodec date will be wrote it)
          3rd arg -> sizeof pcmout.typical value is 4096.
          4th arg -> 0 for litele endian,1 for big endian.
          5th arg -> word size. 1 for 8bit samples or 2 or 16bit samples. typical value is 2.
          6th arg -> sgned signed or unsigned data. 0 for unsigned, 1 for signed. typical value is 1.
          7th arg -> A pointer to the number of the current logical bitstream.*/
        if(ret == 0){
            //EOF
            eof = 1;
        }else if(ret < 0){
            //ERROR
            ov_clear(&vf);
            return false;
        }else{
            fwrite(pcmout,1,ret,f);
        }
    }

    fclose(f);
    ov_clear(&vf);
    return true;
}
