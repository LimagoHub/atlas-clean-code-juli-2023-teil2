// SimpleNimSpielProject.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "SimpleNimSpielProject.h"
#include "game/nimgame/nimgame_impl.h"
#include "client/game_client.h"

using namespace std;

int main()
{
	atlas::game::nimgame_impl game;
    atlas::client::game_client client{game};
    client.go();

	return 0;
}
