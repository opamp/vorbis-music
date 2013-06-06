#include"playVorbis.hpp"
#include<iostream>

playVorbis::playVorbis(const QString& ovFilePath){
    this->filePath = ovFilePath;
}

bool playVorbis::decode(){
    FILE* f = fopen("test.raw","wb"); //for test
    OggVorbis_File vf; /*http://xiph.org/vorbis/doc/vorbisfile/OggVorbis_File.html*/
    if(ov_fopen(this->filePath.toStdString().c_str(),&vf) != 0){ //0 indicates success.
        return false;//ERROR
    }

    char pcmout[PCMOUT_SIZE];//default is 4096
    int eof = 0;
    int currentSection;


    af.setChannelCount(2);
    af.setSampleRate(44100);
    af.setSampleSize(16);
    af.setCodec("audio/pcm");//http://www.iana.org/assignments/media-types/audio/
    af.setSampleType(QAudioFormat::SignedInt);
    af.setByteOrder(QAudioFormat::LittleEndian	);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if(!info.isFormatSupported(af)) {
        std::cout<<"ERROR"<<std::endl;
        return false;
    }

    out = new QAudioOutput(af,this);
    out->setVolume(0.5);

    while(!eof){
        long ret = ov_read(&vf,pcmout,PCMOUT_SIZE,0,2,1,&currentSection);//http://xiph.org/vorbis/doc/vorbisfile/ov_read.html
        /*
          1st arg -> OggVorbis_FIle pointer
          2nd arg -> buffer(decodec date will be wrote it)
          3rd arg -> sizeof pcmout.typical value is 4096.
          4th arg -> 0 for litele endian,1 for big endian.
          5th arg -> word size. 1 for 8bit samples or 2 for 16bit samples. typical value is 2.[16bitPCM]
          6th arg -> signed signed or unsigned data. 0 for unsigned, 1 for signed. typical value is 1.
          7th arg -> A pointer to the number of the current logical bitstream.*/
        if(ret == 0){
            //EOF
            eof = 1;
        }else if(ret < 0){
            //ERROR
            ov_clear(&vf);
            return false;
        }else{
            fwrite(pcmout,sizeof(char),ret,f);//PCM16bit LE signed data.
            this->bArray.append(pcmout,ret);
        }
    }

    connect(out,SIGNAL(stateChanged(QAudio::State)),SLOT(finishedPlaying(QAudio::State)));

    vorbis_info *vinfo = ov_info(&vf,-1);
    if(vinfo == NULL){//fail to get vorbis_info.
        return false;
    }

    fclose(f);
    ov_clear(&vf);

    return true;
}

bool playVorbis::play(){
    std::cout<<"SIZE = "<<(new QBuffer(&bArray))->size()<<std::endl;
    b = new QBuffer(&bArray);
    b->open(QIODevice::ReadOnly);
    out->start(b);
    return true;
}

 void playVorbis::finishedPlaying(QAudio::State state){
     std::cout<<"Changed state = "<<state<<std::endl;
     if (state == QAudio::IdleState) {
         out->stop();
         b->close();
         delete out;
      }
}
