#include "Board.hpp"

Board::Board()
{
    std::for_each(begin(board_), end(board_), [](auto& el) {el.fill('.'); });
}

void Board::draw() noexcept
{
    system("cls");
    updateBoard();
    drawFrame();
    for (const auto& outerArray : board_)
    {
        std::cout << "|";
        std::for_each(begin(outerArray), end(outerArray), [](const auto& el) { std::cout << std::setw(2) << el; });
        std::cout << std::setw(2) << "|" << std::endl;
    }
    cleanBoard();
    drawFrame();
    std::cout << "Score: " << ptrToPlayer_->getPlayerSize() - 4 << std::endl;
}
void Board::updateBoard() noexcept
{
    for (const auto& el : ptrToPlayer_->getPlayerRef())
    {
        board_.at(el.coordY_).at(el.coordX_) = '@';
    }
    board_.at(ptrToFood_->getCurrentLocationRef().coordY_).at(ptrToFood_->getCurrentLocationRef().coordX_) = '#';
}
void Board::cleanBoard() noexcept
{
    for (const auto& el : ptrToPlayer_->getPlayerRef())
    {
        board_.at(el.coordY_).at(el.coordX_) = '.';
    }
    board_.at(ptrToFood_->getCurrentLocationRef().coordY_).at(ptrToFood_->getCurrentLocationRef().coordX_) = '.';
}
void Board::drawFrame() const noexcept
{
    std::cout << "+";
    for (int i = 0; i < WIDTH; i++)
    {
        std::cout << std::setw(2) << "=";
    };
    std::cout << " +" << std::endl;
}

void Board::setPtrToFood(std::shared_ptr<Food> ptrToFood) noexcept
{
    ptrToFood_ = std::move(ptrToFood);
}
void Board::setPtrToPlayer(std::shared_ptr<Player> ptrToPlayer) noexcept
{
    ptrToPlayer_ = std::move(ptrToPlayer);
}
