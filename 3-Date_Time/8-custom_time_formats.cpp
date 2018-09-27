/*
h - the hour without a leading zero (0 to 23 or 1 to 12 if AM/PM display)
hh - the hour with a leading zero (00 to 23 or 01 to 12 if AM/PM display)
H - the hour without a leading zero (0 to 23, even with AM/PM display)
HH - the hour with a leading zero (00 to 23, even with AM/PM display)
m - the minute without a leading zero (0 to 59)
mm - the minute with a leading zero (00 to 59)
s - the second without a leading zero (0 to 59)
ss - the second with a leading zero (00 to 59)
z - the milliseconds without leading zeroes (0 to 999)
zzz - the milliseconds with leading zeroes (000 to 999)
AP or A - use AM/PM display. AP will be replaced by either "AM" or "PM".
ap or a - use am/pm display. ap will be replaced by either "am" or "pm".
t - the timezone (for example "CEST")
*/
#include <QTextStream>
#include <QTime>

int main()
{
    QTextStream out(stdout);

    QTime tm = QTime::currentTime();

    out << "The time is " << tm.toString("hh:mm:ss.zzz") << endl;
    out << "The time is " << tm.toString("h:m:s a") << endl;
    out << "The time is " << tm.toString("h:m:s A") << endl;
    out << "The time is " << tm.toString("h:m ap") << endl;

    return 0;
}
