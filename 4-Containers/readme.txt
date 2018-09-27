Recompiling the programs at first was not successfull.
At fist, I tried deleting the pre-existing executable before recompiling and
i was successfull

The fix is actually removing circularly linked header files
QList and QVector are already included in QTextStream

QSet is not included in QTextStream so the is no risk of circular linked headers
but i still got errors while recompiling. So i used the first fix
