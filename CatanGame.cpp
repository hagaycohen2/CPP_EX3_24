#include "CatanGame.hpp"

CatanGame::CatanGame() {
    players[0].setId(owner::YELLOW);
    players[1].setId(owner::BLUE);
    players[2].setId(owner::RED);
}

// TODO: cards initialization
void CatanGame::init() {
    for (int i = 0; i < 3; i++) {
        knightCount[i] = 0;
    }

    for (int i = 0; i < 11; i++) {
        paiment[i] = {};
    }

    settlements[0].load(0, owner::EMPTY, nullptr, &settlements[4], &settlements[3], nullptr, &roads[1], &roads[0],
                        {10, resource::STONE}, {0, resource::NONE}, {0, resource::NONE});
    settlements[1].load(1, owner::EMPTY, nullptr, &settlements[5], &settlements[4], nullptr, &roads[3], &roads[2],
                        {2, resource::SHEEP}, {0, resource::NONE}, {0, resource::NONE});
    settlements[2].load(2, owner::EMPTY, nullptr, &settlements[6], &settlements[5], nullptr, &roads[5], &roads[4],
                        {9, resource::WOOD}, {0, resource::NONE}, {0, resource::NONE});
    settlements[3].load(3, owner::EMPTY, &settlements[0], &settlements[7], nullptr, &roads[0], &roads[6], nullptr,
                        {10, resource::STONE}, {0, resource::NONE}, {0, resource::NONE});
    settlements[4].load(4, owner::EMPTY, &settlements[1], &settlements[8], &settlements[0], &roads[2], &roads[7], &roads[1],
                        {2, resource::SHEEP}, {10, resource::STONE}, {0, resource::NONE});
    settlements[5].load(5, owner::EMPTY, &settlements[2], &settlements[9], &settlements[1], &roads[4], &roads[8], &roads[3],
                        {9, resource::WOOD}, {2, resource::SHEEP}, {0, resource::NONE});
    settlements[6].load(6, owner::EMPTY, nullptr, &settlements[10], &settlements[2], nullptr, &roads[9], &roads[5],
                        {9, resource::WOOD}, {0, resource::NONE}, {0, resource::NONE});
    settlements[7].load(7, owner::EMPTY, &settlements[3], &settlements[12], &settlements[11], &roads[6], &roads[11], &roads[10],
                        {10, resource::STONE}, {12, resource::WHEAT}, {0, resource::NONE});
    settlements[8].load(8, owner::EMPTY, &settlements[4], &settlements[13], &settlements[12], &roads[7], &roads[13], &roads[12],
                        {2, resource::SHEEP}, {10, resource::STONE}, {6, resource::BRICK});
    settlements[9].load(9, owner::EMPTY, &settlements[5], &settlements[14], &settlements[13], &roads[8], &roads[15], &roads[14],
                        {9, resource::WOOD}, {2, resource::SHEEP}, {4, resource::SHEEP});
    settlements[10].load(10, owner::EMPTY, &settlements[6], &settlements[15], &settlements[14], &roads[9], &roads[16], &roads[17],
                         {9, resource::WOOD}, {10, resource::BRICK}, {0, resource::NONE});
    settlements[11].load(11, owner::EMPTY, &settlements[7], &settlements[16], nullptr, &roads[10], &roads[18], nullptr,
                         {12, resource::WHEAT}, {0, resource::NONE}, {0, resource::NONE});
    settlements[12].load(12, owner::EMPTY, &settlements[8], &settlements[17], &settlements[7], &roads[12], &roads[19], &roads[11],
                         {6, resource::BRICK}, {10, resource::STONE}, {12, resource::WHEAT});
    settlements[13].load(13, owner::EMPTY, &settlements[9], &settlements[18], &settlements[8], &roads[14], &roads[20], &roads[13],
                         {4, resource::SHEEP}, {2, resource::SHEEP}, {6, resource::BRICK});
    settlements[14].load(14, owner::EMPTY, &settlements[10], &settlements[19], &settlements[9], &roads[16], &roads[21], &roads[15],
                         {10, resource::BRICK}, {9, resource::WOOD}, {4, resource::SHEEP});
    settlements[15].load(15, owner::EMPTY, nullptr, &settlements[20], &settlements[10], nullptr, &roads[22], &roads[17],
                         {10, resource::BRICK}, {0, resource::NONE}, {0, resource::NONE});
    settlements[16].load(16, owner::EMPTY, &settlements[11], &settlements[22], &settlements[21], &roads[18], &roads[24], &roads[23],
                         {12, resource::WHEAT}, {9, resource::WHEAT}, {0, resource::NONE});
    settlements[17].load(17, owner::EMPTY, &settlements[12], &settlements[23], &settlements[22], &roads[19], &roads[26], &roads[25],
                         {6, resource::BRICK}, {11, resource::WOOD}, {12, resource::WHEAT});
    settlements[18].load(18, owner::EMPTY, &settlements[13], &settlements[24], &settlements[23], &roads[20], &roads[28], &roads[27],
                         {4, resource::SHEEP}, {6, resource::BRICK}, {0, resource::NONE});
    settlements[19].load(19, owner::EMPTY, &settlements[14], &settlements[25], &settlements[24], &roads[21], &roads[30], &roads[29],
                         {10, resource::BRICK}, {4, resource::SHEEP}, {3, resource::WOOD});
    settlements[20].load(20, owner::EMPTY, &settlements[15], &settlements[26], &settlements[25], &roads[22], &roads[32], &roads[31],
                         {10, resource::BRICK}, {8, resource::STONE}, {0, resource::NONE});
    settlements[21].load(21, owner::EMPTY, &settlements[16], &settlements[27], nullptr, &roads[23], &roads[33], nullptr,
                         {9, resource::WHEAT}, {0, resource::NONE}, {0, resource::NONE});
    settlements[22].load(22, owner::EMPTY, &settlements[17], &settlements[28], &settlements[16], &roads[25], &roads[34], &roads[24],
                         {11, resource::WOOD}, {9, resource::WHEAT}, {12, resource::WHEAT});
    settlements[23].load(23, owner::EMPTY, &settlements[18], &settlements[29], &settlements[17], &roads[27], &roads[35], &roads[26],
                         {6, resource::BRICK}, {11, resource::WOOD}, {0, resource::NONE});
    settlements[24].load(24, owner::EMPTY, &settlements[19], &settlements[30], &settlements[18], &roads[29], &roads[36], &roads[28],
                         {3, resource::WOOD}, {4, resource::SHEEP}, {0, resource::NONE});
    settlements[25].load(25, owner::EMPTY, &settlements[20], &settlements[31], &settlements[19], &roads[31], &roads[37], &roads[30],
                         {8, resource::STONE}, {10, resource::BRICK}, {3, resource::WOOD});
    settlements[26].load(26, owner::EMPTY, nullptr, &settlements[32], &settlements[20], nullptr, &roads[38], &roads[32],
                         {8, resource::STONE}, {0, resource::NONE}, {0, resource::NONE});
    settlements[27].load(27, owner::EMPTY, &settlements[21], &settlements[33], nullptr, &roads[33], &roads[39], nullptr,
                         {9, resource::WHEAT}, {0, resource::NONE}, {0, resource::NONE});
    settlements[28].load(28, owner::EMPTY, &settlements[22], &settlements[34], &settlements[33], &roads[34], &roads[41], &roads[40],
                         {11, resource::WOOD}, {8, resource::WOOD}, {9, resource::WHEAT});
    settlements[29].load(29, owner::EMPTY, &settlements[23], &settlements[35], &settlements[34], &roads[35], &roads[43], &roads[42],
                         {11, resource::WOOD}, {3, resource::STONE}, {0, resource::NONE});
    settlements[30].load(30, owner::EMPTY, &settlements[24], &settlements[36], &settlements[35], &roads[36], &roads[45], &roads[44],
                         {3, resource::WOOD}, {4, resource::WHEAT}, {0, resource::NONE});
    settlements[31].load(31, owner::EMPTY, &settlements[25], &settlements[37], &settlements[36], &roads[37], &roads[47], &roads[46],
                         {8, resource::STONE}, {5, resource::SHEEP}, {3, resource::WOOD});
    settlements[32].load(32, owner::EMPTY, &settlements[26], nullptr, &settlements[37], &roads[38], nullptr, &roads[48],
                         {8, resource::STONE}, {0, resource::NONE}, {0, resource::NONE});
    settlements[33].load(33, owner::EMPTY, &settlements[28], &settlements[38], &settlements[27], &roads[40], &roads[49], &roads[39],
                         {8, resource::WOOD}, {9, resource::WHEAT}, {0, resource::NONE});
    settlements[34].load(34, owner::EMPTY, &settlements[29], &settlements[39], &settlements[28], &roads[42], &roads[50], &roads[41],
                         {3, resource::STONE}, {11, resource::WOOD}, {8, resource::WOOD});
    settlements[35].load(35, owner::EMPTY, &settlements[30], &settlements[40], &settlements[29], &roads[44], &roads[51], &roads[43],
                         {4, resource::WHEAT}, {3, resource::STONE}, {0, resource::NONE});
    settlements[36].load(36, owner::EMPTY, &settlements[31], &settlements[41], &settlements[30], &roads[46], &roads[52], &roads[45],
                         {5, resource::SHEEP}, {3, resource::WOOD}, {4, resource::WHEAT});
    settlements[37].load(37, owner::EMPTY, &settlements[32], &settlements[42], &settlements[31], &roads[48], &roads[53], &roads[47],
                         {8, resource::STONE}, {5, resource::SHEEP}, {0, resource::NONE});
    settlements[38].load(38, owner::EMPTY, &settlements[33], &settlements[43], nullptr, &roads[49], &roads[54], nullptr,
                         {8, resource::WOOD}, {0, resource::NONE}, {0, resource::NONE});
    settlements[39].load(39, owner::EMPTY, &settlements[34], &settlements[44], &settlements[43], &roads[50], &roads[56], &roads[55],
                         {5, resource::BRICK}, {3, resource::STONE}, {8, resource::WOOD});
    settlements[40].load(40, owner::EMPTY, &settlements[35], &settlements[45], &settlements[44], &roads[51], &roads[58], &roads[57],
                         {4, resource::WHEAT}, {6, resource::WHEAT}, {3, resource::STONE});
    settlements[41].load(41, owner::EMPTY, &settlements[36], &settlements[46], &settlements[45], &roads[52], &roads[60], &roads[59],
                         {5, resource::SHEEP}, {4, resource::WHEAT}, {11, resource::SHEEP});
    settlements[42].load(42, owner::EMPTY, &settlements[37], nullptr, &settlements[46], &roads[53], nullptr, &roads[61],
                         {5, resource::SHEEP}, {0, resource::NONE}, {0, resource::NONE});
    settlements[43].load(43, owner::EMPTY, &settlements[39], &settlements[47], &settlements[38], &roads[55], &roads[62], &roads[54],
                         {8, resource::WOOD}, {5, resource::BRICK}, {0, resource::NONE});
    settlements[44].load(44, owner::EMPTY, &settlements[40], &settlements[48], &settlements[39], &roads[57], &roads[63], &roads[56],
                         {6, resource::WHEAT}, {5, resource::BRICK}, {3, resource::STONE});
    settlements[45].load(45, owner::EMPTY, &settlements[41], &settlements[49], &settlements[40], &roads[59], &roads[64], &roads[58],
                         {11, resource::SHEEP}, {4, resource::WHEAT}, {6, resource::WHEAT});
    settlements[46].load(46, owner::EMPTY, &settlements[42], &settlements[50], &settlements[41], &roads[61], &roads[65], &roads[60],
                         {5, resource::SHEEP}, {11, resource::SHEEP}, {0, resource::NONE});
    settlements[47].load(47, owner::EMPTY, &settlements[43], &settlements[51], nullptr, &roads[62], &roads[66], nullptr,
                         {5, resource::BRICK}, {0, resource::NONE}, {0, resource::NONE});
    settlements[48].load(48, owner::EMPTY, &settlements[44], &settlements[52], &settlements[51], &roads[63], &roads[68], &roads[67],
                         {5, resource::BRICK}, {6, resource::WHEAT}, {0, resource::NONE});
    settlements[49].load(49, owner::EMPTY, &settlements[45], &settlements[53], &settlements[52], &roads[64], &roads[70], &roads[69],
                         {11, resource::SHEEP}, {6, resource::WHEAT}, {0, resource::NONE});
    settlements[50].load(50, owner::EMPTY, &settlements[46], nullptr, &settlements[53], &roads[65], nullptr, &roads[71],
                         {11, resource::SHEEP}, {0, resource::NONE}, {0, resource::NONE});
    settlements[51].load(51, owner::EMPTY, &settlements[48], nullptr, &settlements[47], &roads[67], nullptr, &roads[66],
                         {5, resource::BRICK}, {0, resource::NONE}, {0, resource::NONE});
    settlements[52].load(52, owner::EMPTY, &settlements[49], nullptr, &settlements[48], &roads[69], nullptr, &roads[68],
                         {6, resource::WHEAT}, {0, resource::NONE}, {0, resource::NONE});
    settlements[53].load(53, owner::EMPTY, &settlements[50], nullptr, &settlements[49], &roads[71], nullptr, &roads[70],
                         {11, resource::SHEEP}, {0, resource::NONE}, {0, resource::NONE});

    roads[0].load(0, owner::EMPTY, &settlements[0], &settlements[3], nullptr, &roads[1], &roads[6], nullptr);
    roads[1].load(1, owner::EMPTY, &settlements[0], &settlements[4], &roads[0], nullptr, &roads[2], &roads[7]);
    roads[2].load(2, owner::EMPTY, &settlements[1], &settlements[4], nullptr, &roads[3], &roads[1], &roads[7]);
    roads[3].load(3, owner::EMPTY, &settlements[1], &settlements[5], &roads[2], nullptr, &roads[4], &roads[8]);
    roads[4].load(4, owner::EMPTY, &settlements[2], &settlements[5], nullptr, &roads[5], &roads[3], &roads[8]);
    roads[5].load(5, owner::EMPTY, &settlements[2], &settlements[6], &roads[4], nullptr, &roads[9], nullptr);
    roads[6].load(6, owner::EMPTY, &settlements[3], &settlements[7], nullptr, &roads[0], &roads[10], &roads[11]);
    roads[7].load(7, owner::EMPTY, &settlements[4], &settlements[8], &roads[1], &roads[2], &roads[12], &roads[13]);
    roads[8].load(8, owner::EMPTY, &settlements[5], &settlements[9], &roads[3], &roads[4], &roads[14], &roads[15]);
    roads[9].load(9, owner::EMPTY, &settlements[6], &settlements[10], &roads[5], nullptr, &roads[16], &roads[17]);
    roads[10].load(10, owner::EMPTY, &settlements[7], &settlements[11], &roads[6], &roads[11], &roads[18], nullptr);
    roads[11].load(11, owner::EMPTY, &settlements[7], &settlements[12], &roads[6], &roads[10], &roads[19], &roads[12]);
    roads[12].load(12, owner::EMPTY, &settlements[8], &settlements[12], &roads[7], &roads[13], &roads[11], &roads[19]);
    roads[13].load(13, owner::EMPTY, &settlements[8], &settlements[13], &roads[7], &roads[12], &roads[20], &roads[14]);
    roads[14].load(14, owner::EMPTY, &settlements[9], &settlements[13], &roads[8], &roads[15], &roads[13], &roads[20]);
    roads[15].load(15, owner::EMPTY, &settlements[9], &settlements[14], &roads[8], &roads[14], &roads[21], &roads[16]);
    roads[16].load(16, owner::EMPTY, &settlements[10], &settlements[14], &roads[9], &roads[17], &roads[15], &roads[21]);
    roads[17].load(17, owner::EMPTY, &settlements[10], &settlements[15], &roads[9], &roads[16], &roads[22], nullptr);
    roads[18].load(18, owner::EMPTY, &settlements[11], &settlements[16], &roads[10], nullptr, &roads[23], &roads[24]);
    roads[19].load(19, owner::EMPTY, &settlements[12], &settlements[17], &roads[11], &roads[12], &roads[25], &roads[26]);
    roads[20].load(20, owner::EMPTY, &settlements[13], &settlements[18], &roads[13], &roads[14], &roads[27], &roads[28]);
    roads[21].load(21, owner::EMPTY, &settlements[14], &settlements[19], &roads[15], &roads[16], &roads[29], &roads[30]);
    roads[22].load(22, owner::EMPTY, &settlements[15], &settlements[20], &roads[17], nullptr, &roads[31], &roads[32]);
    roads[23].load(23, owner::EMPTY, &settlements[16], &settlements[21], &roads[18], &roads[24], &roads[33], nullptr);
    roads[24].load(24, owner::EMPTY, &settlements[16], &settlements[22], &roads[18], &roads[23], &roads[34], &roads[25]);
    roads[25].load(25, owner::EMPTY, &settlements[17], &settlements[22], &roads[19], &roads[26], &roads[24], &roads[34]);
    roads[26].load(26, owner::EMPTY, &settlements[17], &settlements[23], &roads[19], &roads[25], &roads[35], &roads[27]);
    roads[27].load(27, owner::EMPTY, &settlements[18], &settlements[23], &roads[20], &roads[28], &roads[26], &roads[35]);
    roads[28].load(28, owner::EMPTY, &settlements[18], &settlements[24], &roads[20], &roads[27], &roads[36], &roads[29]);
    roads[29].load(29, owner::EMPTY, &settlements[19], &settlements[24], &roads[21], &roads[30], &roads[28], &roads[36]);
    roads[30].load(30, owner::EMPTY, &settlements[19], &settlements[25], &roads[21], &roads[29], &roads[37], &roads[31]);
    roads[31].load(31, owner::EMPTY, &settlements[20], &settlements[25], &roads[22], &roads[32], &roads[30], &roads[37]);
    roads[32].load(32, owner::EMPTY, &settlements[20], &settlements[26], &roads[22], &roads[31], &roads[38], nullptr);
    roads[33].load(33, owner::EMPTY, &settlements[21], &settlements[27], &roads[23], nullptr, &roads[39], nullptr);
    roads[34].load(34, owner::EMPTY, &settlements[22], &settlements[28], &roads[24], &roads[25], &roads[40], &roads[41]);
    roads[35].load(35, owner::EMPTY, &settlements[23], &settlements[29], &roads[26], &roads[27], &roads[42], &roads[43]);
    roads[36].load(36, owner::EMPTY, &settlements[24], &settlements[30], &roads[28], &roads[29], &roads[44], &roads[45]);
    roads[37].load(37, owner::EMPTY, &settlements[25], &settlements[31], &roads[30], &roads[31], &roads[46], &roads[47]);
    roads[38].load(38, owner::EMPTY, &settlements[26], &settlements[32], &roads[32], nullptr, &roads[48], nullptr);
    roads[39].load(39, owner::EMPTY, &settlements[27], &settlements[33], &roads[33], nullptr, &roads[49], &roads[40]);
    roads[40].load(40, owner::EMPTY, &settlements[28], &settlements[33], &roads[34], &roads[41], &roads[39], &roads[49]);
    roads[41].load(41, owner::EMPTY, &settlements[28], &settlements[34], &roads[34], &roads[40], &roads[50], &roads[42]);
    roads[42].load(42, owner::EMPTY, &settlements[29], &settlements[34], &roads[35], &roads[43], &roads[41], &roads[50]);
    roads[43].load(43, owner::EMPTY, &settlements[29], &settlements[35], &roads[35], &roads[42], &roads[51], &roads[44]);
    roads[44].load(44, owner::EMPTY, &settlements[30], &settlements[35], &roads[36], &roads[45], &roads[43], &roads[51]);
    roads[45].load(45, owner::EMPTY, &settlements[30], &settlements[36], &roads[36], &roads[44], &roads[52], &roads[46]);
    roads[46].load(46, owner::EMPTY, &settlements[31], &settlements[36], &roads[37], &roads[47], &roads[45], &roads[52]);
    roads[47].load(47, owner::EMPTY, &settlements[31], &settlements[37], &roads[37], &roads[46], &roads[53], &roads[48]);
    roads[48].load(48, owner::EMPTY, &settlements[32], &settlements[37], &roads[38], nullptr, &roads[47], &roads[53]);
    roads[49].load(49, owner::EMPTY, &settlements[33], &settlements[38], &roads[39], &roads[40], &roads[54], nullptr);
    roads[50].load(50, owner::EMPTY, &settlements[34], &settlements[39], &roads[41], &roads[42], &roads[55], &roads[56]);
    roads[51].load(51, owner::EMPTY, &settlements[35], &settlements[40], &roads[43], &roads[44], &roads[57], &roads[58]);
    roads[52].load(52, owner::EMPTY, &settlements[36], &settlements[41], &roads[45], &roads[46], &roads[59], &roads[60]);
    roads[53].load(53, owner::EMPTY, &settlements[37], &settlements[42], &roads[47], &roads[48], &roads[61], nullptr);
    roads[54].load(54, owner::EMPTY, &settlements[38], &settlements[43], &roads[49], nullptr, &roads[62], &roads[55]);
    roads[55].load(55, owner::EMPTY, &settlements[39], &settlements[43], &roads[50], &roads[56], &roads[54], &roads[62]);
    roads[56].load(56, owner::EMPTY, &settlements[39], &settlements[44], &roads[50], &roads[55], &roads[63], &roads[57]);
    roads[57].load(57, owner::EMPTY, &settlements[40], &settlements[44], &roads[51], &roads[58], &roads[56], &roads[63]);
    roads[58].load(58, owner::EMPTY, &settlements[40], &settlements[45], &roads[51], &roads[57], &roads[64], &roads[59]);
    roads[59].load(59, owner::EMPTY, &settlements[41], &settlements[45], &roads[52], &roads[60], &roads[58], &roads[64]);
    roads[60].load(60, owner::EMPTY, &settlements[41], &settlements[46], &roads[52], &roads[59], &roads[65], &roads[61]);
    roads[61].load(61, owner::EMPTY, &settlements[42], &settlements[46], &roads[53], nullptr, &roads[60], &roads[65]);
    roads[62].load(62, owner::EMPTY, &settlements[43], &settlements[47], &roads[54], &roads[55], &roads[66], nullptr);
    roads[63].load(63, owner::EMPTY, &settlements[44], &settlements[48], &roads[56], &roads[57], &roads[67], &roads[68]);
    roads[64].load(64, owner::EMPTY, &settlements[45], &settlements[49], &roads[58], &roads[59], &roads[69], &roads[70]);
    roads[65].load(65, owner::EMPTY, &settlements[46], &settlements[50], &roads[60], &roads[61], &roads[71], nullptr);
    roads[66].load(66, owner::EMPTY, &settlements[47], &settlements[51], &roads[62], nullptr, &roads[67], nullptr);
    roads[67].load(67, owner::EMPTY, &settlements[48], &settlements[51], &roads[63], &roads[68], &roads[66], nullptr);
    roads[68].load(68, owner::EMPTY, &settlements[48], &settlements[52], &roads[63], &roads[67], &roads[69], nullptr);
    roads[69].load(69, owner::EMPTY, &settlements[49], &settlements[52], &roads[64], &roads[70], &roads[68], nullptr);
    roads[70].load(70, owner::EMPTY, &settlements[49], &settlements[53], &roads[64], &roads[69], &roads[71], nullptr);
    roads[71].load(71, owner::EMPTY, &settlements[50], &settlements[53], &roads[65], nullptr, &roads[70], nullptr);
}

// TODO: shuffle cards
void CatanGame::shuffleCards() {
}

// TODO: display board
void CatanGame::displayBoard() {
    
}

// TODO: prep round
void CatanGame::prepRound() {
}

int CatanGame::diceRoll() {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}

void CatanGame::distributeResources(int diceRoll) {
    diceRoll -= 2;
    for (int i = 0; i < paiment[diceRoll].size(); i++) {
        if (paiment[diceRoll][i].first == owner::YELLOW) {
            players[YELLOW].incrementResource(paiment[diceRoll][i].second);
        } else if (paiment[diceRoll][i].first == owner::BLUE) {
            players[BLUE].incrementResource(paiment[diceRoll][i].second);
        } else if (paiment[diceRoll][i].first == owner::RED) {
            players[RED].incrementResource(paiment[diceRoll][i].second);
        }
    }
}



int CatanGame::play() {
    init();
    displayBoard();
    return 0;
}