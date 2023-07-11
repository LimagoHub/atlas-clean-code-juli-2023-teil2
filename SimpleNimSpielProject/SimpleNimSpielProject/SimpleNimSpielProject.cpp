// SimpleNimSpielProject.cpp: Definiert den Einstiegspunkt für die Anwendung.
//

#include "SimpleNimSpielProject.h"
#include "game/nimgame/nimgame_impl.h"
#include "client/game_client.h"
#include "game/nimgame/player/human_player.h"
#include "game/nimgame/player/computer_player.h"
#include "game/nimgame/player/oma_player.h"
#include "io/consolen_writer.h"
using namespace std;

int main()
{
    atlas::io::consolen_writer writer;
    atlas::game::human_player fritz{"Fritz"};
    atlas::game::computer_player hal{"HAL"};
    atlas::game::oma_player oma{"Tante Erna"};
	atlas::game::nimgame_impl game{writer};
    game.add_player(&fritz);
    game.add_player(&hal);
    game.add_player(&oma);
    atlas::client::game_client client{game};
    client.go();

	return 0;
}
