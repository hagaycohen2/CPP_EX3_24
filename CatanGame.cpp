#include "CatanGame.hpp"

#include "Card.hpp"
#include "CatanObject.hpp"

CatanGame::CatanGame() {
    players[0].setId(owner::YELLOW);
    players[1].setId(owner::BLUE);
    players[2].setId(owner::RED);
    cards = {Card(KNIGHT),Card(KNIGHT),Card(KNIGHT),Card(VICTORY_POINT),Card(VICTORY_POINT),Card(VICTORY_POINT),Card(VICTORY_POINT),
             Card(ROAD_BUILDING),Card(ROAD_BUILDING),Card(MONOPOLY),Card(MONOPOLY),Card(YEAR_OF_PLENTY),Card(YEAR_OF_PLENTY)};
}

void CatanGame::init() {
    for (int i = 0; i < 3; i++) {
        knightCount[i] = 0;
    }

    for (int i = 0; i < 11; i++) {
        payment[i] = {};
    }

   cout << "Initializing the game board..." << endl;

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

void CatanGame::shuffleCards() {
    cout << "Shuffling cards..." << endl;
    for (int i = 0; i < cards.size(); i++) {
        int j = rand() % cards.size();
        cards.push_back(cards[j]);
        cards[j] = cards[i];
        cards[i] = cards.back();
        cards.pop_back();
    }
}

void CatanGame::displayBoard() {
    cout << "\n--------------------- Catan Board ---------------------" << endl;
    cout << "Players status: " << endl;
    for (int i = 0; i < 3; i++) {
        Player& player = players[i];
        cout << player.getColor() << player.getOwner() << "\033[0m" << " has " << player.getVictoryPoints() << " victory points, and " << knightCount[i] << " knights." << endl;
    }

    cout << "                  " << settlements[0].getColor() << settlements[0].getChar() << "         " << settlements[1].getColor() << settlements[1].getChar() << "         " << settlements[2].getColor() << settlements[2].getChar() << endl;
    cout << "               " << roads[0].getColor() << " / " << "   " << roads[1].getColor() << " \\ " << "   " << roads[2].getColor() << " / " << "   " << roads[3].getColor() << " \\ " << "   " << roads[4].getColor() << " / " << "   " << roads[5].getColor() << " \\ " << endl;
    cout << "            " << settlements[3].getColor() << settlements[3].getChar() << "         " << settlements[4].getColor() << settlements[4].getChar() << "         " << settlements[5].getColor() << settlements[5].getChar() << "         " << settlements[6].getColor() << settlements[6].getChar() << endl;
    cout << "            " << roads[6].getColor() << " | " << "\033[0m" << getResourceName(STONE) << "  10  " << roads[7].getColor() << " | " << "\033[0m" << getResourceName(SHEEP) << "  2  " << roads[8].getColor() << " | " << "\033[0m" << getResourceName(WOOD) << "  9   " << roads[9].getColor() << " | " << endl;
    cout << "            " << settlements[7].getColor() << settlements[7].getChar() << "         " << settlements[8].getColor() << settlements[8].getChar() << "         " << settlements[9].getColor() << settlements[9].getChar() << "         " << settlements[10].getColor() << settlements[10].getChar() << endl;
    cout << "         " << roads[10].getColor() << " / " << "   " << roads[11].getColor() << " \\ " << "   " << roads[12].getColor() << " / " << "   " << roads[13].getColor() << " \\ " << "   " << roads[14].getColor() << " / " << "   " << roads[15].getColor() << " \\ " << "   " << roads[16].getColor() << " / " << "   " << roads[17].getColor() << " \\ " << endl;
    cout << "      " << settlements[11].getColor() << settlements[11].getChar() << "         " << settlements[12].getColor() << settlements[12].getChar() << "         " << settlements[13].getColor() << settlements[13].getChar() << "         " << settlements[14].getColor() << settlements[14].getChar() << "         " << settlements[15].getColor() << settlements[15].getChar() << endl;
    cout << "      " << roads[18].getColor() << " | " << "\033[0m" << getResourceName(WHEAT) << "  12 " << roads[19].getColor() << " | " << "\033[0m" << getResourceName(BRICK) << "  6  " << roads[20].getColor() << " | " << "\033[0m" << getResourceName(SHEEP) << "  4  " << roads[21].getColor() << " | " << "\033[0m" << getResourceName(BRICK) << "  10 " << roads[22].getColor() << " | " << endl;
    cout << "      " << settlements[16].getColor() << settlements[16].getChar() << "         " << settlements[17].getColor() << settlements[17].getChar() << "         " << settlements[18].getColor() << settlements[18].getChar() << "         " << settlements[19].getColor() << settlements[19].getChar() << "         " << settlements[20].getColor() << settlements[20].getChar() << endl;
    cout << "   " << roads[23].getColor() << " / " << "   " << roads[24].getColor() << " \\ " << "   " << roads[25].getColor() << " / " << "   " << roads[26].getColor() << " \\ " << "   " << roads[27].getColor() << " / " << "   " << roads[28].getColor() << " \\ " << "   " << roads[29].getColor() << " / " << "   " << roads[30].getColor() << " \\ " << "   " << roads[31].getColor() << " / " << "   " << roads[32].getColor() << " \\ " << endl;
    cout << settlements[21].getColor() << settlements[21].getChar() << "         " << settlements[22].getColor() << settlements[22].getChar() << "         " << settlements[23].getColor() << settlements[23].getChar() << "         " << settlements[24].getColor() << settlements[24].getChar() << "         " << settlements[25].getColor() << settlements[25].getChar() << "         " << settlements[26].getColor() << settlements[26].getChar() << endl;
    cout << roads[33].getColor() << " | " << "\033[0m" << getResourceName(WHEAT) << "  9  " << roads[34].getColor() << " | " << "\033[0m" << getResourceName(WOOD) << "  11  " << roads[35].getColor() << " | " << "\033[0m" << getResourceName(NONE) << "  7  " << roads[36].getColor() << " | " << "\033[0m" << getResourceName(WOOD) << "  3   " << roads[37].getColor() << " | " << "\033[0m" << getResourceName(STONE) << "  8   " << roads[38].getColor() << " | " << endl;
    cout << settlements[27].getColor() << settlements[27].getChar() << "         " << settlements[28].getColor() << settlements[28].getChar() << "         " << settlements[29].getColor() << settlements[29].getChar() << "         " << settlements[30].getColor() << settlements[30].getChar() << "         " << settlements[31].getColor() << settlements[31].getChar() << "         " << settlements[32].getColor() << settlements[32].getChar() << endl;
    cout << "   " << roads[39].getColor() << " \\ " << "   " << roads[40].getColor() << " / " << "   " << roads[41].getColor() << " \\ " << "   " << roads[42].getColor() << " / " << "   " << roads[43].getColor() << " \\ " << "   " << roads[44].getColor() << " / " << "   " << roads[45].getColor() << " \\ " << "   " << roads[46].getColor() << " / " << "   " << roads[47].getColor() << " \\ " << "   " << roads[48].getColor() << " / " << endl;
    cout << "      " << settlements[33].getColor() << settlements[33].getChar() << "         " << settlements[34].getColor() << settlements[34].getChar() << "         " << settlements[35].getColor() << settlements[35].getChar() << "         " << settlements[36].getColor() << settlements[36].getChar() << "         " << settlements[37].getColor() << settlements[37].getChar() << endl;
    cout << "      " << roads[49].getColor() << " | " << "\033[0m" << getResourceName(WOOD) << "  8   " << roads[50].getColor() << " | " << "\033[0m" << getResourceName(STONE) << "  3   " << roads[51].getColor() << " | " << "\033[0m" << getResourceName(WHEAT) << "  4  " << roads[52].getColor() << " | " << "\033[0m" << getResourceName(SHEEP) << "  5  " << roads[53].getColor() << " | " << endl;
    cout << "      " << settlements[38].getColor() << settlements[38].getChar() << "         " << settlements[39].getColor() << settlements[39].getChar() << "         " << settlements[40].getColor() << settlements[40].getChar() << "         " << settlements[41].getColor() << settlements[41].getChar() << "         " << settlements[42].getColor() << settlements[42].getChar() << endl;
    cout << "         " << roads[54].getColor() << " \\ " << "   " << roads[55].getColor() << " / " << "   " << roads[56].getColor() << " \\ " << "   " << roads[57].getColor() << " / " << "   " << roads[58].getColor() << " \\ " << "   " << roads[59].getColor() << " / " << "   " << roads[60].getColor() << " \\ " << "   " << roads[61].getColor() << " / " << endl;
    cout << "            " << settlements[43].getColor() << settlements[43].getChar() << "         " << settlements[44].getColor() << settlements[44].getChar() << "         " << settlements[45].getColor() << settlements[45].getChar() << "         " << settlements[46].getColor() << settlements[46].getChar() << endl;
    cout << "            " << roads[62].getColor() << " | " << "\033[0m" << getResourceName(BRICK) << "  5  " << roads[63].getColor() << " | " << "\033[0m" << getResourceName(WHEAT) << "  6  " << roads[64].getColor() << " | " << "\033[0m" << getResourceName(SHEEP) << "  11 " << roads[65].getColor() << " | " << endl;
    cout << "            " << settlements[47].getColor() << settlements[47].getChar() << "         " << settlements[48].getColor() << settlements[48].getChar() << "         " << settlements[49].getColor() << settlements[49].getChar() << "         " << settlements[50].getColor() << settlements[50].getChar() << endl;
    cout << "               " << roads[66].getColor() << " \\ " << "   " << roads[67].getColor() << " / " << "   " << roads[68].getColor() << " \\ " << "   " << roads[69].getColor() << " / " << "   " << roads[70].getColor() << " \\ " << "   " << roads[71].getColor() << " / " << endl;
    cout << "                  " << settlements[51].getColor() << settlements[51].getChar() << "         " << settlements[52].getColor() << settlements[52].getChar() << "         " << settlements[53].getColor() << settlements[53].getChar() << endl;
    cout << "-------------------------------------------------------\n"
         << endl;
}

void CatanGame::prepRound() {
    cout << "Prepping round" << endl;
    for (int j = 0; j < 6; j++) {
        int i = j % 3;
        cout << players[i].getColor() << players[i].getOwner() << "'s turn" << "\033[0m" << endl;
        while (true) {
            cout << "please place a settlement, insert settlement id: ";
            int settlement;
            cin >> settlement;
            if (settlement < 0 || settlement > 53) {
                cout << "Invalid settlement id" << endl;
            } else if (settlements[settlement].preOccupationAtempt(players[i].getId())) {
                addPayment(players[i].getId(), settlements[settlement].getResources());
                players[i].incrementVictoryPoints();
                displayBoard();
                break;
            } else {
                cout << "Settlement placement failed" << endl;
            }
        }
        while (true) {
            cout << "please place a road, insert road id: ";
            int road;
            cin >> road;
            if (road < 0 || road > 71) {
                cout << "Invalid road id" << endl;
            } else if (roads[road].occupationAtempt(players[i].getId())) {
                displayBoard();
                break;
            } else {
                cout << "Road placement failed" << endl;
            }
        }
    }
    for (int i = 2; i < 13; i++) {
        distributeResources(i);
    }
    for (int i = 0; i < 3; i++) {
        cout << players[i].getColor() << players[i].getOwner() << "'s display" << "\033[0m" << endl;
        players[i].displayResources();
    }
}

int CatanGame::diceRoll() {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}

void CatanGame::diceRoll_7() {
}

void CatanGame::distributeResources(int diceRoll) {
    diceRoll -= 2;
    for (int i = 0; i < payment[diceRoll].size(); i++) {
        if (payment[diceRoll][i].first == owner::YELLOW) {
            players[YELLOW].incrementResource(payment[diceRoll][i].second);
        } else if (payment[diceRoll][i].first == owner::BLUE) {
            players[BLUE].incrementResource(payment[diceRoll][i].second);
        } else if (payment[diceRoll][i].first == owner::RED) {
            players[RED].incrementResource(payment[diceRoll][i].second);
        }
    }
}

void CatanGame::addPayment(owner player, pair<int, resource>* resourceVec) {
    for (int i = 0; i < 3; i++) {
        pair<owner, resource> paymentPair = {player, resourceVec[i].second};
        payment[resourceVec[i].first - 2].push_back(paymentPair);
    }
}

bool CatanGame::buildSettlement(int playerId, int settlementId) {
    if (settlementId < 0 || settlementId > 53) {
        cout << "Invalid settlement id" << endl;
        return false;
    }
    Player& player = players[playerId];
    Settlement& settlement = settlements[settlementId];
    if (player.getResource(BRICK) > 0 && player.getResource(WOOD) > 0 && player.getResource(SHEEP) > 0 && player.getResource(WHEAT) > 0) {
        bool occupied = settlement.occupationAtempt(player.getId());
        if (occupied) {
            player.decrementResource(BRICK);
            player.decrementResource(WOOD);
            player.decrementResource(SHEEP);
            player.decrementResource(WHEAT);
            player.incrementVictoryPoints();
            addPayment(player.getId(), settlement.getResources());
            displayBoard();
            return true;
        }
        cout << "Settlement placement failed" << endl;
        return false;
    }
    cout << "Not enough resources" << endl;
    return false;
}

bool CatanGame::buildRoad(int playerId, int roadId) {
    if (roadId < 0 || roadId > 71) {
        cout << "Invalid road id" << endl;
        return false;
    }
    Player& player = players[playerId];
    Road& road = roads[roadId];
    if (player.getResource(BRICK) > 0 && player.getResource(WOOD) > 0) {
        bool occupied = road.occupationAtempt(player.getId());
        if (occupied) {
            player.decrementResource(BRICK);
            player.decrementResource(WOOD);
            displayBoard();
            return true;
        }
        cout << "Road placement failed" << endl;
        return false;
    }
    cout << "Not enough resources" << endl;
    return false;
}

bool CatanGame::buildCity(int playerId, int settlementId) {
    if (settlementId < 0 || settlementId > 53) {
        cout << "Invalid settlement id" << endl;
        return false;
    }
    Player& player = players[playerId];
    Settlement& settlement = settlements[settlementId];
    if (player.getResource(STONE) > 2 && player.getResource(WHEAT) > 1) {
        if (settlement.getOwner() == player.getId() && settlement.getIsCity() == false) {
            settlement.setIsCity();
            player.decrementResource(STONE);
            player.decrementResource(STONE);
            player.decrementResource(STONE);
            player.decrementResource(WHEAT);
            player.decrementResource(WHEAT);
            player.incrementVictoryPoints();
            addPayment(player.getId(), settlement.getResources());
            cout << "City built" << endl;
            displayBoard();
            return true;
        }
        cout << "Settlement is not yours or is already a city" << endl;
        return false;
    }
    cout << "Not enough resources" << endl;
    return false;
}

bool CatanGame::buyCard(int playerId) {
    if (cards.size() == 0) {
        cout << "No more cards" << endl;
        return false;
    }
    Player& player = players[playerId];
    if (player.getResource(SHEEP) > 0 && player.getResource(WHEAT) > 0 && player.getResource(STONE) > 0) {
        player.decrementResource(SHEEP);
        player.decrementResource(WHEAT);
        player.decrementResource(STONE);
        Card card = cards.back();
        cards.pop_back();
        cout << "Card bought" << endl;
        card.display();
        player.addCard(card);
        return true;
    }
    cout << "Not enough resources" << endl;
    return false;
}

int CatanGame::playerCards(int playerId) {
    Player& player = players[playerId];
    cout << "Your cards: " << endl;
    player.displayCards();
    cout << "Please enter the index of the card you want to play, or -1 to pass: ";
    int index;
    cin >> index;
    if (index < 0 || index >= player.getCardCount()) {
        cout << "Invalid index" << endl;
        return -1;
    }
    return index;
}

void CatanGame::playCard(int playerId, type cardType) {
    cout << "\nPlaying card" << endl;
    Player& player = players[playerId];
    switch (cardType) {
        case KNIGHT:
            knightCount[playerId]++;
            cout << "Knight added" << endl;
            if (knightCount[playerId] >= 3) {
                player.incrementVictoryPoints();
            }
            break;
        case VICTORY_POINT:
            player.incrementVictoryPoints();
            cout << "Victory point added" << endl;
            break;
        case MONOPOLY:
            cout << "Monopoly card played" << endl;
            playMonopoly(playerId);
            break;
        case ROAD_BUILDING:
            cout << "Road building card played" << endl;
            playRoadBuilding(playerId);
            break;
        case YEAR_OF_PLENTY:
            cout << "Year of plenty card played" << endl;
            playYearOfPlenty(playerId);
            break;
        default:
            break;
    }
    displayBoard();
}

void CatanGame::playMonopoly(int playerId) {
    cout << "your resources: " << endl;
    players[playerId].displayResources();
    resource monopoly = NONE;
    while (monopoly == NONE) {
        cout << "resources index: 0 = STONE, 1 = WOOD, 2 = BRICK, 3 = SHEEP, 4 = WHEAT" << endl;
        cout << "Please enter the resource you want to monopolize: ";
        int res;
        cin >> res;
        if (res < 0 || res > 4) {
            cout << "Invalid resource" << endl;
        } else {
            monopoly = intToResource(res);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (i != playerId) {
            int amount = players[i].getResource(monopoly);
            for (int j = 0; j < amount; j++) {
                players[i].decrementResource(monopoly);
                players[playerId].incrementResource(monopoly);
            }
        }
    }
    cout << "Monopoly successful" << endl;
    for (int i = 0; i < 3; i++) {
        cout << players[i].getColor() << players[i].getOwner() << "'s display:" << "\033[0m" << endl;
        players[i].displayResources();
    }
}

void CatanGame::playRoadBuilding(int playerId) {
    displayBoard();
    int roadId;
    for (int i = 0; i < 2; i++) {
        cout << "Please enter the road id you want to build, or -1 to pass: ";
        while (true) {
            cin >> roadId;
            if (roadId < 0 || roadId > 71) {
                cout << "Invalid road id" << endl;
            } else if (roads[roadId].occupationAtempt(players[playerId].getId())) {
                cout << "Road placed" << endl;
                break;
            } else if (roadId == -1) {
                break;
            } else {
                cout << "Road placement failed, please enter a valid road id: ";
            }
        }
        displayBoard();
    }
    cout << "Road building successful" << endl;
}

void CatanGame::playYearOfPlenty(int playerId) {
    cout << "your resources: " << endl;
    players[playerId].displayResources();
    for (int i = 0; i < 2; i++) {
        cout << "resources index: 0 = STONE, 1 = WOOD, 2 = BRICK, 3 = SHEEP, 4 = WHEAT" << endl;
        cout << "Please enter the resource index you want to take, or -1 to pass: ";
        int resIndex;
        while (true) {
            cin >> resIndex;
            if (resIndex < 0 || resIndex > 4) {
                cout << "Invalid resource index" << endl;
            } else if (resIndex == -1) {
                break;
            } else {
                resource res = intToResource(resIndex);
                players[playerId].incrementResource(res);
                cout << "Resource added" << endl;
                break;
            }
        }
    }
    cout << "Year of plenty successful" << endl;
    cout << players[playerId].getColor() << players[playerId].getOwner() << "'s display:" << "\033[0m" << endl;
    players[playerId].displayResources();
}

resource CatanGame::intToResource(int res) {
    switch (res) {
        case 0:
            return STONE;
        case 1:
            return WOOD;
        case 2:
            return BRICK;
        case 3:
            return SHEEP;
        case 4:
            return WHEAT;
        default:
            return NONE;
    }
}

bool CatanGame::tradeValues(vector<pair<resource, int>>& values) {
    cout << "How many resources do you want to trade? ";
    int n;
    cin >> n;
    if (n < 0 || n > 4) {
        cout << "Invalid number of resources" << endl;
        return false;
    }
    cout << "resources index: 0 = STONE, 1 = WOOD, 2 = BRICK, 3 = SHEEP, 4 = WHEAT" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Please enter the resource you want to trade: ";
        int res;
        cin >> res;
        if (res < 0 || res > 4) {
            cout << "Invalid resource" << endl;
            return false;
        }
        resource r = intToResource(res);
        cout << "Please enter the amount of " << getResourceName(res) << " you want to trade: ";
        int amount;
        cin >> amount;
        if (amount < 0) {
            cout << "Invalid amount" << endl;
            return false;
        }
        pair<resource, int> value = {r, amount};
        values.push_back(value);
    }
    return true;
}

bool CatanGame::makeAnOffer(int playerId, vector<pair<resource, int>>& give, vector<pair<resource, int>>& receive) {
    Player& current = players[playerId];
    int otherPlayerId;
    cout << "Please enter the player id you want to make an offer to: ";
    cin >> otherPlayerId;
    if (otherPlayerId < 0 || otherPlayerId > 2 || otherPlayerId == playerId) {
        cout << "Invalid player id" << endl;
        return false;
    }
    Player& other = players[otherPlayerId];
    for (int i = 0; i < give.size(); i++) {
        if (current.getResource(give[i].first) < give[i].second) {
            cout << "You don't have enough " << getResourceName(give[i].first) << endl;
            return false;
        }
    }
    cout << "public display" << endl;
    cout << "Player " << current.getColor() << current.getOwner() << "\033[0m" << " wants to give:" << endl;
    for (int i = 0; i < give.size(); i++) {
        cout << give[i].second << " " << getResourceName(give[i].first) << endl;
    }

    cout << "to player " << other.getColor() << other.getOwner() << "\033[0m" << " in exchange for:" << endl;
    for (int i = 0; i < receive.size(); i++) {
        cout << receive[i].second << " " << getResourceName(receive[i].first) << endl;
    }
    cout << "Do you accept the offer? (y/n): ";
    char answer;
    cin >> answer;
    if (answer == 'y') {
        for (int i = 0; i < receive.size(); i++) {
            if (other.getResource(receive[i].first) < receive[i].second) {
                cout << "The other player doesn't have enough " << getResourceName(receive[i].first) << endl;
                return false;
            }
        }
        makeTrade(playerId, give, otherPlayerId, receive);
        cout << "Trade successful" << endl;
        for (int i = 0; i < 3; i++) {
            cout << players[i].getColor() << players[i].getOwner() << "'s display:" << "\033[0m" << endl;
            players[i].displayResources();
        }
        return true;
    }
    cout << "Trade declined" << endl;
    return false;
}

void CatanGame::makeTrade(int playerId, vector<pair<resource, int>>& give, int otherPlayerId, vector<pair<resource, int>>& receive) {
    Player& current = players[playerId];
    Player& other = players[otherPlayerId];
    for (int i = 0; i < give.size(); i++) {
        for (int j = 0; j < give[i].second; j++) {
            current.decrementResource(give[i].first);
            other.incrementResource(give[i].first);
        }
    }
    for (int i = 0; i < receive.size(); i++) {
        for (int j = 0; j < receive[i].second; j++) {
            other.decrementResource(receive[i].first);
            current.incrementResource(receive[i].first);
        }
    }
}

bool CatanGame::victroryCheck(int playerId) {
    if (players[playerId].getVictoryPoints() >= 10) {
        cout << "Player " << players[playerId].getColor() << players[playerId].getOwner() << "\033[0m" << " wins!" << endl;
        return true;
    }
    return false;
}

int CatanGame::play() {
    init();
    displayBoard();
    prepRound();
    shuffleCards();
    int tern = 0;
    bool keepTern = true;
    bool keepPlaying = true;
    vector<pair<resource, int>> give = {};
    vector<pair<resource, int>> receive = {};
    int settlementId, roadId, cityId, cardIndex;

    while (keepPlaying) {
        keepTern = true;
        tern = tern % 3;
        Player& player = players[tern];
        cout << player.getColor() << player.getOwner() << "'s turn" << "\033[0m" << endl;
        cout << "Press any key to roll the dice" << endl;
        char c;
        cin >> c;
        int dice = diceRoll();
        cout << "\nDice roll: " << dice << endl;
        if (dice == 7) {
            diceRoll_7();
        } else {
            cout << "Resources distribution\n"
                 << endl;
            distributeResources(dice);
            for (int i = 0; i < 3; i++) {
                cout << players[i].getColor() << players[i].getOwner() << "'s display:" << "\033[0m" << endl;
                players[i].displayResources();
            }
        }
        while (keepTern) {
            cout << player.getColor() << player.getOwner() << "'s display:" << "\033[0m" << endl;
            cout << "1. Build Settlement" << endl;
            cout << "2. Build Road" << endl;
            cout << "3. Build City" << endl;
            cout << "4. Buy Card" << endl;
            cout << "5. Display cards" << endl;
            cout << "6. Make an offer" << endl;
            cout << "7. Display board" << endl;
            cout << "8. Display resources" << endl;
            cout << "9. End turn" << endl;

            int choice;
            cin >> choice;

            if (cin.fail() || choice < 1 || choice > 9) {
                cin.clear();
                cout << "Invalid choice" << endl;
                cin.ignore(1000, '\n');  // clear buffer
                continue;
            }

            switch (choice) {
                case 1:
                    cout << "Please enter the settlement id: ";
                    cin >> settlementId;
                    buildSettlement(tern, settlementId);
                    break;
                case 2:
                    cout << "Please enter the road id: ";
                    cin >> roadId;
                    buildRoad(tern, roadId);
                    break;
                case 3:
                    cout << "Please enter the settlement id: ";
                    cin >> cityId;
                    buildCity(tern, cityId);
                    break;
                case 4:
                    buyCard(tern);
                    break;
                case 5:
                    cardIndex = playerCards(tern);
                    if (cardIndex != -1) {
                        playCard(tern, player.removeCard(cardIndex));
                    }
                    break;
                case 6:
                    cout << "Please enter the resources you want to give" << endl;
                    if (tradeValues(give)) {
                        cout << "Please enter the resources you want to receive" << endl;
                        if (tradeValues(receive)) {
                            makeAnOffer(tern, give, receive);
                        }
                    }
                    give.clear();
                    receive.clear();
                    break;
                case 7:
                    displayBoard();
                    break;
                case 8:
                    player.displayResources();
                    break;
                case 9:
                    keepTern = false;
                    tern++;
                    if (victroryCheck(tern)) {
                        keepPlaying = false;
                    }
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
        }
    }
    return 0;
}

int CatanGame::demo() {
    cout << "Demo" << endl;
    cout << "Prepping round" << endl;
    init();
    displayBoard();

    // player 0
    settlements[19].preOccupationAtempt(YELLOW);
    addPayment(YELLOW, settlements[19].getResources());
    players[YELLOW].incrementVictoryPoints();
    displayBoard();
    roads[30].occupationAtempt(YELLOW);
    displayBoard();

    // player 1
    cout << "BLUE wants to build a settlement on a invalid location" << endl;
    settlements[25].preOccupationAtempt(BLUE);  // invalid
    settlements[31].preOccupationAtempt(BLUE);
    addPayment(BLUE, settlements[31].getResources());
    players[BLUE].incrementVictoryPoints();
    displayBoard();
    roads[46].occupationAtempt(BLUE);
    displayBoard();

    // player 2
    settlements[34].preOccupationAtempt(RED);
    addPayment(RED, settlements[34].getResources());
    players[RED].incrementVictoryPoints();
    displayBoard();
    roads[50].occupationAtempt(RED);
    displayBoard();

    // player 0
    settlements[8].preOccupationAtempt(YELLOW);
    addPayment(YELLOW, settlements[8].getResources());
    players[YELLOW].incrementVictoryPoints();
    displayBoard();
    roads[13].occupationAtempt(YELLOW);
    displayBoard();

    // player 1
    settlements[41].preOccupationAtempt(BLUE);
    addPayment(BLUE, settlements[41].getResources());
    players[BLUE].incrementVictoryPoints();
    displayBoard();
    roads[52].occupationAtempt(BLUE);
    displayBoard();

    // player 2
    settlements[9].preOccupationAtempt(RED);
    addPayment(RED, settlements[9].getResources());
    players[RED].incrementVictoryPoints();
    displayBoard();
    roads[14].occupationAtempt(RED);
    displayBoard();

    cout << "Resources distribution to players according to the prepped round placements" << endl;

    for (int i = 2; i < 13; i++) {
        distributeResources(i);
    }
    for (int i = 0; i < 3; i++) {
        cout << players[i].getColor() << players[i].getOwner() << "'s display" << "\033[0m" << endl;
        players[i].displayResources();
    }

    cout << "End of prepped round" << endl;

    shuffleCards();

    return 0;
}