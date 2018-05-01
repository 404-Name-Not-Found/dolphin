// Copyright 2018 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#include "DolphinQt2/Config/ProfileConfigWidget.h"

#include <QComboBox>
#include <QHBoxLayout>
#include <QPushButton>

#include "Common/CommonPaths.h"
#include "Common/FileUtil.h"
#include "Core/ConfigLoaders/GameConfigLoader.h"
#include "Core/ConfigManager.h"
#include "UICommon/GameFile.h"

ProfileConfigWidget::ProfileConfigWidget(/*const UICommon::GameFile& game*/)// : m_game(game)
{
//	m_game_id = m_game.GetGameID();
//	m_gameini_local_path =
			//QString::fromStdString(File::GetUserPath(D_GAMESETTINGS_IDX) + m_game_id + ".ini");
	//m_gameini_local = SConfig::LoadLocalGameIni(m_game_id, m_game.GetRevision());
	//m_gameini_default = SConfig::LoadDefaultGameIni(m_game_id, m_game.GetRevision());

	CreateWidgets();
  ConnectWidgets();
}

void ProfileConfigWidget::CreateWidgets()
{
	auto* profile_layout = new QHBoxLayout;
  m_controller_select_combo = new QComboBox;
  for ( const auto &item : {tr("GameCube"), tr("Wii")})
    m_controller_select_combo->addItem(item);
  m_controller_id_combo = new QComboBox;
  for ( const auto &item : {tr("1"), tr("2"), tr("3"), tr("4")})
    m_controller_id_combo->addItem(item);
  m_profile_combo = new QComboBox;
  m_profile_combo->addItem(tr(" "));
  m_remove_button = new QPushButton(tr("Remove"));

  profile_layout->addWidget(m_controller_select_combo);
  profile_layout->addWidget(m_controller_id_combo);
  profile_layout->addWidget(m_profile_combo);
  profile_layout->addWidget(m_remove_button);

  profile_layout->setContentsMargins(0, 0, 0, 0);
  setLayout(profile_layout);
}

void ProfileConfigWidget::ConnectWidgets()
{
  connect(m_remove_button, &QPushButton::pressed, this, &ProfileConfigWidget::OnProfileRemove);
}

void ProfileConfigWidget::LoadSettings()
{

}

void ProfileConfigWidget::SaveSettings()
{

}

void ProfileConfigWidget::OnProfileRemove()
{
  delete this;
}
