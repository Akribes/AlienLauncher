/* Copyright 2020 Mart Koster
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ADDINSTANCEWINDOW_H
#define ADDINSTANCEWINDOW_H

#include <QComboBox>
#include <QLineEdit>
#include <QWidget>

namespace Ui {
	class AddInstanceWindow;
}

class AddInstanceWindow: public QWidget {
	Q_OBJECT

	public:
		explicit AddInstanceWindow(QWidget *parent = nullptr);
		~AddInstanceWindow();

	private slots:
		void on_typeComboBox_currentIndexChanged(int index = 0);

	private:
		Ui::AddInstanceWindow *ui;
		QLineEdit *urlLineEdit = nullptr;
		QComboBox *versionComboBox = nullptr;
};

#endif // ADDINSTANCEWINDOW_H
