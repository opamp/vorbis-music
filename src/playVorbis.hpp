#ifndef PLAY_VORBIS_HPP
#define PLAY_VORBIS_HPP
#include<QObject>
#include<QString>
#include<QByteArray>

#define PCMOUT_SIZE 4096

/*This headers must be included*/
#include<vorbis/vorbisfile.h>

class playVorbis : public QObject{
    Q_OBJECT
public:
    playVorbis(const QString &);

    bool play();

private:
    QString filePath;
    QByteArray bArray;
};
#endif
