# CMakeList.txt: CMake-Projekt für "SimpleNimSpielProject". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (SimpleNimSpielProject "SimpleNimSpielProject.cpp" "SimpleNimSpielProject.h"  "game/game.h" "client/game_client.h" game/nimgame/nimgame_impl.h)

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
