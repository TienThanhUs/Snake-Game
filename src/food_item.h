#pragma once
#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

class Food
{
private:
    int foodX, foodY;

public:
    void setFoodX(const int &tung);

    void setFoodY(const int &hoanh);

    int getFoodX();

    int getFoodY();
};

#endif
