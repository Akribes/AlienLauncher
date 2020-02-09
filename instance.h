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

#ifndef INSTANCE_H
#define INSTANCE_H

#include <QFile>
#include <QString>

class Instance {
	public:
		explicit Instance(QString name);
		virtual ~Instance() = 0;

		QFile getDirectory();
		virtual void launch() = 0;

	protected:
		QString name;
};

#endif // INSTANCE_H
