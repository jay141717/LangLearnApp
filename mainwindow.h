#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QSet>
#include <QPair>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString createNewBook();

private slots:
    void onSubmitClicked();
    void restartCurrentBook();
    void deleteCurrentBook();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;

    QSet<QPair<QString, QString>> vocabPairs;

    void saveVocabFromTable();
    QString generateSentence(bool spanishMode);
    void setupMorphologyFields(int row, const QString& part);

    bool englishMode = false;

    void playSpanishAudio(const QString &text);
    QString booksDir;
    QString currentBook;

    void loadBooksList();
    void loadBookNextSentence();
};

#endif // MAINWINDOW_H
