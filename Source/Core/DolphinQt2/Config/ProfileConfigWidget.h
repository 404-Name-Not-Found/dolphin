// Copyright 2018 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <array>

#include <QWidget>

#include "Common/IniFile.h"

namespace UICommon
{
class GameFile;
}

class QComboBox;
class QHBoxLayout;
class QPushButton;
class QString;

class ProfileConfigWidget : public QWidget
{
	//Q_OBJECT
public:
  explicit ProfileConfigWidget(/*const UICommon::GameFile& game*/);

private:
	void CreateWidgets();
	void ConnectWidgets();
	void LoadSettings();
	void SaveSettings();
	//void Update();

	void OnProfileRemove();

	QComboBox* m_controller_select_combo;
	QComboBox* m_controller_id_combo;
	QComboBox* m_profile_combo;
	QPushButton* m_remove_button;

	QString m_gameini_local_path;

	//IniFile m_gameini_local;
	//IniFile m_gameini_default;

	//const UICommon::GameFile& m_game;
	//std::string m_game_id;
};
