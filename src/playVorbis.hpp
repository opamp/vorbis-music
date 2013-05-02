#ifndef PLAY_VORBIS_HPP
#define PLAY_VORBIS_HPP
#include<QObject>
#include<QString>

class playVorbis : public QObject{
    Q_OBJECT
public:
    playVorbis(const QString &);

    bool play();

private:
    QString filePath;
};
#endif
