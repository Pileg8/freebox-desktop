#ifndef MAFREEBOX_H
#define MAFREEBOX_H

#include <QObject>
#include <QtNetwork>
class MaFreeBox : public QObject
{
    Q_OBJECT
public:
    explicit MaFreeBox(QObject *parent = 0);

    void setHostName(const QString& host) ;
    void setPort(int port) ;
    const QString& appToken() const;

    //request methods
public slots:
    void init();
    void authorize(const QString& appId, const QString& appName,
                   const QString& appVersion, const QString& deviceName);
    void authorizeProgress();

    void login(const QString& appId, const QString& appVersion, const QString& password);

signals:
    void ready();
    void authorizedReceived(const QString& appToken,int trackId);
    void authorizeProgressReceived(const QString& challenge, const QString& status);

protected slots:
    void initFinished();
    void authorizeFinished();
    void authorizeProgressFinished();

protected:
     QNetworkRequest createRequest(const QString& uri) const;
     QString hmacSha1(QByteArray key, QByteArray baseString);

private:
    QString mHost;
    int mPort;
    QString mBaseUrl;
    QString mApiVersion;
    QString mDeviceType;
    QString mDeviceName;

    QString mAppToken;
    double mTrackId;
    QString mChallenge;
    QString mAuthorizeStatus;
    QNetworkAccessManager * mNetManager;
    
};

#endif // MAFREEBOX_H
