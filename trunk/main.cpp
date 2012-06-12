#include <QLocalSocket>
#include <QApplication>
#include <QSharedMemory>
#include <QLocalServer>
#include <QtGui>
#include "mainwindow.h"
#include "definitions.h"

class Application : public QApplication
{
	Q_OBJECT
public:
	Application(int &argc, char **argv, const QString uniqueKey);

	bool isRunning() { return _isRunning; }
	bool sendMessage(const QString &message);

public slots:
	void receiveMessage();

signals:
	void messageAvailable(QString message);

private:
	bool _isRunning;
	QString _uniqueKey;
	QSharedMemory sharedMemory;
	QLocalServer *localServer;

	static const int timeout = 1000;
};

Application::Application(int &argc, char **argv, const QString uniqueKey) : QApplication(argc, argv), _uniqueKey(uniqueKey)
{
	sharedMemory.setKey(_uniqueKey);
	if (sharedMemory.attach())
		_isRunning = true;
	else
	{
		_isRunning = false;
		// create shared memory.
		if (!sharedMemory.create(1))
		{
			qDebug("Unable to create single instance.");
			return;
		}
		// create local server and listen to incomming messages from other instances.
		localServer = new QLocalServer(this);
		connect(localServer, SIGNAL(newConnection()), this, SLOT(receiveMessage()));
		localServer->listen(_uniqueKey);
	}
}

void Application::receiveMessage()
{
	QLocalSocket *localSocket = localServer->nextPendingConnection();
	if (!localSocket->waitForReadyRead(timeout))
	{
		qDebug(localSocket->errorString().toLatin1());
		return;
	}
	QByteArray byteArray = localSocket->readAll();
	QString message = QString::fromUtf8(byteArray.constData());
	emit messageAvailable(message);
	localSocket->disconnectFromServer();
}

bool Application::sendMessage(const QString &message)
{
	if (!_isRunning)
		return false;
	QLocalSocket localSocket(this);
	localSocket.connectToServer(_uniqueKey, QIODevice::WriteOnly);
	if (!localSocket.waitForConnected(timeout))
	{
		qDebug(localSocket.errorString().toLatin1());
		return false;
	}
	localSocket.write(message.toUtf8());
	if (!localSocket.waitForBytesWritten(timeout))
	{
		qDebug(localSocket.errorString().toLatin1());
		return false;
	}
	localSocket.disconnectFromServer();
	return true;
}

int main(int argc, char *argv[])
{
    Application a(argc, argv, "uniqueqtluapad");
	QStringList arguments = a.arguments();
	arguments.removeFirst();
	if (a.isRunning())
	{
		QStringList::const_iterator end = arguments.end();
		for (QStringList::const_iterator it = arguments.begin();
			it != end; ++it) {
			QString arg = (*it);
			if (arg.isEmpty()) continue;

			a.sendMessage(arg);
		}
		return 0;
	}

    MainWindow w;
    QSettings settings(ORGNAME, APPNAME);
    settings.beginGroup("QtLuaPad");
    QString style = settings.value("style").toString().toLatin1();
    settings.endGroup();
    Application::setStyle(QStyleFactory::create(style));
    Application::setPalette(Application::style()->standardPalette());
    Application::setOrganizationDomain(ORGURL);
    Application::setOrganizationName(ORGNAME);
    Application::setApplicationName(APPNAME);
    Application::setApplicationVersion(APPVRSN);

	if (!arguments.isEmpty()) {
		QStringList::const_iterator end = arguments.end();
		for (QStringList::const_iterator it = arguments.begin();
			it != end; ++it) {
			QString arg = (*it);
			if (arg.isEmpty()) continue;

			w._openFile(arg);
		}
	}

	w.connect(&a, SIGNAL(messageAvailable(QString)), &w, SLOT(_openFile(QString)));
	w.show();
    return a.exec();
}
#include "main.moc"