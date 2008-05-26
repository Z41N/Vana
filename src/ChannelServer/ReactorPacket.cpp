/*
Copyright (C) 2008 Vana Development Team

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
#include "ReactorPacket.h"
#include "PacketCreator.h"
#include "Player.h"
#include "Reactors.h"
#include "SendHeader.h"

void ReactorPacket::showReactor(Player* player, Reactor *reactor) {
	Packet packet;
	packet.addHeader(SEND_SHOW_REACTOR);
	packet.addInt(reactor->getID());
	packet.addInt(reactor->getReactorID());
	packet.addByte(reactor->getState());
	packet.addShort(reactor->getPos().x);
	packet.addShort(reactor->getPos().y);
	packet.addByte(0);
	packet.send(player);
}

void ReactorPacket::triggerReactor(Player *player, vector <Player*> players, Reactor *reactor) {
	Packet packet = Packet();
	packet.addHeader(SEND_TRIGGER_REACTOR);
	packet.addInt(reactor->getID());
	packet.addByte(reactor->getState()); // State
	packet.addShort(reactor->getPos().x);
	packet.addShort(reactor->getPos().y);
	packet.addInt(player->getPlayerid());
	packet.sendTo(player, players, 1);
}

void ReactorPacket::destroyReactor(Player *player, vector <Player*> players, Reactor *reactor) {
	Packet packet = Packet();
	packet.addHeader(SEND_DESTROY_REACTOR);
	packet.addInt(reactor->getID());
	packet.addByte(reactor->getState());
	packet.addShort(reactor->getPos().x);
	packet.addShort(reactor->getPos().y);
	packet.sendTo(player, players, 1);
}
