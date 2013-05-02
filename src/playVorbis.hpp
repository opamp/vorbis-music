#ifndef PLAY_VORBIS_HPP
#define PLAY_VORBIS_HPP
#include<QObject>
#include<QString>

/*This headers must be included*/
#include<vorbis/vorbisfile.h>

class playVorbis : public QObject{
    Q_OBJECT
public:
    playVorbis(const QString &);

    bool play();

private:
    QString filePath;
};
#endif
