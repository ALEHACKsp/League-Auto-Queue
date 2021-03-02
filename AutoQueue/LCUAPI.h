#pragma once
#include "LeagueConnector.h"
#include <regex>

struct JSON_Object {
    JSON_Object(std::string pData = "") {
        Data = pData;
    }
    void Set(std::string pData) {
        this->Data = pData;
    }
    std::string Get() {
        return this->Data;
    }
private:
    std::string Data;
};

enum class GameState {
    None,
    Lobby,
    Matchmaking,
    ReadyCheck,
    ChampSelect,
    GameStart,
    FailedToLaunch,
    InProgress,
    Reconnect,
    WaitingForStats,
    EndOfGame,
    TerminatedInError
};

enum class GameMode {
    Draft_Pick = 400,           // 5v5 Draft Pick games
    Ranked_Solo = 420,          // 5v5 Ranked Solo games
    Blind_Pick = 430,           // 5v5 Blind Pick games
    Ranked_Flex = 440,          // 5v5 Ranked Flex games
    ARAM = 450,                 // 5v5 ARAM games
    Bot_Intro = 830,            // Co-op vs. AI Intro Bot games
    Bot_Beginner = 840,         // Co-op vs. AI Beginner Bot game
    Bot_Intermediate = 850     // Co-op vs. AI Intermediate Bot games
};

enum class GameRoles {
    Top,
    Mid,
    Bot,
    Support,
    Jungle,
    Fill,
    Unselected,
};

enum class Champions : int {
    None = -1,
    Shaco = 35,
    DrMundo = 36,
    Rammus = 33,
    Anivia = 34,
    Irelia = 39,
    Yasuo = 157,
    Sona = 37,
    Kassadin = 38,
    Zac = 154,
    Gnar = 150,
    Karma = 43,
    Corki = 42,
    Gangplank = 41,
    Janna = 40,
    Braum = 201,
    Ashe = 22,
    Tryndamere = 23,
    Jax = 24,
    Morgana = 25,
    Zilean = 26,
    Singed = 27,
    Evelynn = 28,
    Twitch = 29,
    Galio = 3,
    Velkoz = 161,
    Olaf = 2,
    Annie = 1,
    Leblanc = 7,
    Karthus = 30,
    Urgot = 6,
    XinZhao = 5,
    Amumu = 32,
    TwistedFate = 4,
    Chogath = 31,
    FiddleSticks = 9,
    Vladimir = 8,
    Warwick = 19,
    Teemo = 17,
    Tristana = 18,
    Sivir = 15,
    Soraka = 16,
    Ryze = 13,
    Sion = 14,
    MasterYi = 11,
    Alistar = 12,
    MissFortune = 21,
    Nunu = 20,
    Rengar = 107,
    Volibear = 106,
    Fizz = 105,
    Graves = 104,
    Ahri = 103,
    Shyvana = 102,
    Lux = 99,
    Xerath = 101,
    Thresh = 412,
    Shen = 98,
    Jinx = 222,
    KogMaw = 96,
    Riven = 92,
    Talon = 91,
    Malzahar = 90,
    Kayle = 10,
    Kalista = 429,
    Leona = 89,
    Gragas = 79,
    Lulu = 117,
    Poppy = 78,
    Fiora = 114,
    Udyr = 77,
    Ziggs = 115,
    Viktor = 112,
    Sejuani = 113,
    Varus = 110,
    Nautilus = 111,
    Draven = 119,
    Mordekaiser = 82,
    Yorick = 83,
    Pantheon = 80,
    Ezreal = 81,
    Garen = 86,
    Akali = 84,
    Kennen = 85,
    Vayne = 67,
    Jayce = 126,
    Cassiopeia = 69,
    Lissandra = 127,
    Rumble = 68,
    Khazix = 121,
    Darius = 122,
    Hecarim = 120,
    Skarner = 72,
    Lucian = 236,
    Heimerdinger = 74,
    Nasus = 75,
    Zed = 238,
    Nidalee = 76,
    Syndra = 134,
    Quinn = 133,
    JarvanIV = 59,
    Renekton = 58,
    Maokai = 57,
    Nocturne = 56,
    Katarina = 55,
    LeeSin = 64,
    MonkeyKing = 62,
    Brand = 63,
    Azir = 268,
    Elise = 60,
    Diana = 131,
    Nami = 267,
    Orianna = 61,
    Aatrox = 266,
    Zyra = 143,
    Trundle = 48,
    Veigar = 45,
    Taric = 44,
    Caitlyn = 51,
    Blitzcrank = 53,
    Malphite = 54,
    Vi = 254,
    Swain = 50,
    Sett = 875,
    Pyke = 555,
    Neeko = 518,
    Aphelios = 523,
    Sylas = 517,
    Ornn = 516,
    Xayah = 498,
    Rakan = 497,
    Bard = 432,
    Ivern = 427,
    Reksai = 421,
    Illaoi = 420,
    Yuumi = 350,
    Qiyana = 246,
    Ekko = 245,
    Kled = 240,
    Kindred = 203,
    Senna = 235,
};

class LCUAPI {
public:
    bool IsConnected();
    GameState GetGameState();
    JSON_Object CreatePracticeGame(unsigned short TeamSize = 1);
    JSON_Object CreateLobby(GameMode QueueID);
    JSON_Object JoinQueue();
    JSON_Object ReadyCheckAccept();
    JSON_Object ReadyCheckDecline();
    JSON_Object RolePicker(GameRoles Role1, GameRoles Role2 = GameRoles::Unselected);
    JSON_Object SelectChampion(int actid, Champions ChampionID);
    JSON_Object CompleteAction(int actid);
    JSON_Object Restart();
    JSON_Object GetChampSelectTimer();
    JSON_Object GetChampSelectInfo(); // this is to get the actid, we need to put that in later.

private:
    LeagueConnector conn{ L"" };
};