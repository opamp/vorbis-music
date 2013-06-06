#ifndef PLAY_VORBIS_HPP
#define PLAY_VORBIS_HPP
#include<QObject>
#include<QString>
#include<QBuffer>
#include<QByteArray>
#include<QAudioBuffer>
#include<QAudioFormat>
#include<QIODevice>
#include<QAudioOutput>

#define PCMOUT_SIZE 4096

/*This headers must be included*/
#include<vorbis/vorbisfile.h>

class playVorbis : public QObject{
    Q_OBJECT
public:
    playVorbis(const QString &);

    bool decode();
    bool play();

private slots:
    void finishedPlaying(QAudio::State);

private:
    QString filePath;
    QByteArray bArray;
    QBuffer* b;
    QAudioFormat af;
    QAudioOutput *out;
};
#endif
