#ifndef MainWindow_H
#define MainWindow_H

#include <QMainWindow>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
	Q_OBJECT

public:
	string RemovedData;
	vector<string> A;
	vector<string> B;
	vector<string> C;
	vector<pair<char, char>> Move;
	QPixmap pic;
	QPixmap pic1;
	QPixmap pic2;
	QPixmap pic3;
	int MoveNumber;
	int Clicked;
	void moveRock(char start, char end);
	void MoveSingleDisk(char start, char finish);
	void MoveTower(int n, char start, char finish, char temp);
	void UpdateGUI();
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:

	void on_pushButton_clicked();

	void on_action1_2_triggered();

	void on_action2_2_triggered();

	void on_action3_2_triggered();

	void on_action4_triggered();

private:
	Ui::MainWindow *ui;
};

#endif // MainWindow_H
