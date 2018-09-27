#include <QtGlobal>
class SoundEvent
{
  public:
    SoundEvent(qint64 timestamp = 0, int soundId = 0);
    ~SoundEvent();
    qint64 timestamp;
    int soundId;
};