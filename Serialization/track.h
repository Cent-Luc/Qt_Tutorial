#include <QObject>
#include <QVector>
#include <QElapsedTimer>
#include "SoundEvent.h"
class Track : public QObject
{
    Q_OBJECT
public:
    enum class State {
        STOPPED,
        PLAYING,
        RECORDING,
    };
    explicit Track(QObject *parent = 0);
    qint64 duration() const;
    State state() const;
    State previousState() const;
    quint64 elapsedTime() const;
    const std::vector<std::unique_ptr<SoundEvent>>& soundEvents() const;
    ~Track();

    signals:
    void stateChanged(State state);

    public slots:
    void play();
    void record();
    void stop();
    void addSoundEvent(int soundEventId);

private:
    qint64 mDuration;
    std::vector<std::unique_ptr<SoundEvent>> mSoundEvents;
    QElapsedTimer mTimer;
    State mState;
    State mPreviousState;
    void clear();
    void setState(State state);
};
