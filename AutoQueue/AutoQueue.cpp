#include "LCUAPI.h"

LCUAPI LCU;

void AutoQueue() {
    auto GameState = LCU.GetGameState();
    switch (LCU.GetGameState()) {
    case GameState::None:
    {
        LCU.CreateLobby(GameMode::Ranked_Solo);
        break;
    }
    case GameState::Lobby:
    {
        LCU.RolePicker(GameRoles::Support, GameRoles::Mid);
        Sleep(200);
        LCU.JoinQueue();
        break;
    }
    case GameState::ReadyCheck:
    {
        LCU.ReadyCheckAccept();
        break;
    }
    case GameState::ChampSelect:
    {
        // Ban Select
        auto ChampSelectTimer = LCU.GetChampSelectTimer().Get();

        if (ChampSelectTimer.find("PLANNING") < 4000) {
            for (int actid = 0; actid < 10; actid++) {
                LCU.SelectChampion(actid, Champions::None);
            }
        }
        else if (ChampSelectTimer.find("BAN_PICK") < 4000) {
            Sleep(1000);
            for (int actid = 0; actid < 10; actid++) {
                LCU.SelectChampion(actid, Champions::None);
                Sleep(100);
                LCU.CompleteAction(actid);
            }
            Sleep(29000);
            do {
                for (int actid = 10; actid < 20; actid++) {
                    LCU.SelectChampion(actid, Champions::Yuumi);
                }
                Sleep(1000);

                if (LCU.GetGameState() != GameState::ChampSelect)
                    break;

            } while (true);
        }
        break;
    }
    case GameState::WaitingForStats:
    {
        LCU.Restart();
        Sleep(55000);
        break;
    }
    case GameState::EndOfGame:
    {
        Sleep(43000);
        LCU.CreateLobby(GameMode::Ranked_Solo);
        break;
    }
    }
    Sleep(1000);
}

int main() {
    SetConsoleTitleA("Dencelle's AutoQueue");
    while (true)
        AutoQueue();
}