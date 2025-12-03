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

// ==========================================
// Minimal Inheritance for Assignment
// Base class: Fragment (generic language pair)
// Derived class: MemoryItem (adds "known" flag)
// ==========================================

class Fragment {
public:
    QString spanish;
    QString english;

    Fragment(const QString &es = "", const QString &en = "")
        : spanish(es), english(en) {}

    virtual QString info() const {
        return spanish + " = " + english;
    }

    virtual ~Fragment() {}
};


class MemoryItem : public Fragment {
public:
    bool known;

    MemoryItem(const QString &es = "", const QString &en = "", bool k = false)
        : Fragment(es, en), known(k) {}

    QString info() const override {
        return QString("MemoryItem: [%1] known=%2")
            .arg(Fragment::info())
            .arg(known ? "true" : "false");
    }
};


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
