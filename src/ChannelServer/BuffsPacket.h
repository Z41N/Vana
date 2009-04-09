/*
Copyright (C) 2008-2009 Vana Development Team

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; version 2
of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#ifndef BUFFSPACK_H
#define BUFFSPACK_H

#include "Types.h"

class Player;
struct ActiveBuff;

namespace BuffsPacket {
	void useSkill(Player *player, int32_t skillid, int32_t time, ActiveBuff &pskill, ActiveMapBuff &mskill, int16_t addedinfo);
	void endSkill(Player *player, ActiveBuff &pskill);

	// Specific skills
	void usePirateBuff(Player *player, int32_t skillid, int32_t time, ActiveBuff &pskill, ActiveMapBuff &mskill);
	void useSpeedInfusion(Player *player, int32_t time, ActiveBuff &pskill, ActiveMapBuff &mskill, int16_t addedinfo);
	void useMount(Player *player, int32_t skillid, int32_t time, ActiveBuff &pskill, int16_t addedinfo, int32_t mountid);
};

#endif