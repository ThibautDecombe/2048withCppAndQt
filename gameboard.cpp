#include "gameboard.h"


GameBoard::GameBoard(QObject *parent) : QObject(parent)
{

    progress.open("..//2048//memorycard.txt");
    std::string bestscore_str;
    std::getline(progress, bestscore_str);
    bestscore = std::atoi(bestscore_str.c_str());
    std::string score_str;
    std::getline(progress, score_str);
    score = std::atoi(score_str.c_str());
    std::string nbtiles_str;
    std::getline(progress, nbtiles_str);
    std::string win_str;
    std::getline(progress, win_str);
    winner = std::atoi(win_str.c_str());
    numberOfTiles = std::atoi(nbtiles_str.c_str());
    std::string color_str;
    std::getline(progress, color_str);
    indColorOptions = std::atoi(color_str.c_str());

    std::string game_str;
    std::getline(progress, game_str);
    if (std::atoi(game_str.c_str()) == 0){
        gamemode = false;
    }
    if (std::atoi(game_str.c_str()) == 1){
        gamemode = true;
    }


    int a, b, c, d;
    while (progress >> a >> b >> c >> d)
    {
        moves.push_back({a, b, c, d});
        //qDebug() << a << " " << b << " " << c << " ";
        //qDebug() << moves;
        //qDebug() << moves[0][1];
    }
    //defineSetOfColors(0);

    progress.close();

    verifyLost = false;

    //scoreraz();             // depois mudar para recuperar no .txt - ok!
    //numberOfTiles = 4;
    //indColorOptions = 0;
    createTiles();
    defineSetOfColors(indColorOptions);
    refreshRef();

    //createNewTile();                            // criar funcao nova
    loadGame();

    qDebug() << "Object GameBoard created";
    tileChanged();
}

void GameBoard::loadGame(){
    save_moves = moves;
//    if (moves.size() == 1 && moves[0][0] == 0 && moves[0][1] == 0 && moves[0][2] == 0){
//        moves.erase(moves.begin());
//    }
    if (moves[0][0] == 0 && moves[0][1] == 0 && moves[0][2] == 0 && (moves[0][3] == 0 || moves[0][3] == 4) && moves.size() == 1) {
        createNewTile();
    }
    else{
        for (int i = 0; i < moves.size(); i++){
        //tiles[0][0]->setNumber(2);
        //tiles[0][3]->setNumber(4);
            //qDebug() << moves[i][1];
            tiles[(moves[i][0])][(moves[i][1])] -> setNumber(moves[i][2]);
            if (moves[i][3] == 0){
                loadRight();
            }
            else if (moves[i][3] == 1){
                loadLeft();
            }
            else if (moves[i][3] == 2){
                loadUp();
            }
            else if (moves[i][3] == 3){
                loadDown();
            }
        }
    }

}

void GameBoard::loadRight(){
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = (numberOfTiles - 2); i >= 0; i--){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i+1][j] == 0){
                        changePlaces(i+1, j, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i+1][j] == *matrixNb[i][j]) && tiles[i+1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i+1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i+1, j, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::loadLeft()
{
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = 1; i < numberOfTiles; i++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i-1][j] == 0){
                        changePlaces(i-1, j, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i-1][j] == *matrixNb[i][j]) && tiles[i-1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i-1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i-1, j, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::loadUp()
{
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = 1; j < numberOfTiles; j++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i][j-1] == 0){
                        changePlaces(i, j-1, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i][j-1] == *matrixNb[i][j]) && tiles[i][j-1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j-1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j-1, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::loadDown()
{
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = (numberOfTiles-2); j >= 0; j--){
                if (*matrixNb[i][j] != 0){;
                    if (*matrixNb[i][j+1] == 0){
                        changePlaces(i, j+1, i, j);
                        refreshRef();
                    }
                    if ((*matrixNb[i][j+1] == *matrixNb[i][j]) && tiles[i][j+1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j+1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j+1, i, j);
                        refreshRef();
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
}

void GameBoard::clearProgress(){
    progress.open("..//2048//memorycard.txt", std::ofstream::out | std::ofstream::trunc);
    progress.close();
}

void GameBoard::verifyLostRight()
{
    std::vector<int> listfusion = {};  //pour controler le score
    bool callRandom = false;
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = (numberOfTiles - 2); i >= 0; i--){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i+1][j] == 0){
                        //changePlaces(i+1, j, i, j);
                        //refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i+1][j] == *matrixNb[i][j]) && tiles[i+1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        //tiles[i+1][j]->resetTile();
                        //refreshRef();
                        //tileChanged();
                        //tiles[i][j]->multNumber();
                        //tiles[i][j]->setFusion(true);
                        //changePlaces(i+1, j, i, j);
                        //refreshRef();
                        //listfusion.push_back((*matrixNb[i+1][j])/2);    //ajouter score
                        callRandom =  true;
                    }
                }
            }
        }
    }
    if (callRandom){
        verifyLost = true;
    }
}

void GameBoard::verifyLostLeft()
{
    std::vector<int> listfusion = {};
    bool callRandom = false;
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = 1; i < numberOfTiles; i++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i-1][j] == 0){
                        //changePlaces(i-1, j, i, j);
                        //refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i-1][j] == *matrixNb[i][j]) && tiles[i-1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
//                        tiles[i-1][j]->resetTile();
//                        refreshRef();
//                        tileChanged();
//                        tiles[i][j]->multNumber();
//                        tiles[i][j]->setFusion(true);
//                        changePlaces(i-1, j, i, j);
//                        refreshRef();
//                        listfusion.push_back((*matrixNb[i-1][j])/2);
                        callRandom = true;
                    }
                }
            }
        }
    }
    if (callRandom){
        verifyLost = true;
    }
}

void GameBoard::verifyLostUp()
{
    std::vector<int> listfusion = {};
    bool callRandom = false;
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = 1; j < numberOfTiles; j++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i][j-1] == 0){
//                        changePlaces(i, j-1, i, j);
//                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i][j-1] == *matrixNb[i][j]) && tiles[i][j-1]->getFusion() == false && tiles[i][j]->getFusion() == false){
//                        tiles[i][j-1]->resetTile();
//                        refreshRef();
//                        tileChanged();
//                        tiles[i][j]->multNumber();
//                        tiles[i][j]->setFusion(true);
//                        changePlaces(i, j-1, i, j);
//                        refreshRef();
//                        listfusion.push_back((*matrixNb[i][j-1])/2);
                        callRandom = true;
                    }
                }
            }
        }
    }
    if (callRandom){
        verifyLost = true;
    }
}



void GameBoard::verifyLostDown()
{
    std::vector<int> listfusion = {};
    bool callRandom = false;
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = (numberOfTiles-2); j >= 0; j--){
                if (*matrixNb[i][j] != 0){;
                    if (*matrixNb[i][j+1] == 0){
//                        changePlaces(i, j+1, i, j);
//                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i][j+1] == *matrixNb[i][j]) && tiles[i][j+1]->getFusion() == false && tiles[i][j]->getFusion() == false){
//                        tiles[i][j+1]->resetTile();
//                        refreshRef();
//                        tileChanged();
//                        tiles[i][j]->multNumber();
//                        tiles[i][j]->setFusion(true);
//                        changePlaces(i, j+1, i, j);
//                        refreshRef();
//                        listfusion.push_back((*matrixNb[i][j+1])/2);
                        callRandom = true;
                    }
                }
            }
        }
    }
    if (callRandom){
        verifyLost = true;
    }
}

int GameBoard::multiplier()
{
    if (gamemode == 0){
        return 1;
    }
    else{
        return 0;
    }
}

//int GameBoard::getwinner()
//{
//    return winner;
//}

void GameBoard::setwinner()
{
    winner = 2;
}

void GameBoard::setgamenormal()
{
    gamemode = false;
}

void GameBoard::setgamepractice()
{
    gamemode = true;
}

int GameBoard::readWinner()
{
    return winner;
}

int GameBoard::readLoser()
{
    return loser;
}

void GameBoard::saveGame()
{
    save_moves.back() = {save_moves.back()[0], save_moves.back()[1], save_moves.back()[2], 4};
    clearProgress();
    progress.open("..//2048//memorycard.txt");
    progress << bestscore << "\n";
    progress << score << "\n";
    progress << numberOfTiles << "\n";
    progress << winner << "\n";
    progress << indColorOptions << "\n";
    if (gamemode == false){
        progress << 0 << "\n";
    }
    if (gamemode == true){
        progress << 1 << "\n";
    }
//    //bool fin = true;
//    int clearlist = 0;
    for (int i = 0; i < save_moves.size(); i++){
//        if (fin){
            progress << save_moves[i][0] << " " << save_moves[i][1] << " " << save_moves[i][2] << " " << save_moves[i][3] << "\n";
//        }
//        if (save_moves[i][3] == 4){
//            clearlist = i;
//        }
    }

    progress.close();
}

GameBoard::~GameBoard()
{
    saveGame();
    deleteTiles();
    qDebug() << "Objects destroyed";
}

void GameBoard::moveRight()
{
    verifyRight();
    tileChanged();
}

void GameBoard::moveLeft()
{  
    verifyLeft();
    tileChanged();
}

void GameBoard::moveUp()
{
    verifyUp();
    tileChanged();
}

void GameBoard::moveDown()
{
    verifyDown();
    tileChanged();
}

void GameBoard::verifyRight()
{
    std::vector<int> listfusion = {};  //pour controler le score
    bool callRandom = false;
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = (numberOfTiles - 2); i >= 0; i--){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i+1][j] == 0){
                        changePlaces(i+1, j, i, j);
                        wait(); //
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i+1][j] == *matrixNb[i][j]) && tiles[i+1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i+1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i+1, j, i, j);
                        wait(); //
                        refreshRef();
                        listfusion.push_back((*matrixNb[i+1][j])/2);    //ajouter score
                        callRandom =  true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        save_moves.back() = {save_moves.back()[0], save_moves.back()[1], save_moves.back()[2], 0};
        createNewTile();
        for (int i = 0; i < listfusion.size(); i++){    //
            add_score(listfusion[i]);
        }
        qDebug() << score;
        if (score > bestscore){
            bestscore = score;
        }
        for (int j = 0; j < numberOfTiles; j++){
            for (int k = 0; k < numberOfTiles; k++){
                if ((*matrixNb[j][k]) == 2048 && winner == 0){
                    winner = 1;
                }
            }
        }
        //verifyLost = true;
        tileChanged();
    }
}

void GameBoard::verifyLeft()
{
    std::vector<int> listfusion = {};
    bool callRandom = false;
    for (int j = 0; j < numberOfTiles; j++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int i = 1; i < numberOfTiles; i++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i-1][j] == 0){
                        changePlaces(i-1, j, i, j);
                        wait(); //
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i-1][j] == *matrixNb[i][j]) && tiles[i-1][j]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i-1][j]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i-1, j, i, j);
                        wait(); //
                        refreshRef();
                        listfusion.push_back((*matrixNb[i-1][j])/2);
                        callRandom = true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        save_moves.back() = {save_moves.back()[0], save_moves.back()[1], save_moves.back()[2], 1};
        createNewTile();
        for (int i = 0; i < listfusion.size(); i++){    //
            add_score(listfusion[i]);
        }
        qDebug() << score;
        if (score > bestscore){
            bestscore = score;
        }
        for (int j = 0; j < numberOfTiles; j++){
            for (int k = 0; k < numberOfTiles; k++){
                if ((*matrixNb[j][k]) == 2048 && winner == 0){
                    winner = 1;
                }
            }
        }
        //verifyLost = true;
        tileChanged();
    }
}

void GameBoard::verifyUp()
{
    std::vector<int> listfusion = {};
    bool callRandom = false;
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = 1; j < numberOfTiles; j++){
                if (*matrixNb[i][j] != 0){
                    if (*matrixNb[i][j-1] == 0){
                        changePlaces(i, j-1, i, j);
                        wait(); //
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i][j-1] == *matrixNb[i][j]) && tiles[i][j-1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j-1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j-1, i, j);
                        wait(); //
                        refreshRef();
                        listfusion.push_back((*matrixNb[i][j-1])/2);
                        callRandom = true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        save_moves.back() = {save_moves.back()[0], save_moves.back()[1], save_moves.back()[2], 2};
        createNewTile();
        for (int i = 0; i < listfusion.size(); i++){    //
            add_score(listfusion[i]);
        }
        qDebug() << score;
        if (score > bestscore){
            bestscore = score;
        }
        for (int j = 0; j < numberOfTiles; j++){
            for (int k = 0; k < numberOfTiles; k++){
                if ((*matrixNb[j][k]) == 2048 && winner == 0){
                    winner = 1;
                }
            }
        }
        //verifyLost = true;
        tileChanged();
    }
}



void GameBoard::verifyDown()
{
    std::vector<int> listfusion = {};
    bool callRandom = false;
    for (int i = 0; i < numberOfTiles; i++){
        for (int k = 0; k < numberOfTiles; k++){ // Pour répéter numberOfTiles fois
            for (int j = (numberOfTiles-2); j >= 0; j--){
                if (*matrixNb[i][j] != 0){;
                    if (*matrixNb[i][j+1] == 0){
                        changePlaces(i, j+1, i, j);
                        wait(); //
                        refreshRef();
                        callRandom = true;
                    }
                    if ((*matrixNb[i][j+1] == *matrixNb[i][j]) && tiles[i][j+1]->getFusion() == false && tiles[i][j]->getFusion() == false){
                        tiles[i][j+1]->resetTile();
                        refreshRef();
                        tileChanged();
                        tiles[i][j]->multNumber();
                        tiles[i][j]->setFusion(true);
                        changePlaces(i, j+1, i, j);
                        wait();
                        refreshRef();
                        listfusion.push_back((*matrixNb[i][j+1])/2);
                        callRandom = true;
                    }
                }
            }
        }

    }
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setFusion(false);
        }
    }
    if (callRandom){
        save_moves.back() = {save_moves.back()[0], save_moves.back()[1], save_moves.back()[2], 3};
        createNewTile();
        for (int i = 0; i < listfusion.size(); i++){    //
            add_score(listfusion[i]);
        }
        qDebug() << score;
        if (score > bestscore){
            bestscore = score;
        }
        for (int j = 0; j < numberOfTiles; j++){
            for (int k = 0; k < numberOfTiles; k++){
                if ((*matrixNb[j][k]) == 2048 && winner == 0){
                    winner = 1;
                }
            }
        }
        //verifyLost = true;
        tileChanged();
    }
}

void GameBoard::scoreraz()
{
    score = 0;
}

void GameBoard::add_score(int a)
{
    score += a*multiplier();
}

void GameBoard::createNewTile()
{
    srand(time(NULL)); // initialize the random
    QVector<int> vecRand;
    bool vecRandExists = false;
    for (int i = 0; i < numberOfTiles; i++){
        for (int j = 0; j < numberOfTiles; j++){
            if (*matrixNb[i][j] == 0){
                vecRand << i << j; // Vector with all 0's cases
                vecRandExists = true;
            }
        }
    }
    if (vecRand.length() == 2){ //2
        qDebug() <<  "vecrand = 2";
        int randNumber = rand() % 2 + 1;
        qDebug() <<  "int";
        tiles[vecRand.at(0)][vecRand.at(1)]->setNumber(randNumber*2);
        qDebug() <<  "tiles";
        save_moves.push_back({vecRand.at(0), vecRand.at(1), randNumber*2});
        qDebug() <<  "save";
        refreshRef();
        qDebug() <<  "refresh";
    }
//    if (!vecRandExists){ //2
//        qDebug() <<  "vecrand = 0";
//        verifyLostDown();
//        verifyLostLeft();
//        verifyLostUp();
//        verifyLostRight();
//        if (verifyLost){
//            qDebug() <<  "YOU LOSE";
//            loser = 1;
//            return;
//        }
//        verifyLost = false;
//    }
    if (vecRand.length() > 2){
        int randNumber = rand() % 2 + 1;
        int randIndex = rand() % (vecRand.length()/2 - 1);
        tiles[vecRand.at(randIndex*2)][vecRand.at(randIndex*2+1)]->setNumber(randNumber*2);
        save_moves.push_back({vecRand.at(randIndex*2), vecRand.at(randIndex*2+1), randNumber*2});
        refreshRef();
    }
    verifyLostDown();
    verifyLostLeft();
    verifyLostUp();
    verifyLostRight();
    if (!verifyLost){
        qDebug() <<  "YOU LOSE";
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        loser = 1;
        return;
    }
    verifyLost = false;

//    int nbZeros = 0;
//    for (int j = 0; j < numberOfTiles; j++){
//        for (int k = 0; k < numberOfTiles; k++){
//            if ((*matrixNb[j][k]) == 0){
//                nbZeros += 1;
//            }
//        }
//    }
//    if (nbZeros == 0){

//                qDebug() <<  "vecrand = 0";
//                verifyLostDown();
//                verifyLostLeft();
//                verifyLostUp();
//                verifyLostRight();
//                if (verifyLost){
//                    qDebug() <<  "YOU LOSE";
//                    loser = 1;
//                    return;
//                }
//                verifyLost = false;

//    }
}

void GameBoard::newGame()
{
     scoreraz();
     winner = 0;
     loser = 0;
     verifyLost = false;
     deleteTiles();
     createTiles();
     defineSetOfColors(indColorOptions);
     refreshRef();
     //

     save_moves.clear();
     //progress.clear();
     save_moves = {{0, 0, 0, 0}};
     createNewTile();

     refreshRef();
     tileChanged();
}

void GameBoard::undoGame()
{
    qDebug() << "undo";
    if (save_moves.size() > 2){
        deleteTiles();
        createTiles();
        //defineSetOfColors(indColorOptions);
        refreshRef();
        scoreraz();
        save_moves.pop_back();

        for (int i = 0; i < (save_moves.size() - 1); i++){
            //tiles[0][0]->setNumber(2);
            //tiles[0][3]->setNumber(4);
                //qDebug() << moves[i][1];
            tiles[(save_moves[i][0])][(save_moves[i][1])] -> setNumber(save_moves[i][2]);
            if (save_moves[i][3] == 0){
                loadRight();
            }
            else if (save_moves[i][3] == 1){
                loadLeft();
            }
            else if (save_moves[i][3] == 2){
                loadUp();
            }
            else if (save_moves[i][3] == 3){
                loadDown();
            }
        }
        tiles[(save_moves.back()[0])][(save_moves.back()[1])] -> setNumber(save_moves.back()[2]);
        refreshRef();
        tileChanged();
    }
}

void GameBoard::setNumberOfTiles(int n)
{
    //deleteTiles();
    //scoreraz();
    //numberOfTiles = n;
    //createTiles();
    //defineSetOfColors(indColorOptions);
    //createNewTile();;
    //tileChanged();

    scoreraz();
    deleteTiles();
    numberOfTiles = n;
    createTiles();
    defineSetOfColors(indColorOptions);
    refreshRef();
    //

    save_moves.clear();
    //progress.clear();
    save_moves = {{0, 0, 0, 0}};
    createNewTile();

    refreshRef();
    tileChanged();
}

void GameBoard::defineSetOfColors(int n)
{
    QList<QString> tempColors;
    if (n == 0){
        tempColors << "#007615" << "#044e08" << "#73d216" << "#98fb83" << "#054c0b" << "#054c0b" << "#bbffa9" << "#73d216";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[j + i*numberOfTiles]->defineSetOfTilesColors("Green");
                tilesQml[j + i*numberOfTiles]->setColor();
            }
        }
    }
    if (n == 1){
        tempColors << "#baae9d" << "#ccc2b3" << "#ccc2b3" << "#faf9f0"<< "#ffffff" << "#746c6b" << "#f6f2c9" << "#8f7a66";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[j + i*numberOfTiles]->defineSetOfTilesColors("Classic");
                tilesQml[j + i*numberOfTiles]->setColor();
            }
        }
    }
    if (n == 2){
        tempColors << "#ffcc29" << "#fff773" << "#3E4095" << "#0fa31f"<< "#ffffff" << "#ffffff" << "#3be54f" << "#3E4095";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[j + i*numberOfTiles]->defineSetOfTilesColors("Brazil");
                tilesQml[j + i*numberOfTiles]->setColor();
            }
        }
    }
    if (n == 3){
        tempColors << "#051440" << "#030f2f" << "#ec1920" << "#020c29"<< "#ffffff" << "#ffffff" << "#0f3ba9" << "#ec1920";
        for (int i=0; i < numberOfTiles; i++){
            for (int j=0; j < numberOfTiles; j++){
                tilesQml[j + i*numberOfTiles]->defineSetOfTilesColors("France");
                tilesQml[j + i*numberOfTiles]->setColor();
            }
        }
    }
    colorsList = tempColors;
    indColorOptions = n;
    tileChanged();
}

int GameBoard::readPosX()
{
    if (indX == numberOfTiles*numberOfTiles){
        indX = 0;
    }
    return tilesQml[indX++]->getPosition(0);
}

int GameBoard::readPosY()
{
    if (indY == numberOfTiles*numberOfTiles){
        indY = 0;
    }
    return tilesQml[indY++]->getPosition(1);
}

QString GameBoard::readTileNb()
{
    if (indNb == numberOfTiles*numberOfTiles){
        indNb = 0;
    }
    return tilesQml[indNb++]->getNumber();
}

QString GameBoard::readTileColor()
{
    if (indColor == numberOfTiles*numberOfTiles){
        indColor = 0;
    }
    return tilesQml[indColor++]->getColor();
}

QString GameBoard::readTileTextColor()
{
    if (indTextColor == numberOfTiles*numberOfTiles){
        indTextColor = 0;
    }
    return tilesQml[indTextColor++]->getTextColor();
}

int GameBoard::readNumberOfTiles()
{
    return numberOfTiles;
}

QList<QString> GameBoard::readColorsList()
{
    return colorsList;
}

int GameBoard::readScore()
{
    return score;
}

int GameBoard::readBestScore()
{
    return bestscore;
}

bool GameBoard::readgamemode()
{
    return gamemode;
}

void GameBoard::refreshRef()
{
    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j]->setPosition(i*85 + 10, j*85 + 10);
            matrixNb[i][j] = tiles[i][j]->getRefNumber();
        }
    }
}

void GameBoard::printInfo()
{
    qDebug() << "matrixNb:";
    for (int j=0; j < numberOfTiles; j++){
       qDebug() << *matrixNb[0][j] << "," << *matrixNb[1][j] << "," << *matrixNb[2][j] << "," << *matrixNb[3][j];
    }
}

void GameBoard::changePlaces(int i1, int j1, int i2, int j2)
{
    Tile* temp;
    temp = tiles[i1][j1];
    tiles[i1][j1] = tiles[i2][j2];
    tiles[i2][j2] = temp;
}

void GameBoard::createTiles()
{
    indX = 0, indY = 0, indNb = 0, indColor = 0,
            indTextColor = 0;

    tiles = new Tile**[numberOfTiles];
    for (int i=0; i < numberOfTiles; i++) tiles[i] = new Tile*[numberOfTiles];

    matrixNb = new int**[numberOfTiles];
    for (int i=0; i < numberOfTiles; i++) matrixNb[i] = new int*[numberOfTiles];

    tilesQml = new Tile*[numberOfTiles*numberOfTiles];

    for (int i=0; i < numberOfTiles; i++){
        for (int j=0; j < numberOfTiles; j++){
            tiles[i][j] = new Tile(i*85 + 10, j*85 + 10);
            tilesQml[j + i*numberOfTiles] = tiles[i][j];
        }
    }

    refreshRef();
}

void GameBoard::deleteTiles()
{
    if (matrixNb != NULL){
        for (int i=0; i < numberOfTiles; i++){
            delete[] matrixNb[i];
        }
        delete[] matrixNb;
    }

    if (tilesQml != NULL){
        delete [] tilesQml;
    }

    for (int i=0; i < numberOfTiles ; i++){
        for (int j=0; j < numberOfTiles; j++){
            delete tiles[i][j];
        }
    }

    if (tiles != NULL){
        for (int i=0; i < numberOfTiles; i++){
            delete[] tiles[i];
        }
        delete[] tiles;
    }
}


